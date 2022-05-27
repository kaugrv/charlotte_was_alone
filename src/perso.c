#include "perso.h"
#include "gestionSDL.h"


Perso createPerso(float width, float height, float r, float g, float b, float posStartX, float posStartY, float posGoalX, float posGoalY, float jumpForce) {
    Perso createdPerso;

    //Valeur definie
    createdPerso.width = width;
    createdPerso.height = height;
    createdPerso.r = r;
    createdPerso.g = g;
    createdPerso.b = b;
    createdPerso.posStartX = posStartX;
    createdPerso.posStartY = posStartY;
    createdPerso.posGoalX = posGoalX;
    createdPerso.posGoalY = posGoalY;
    createdPerso.jumpForce = jumpForce;

    //Valeur deduites
    createdPerso.x = posStartX;
    createdPerso.y = posStartY;
    createdPerso.onGround = 0;
    createdPerso.canJumpAgain = 1;
    createdPerso.fallForce = -jumpForce;
    // m/s
    createdPerso.vitesseX = 0;
    createdPerso.vitesseY = 0;
    // m/s /s
    createdPerso.accelerationX = 50;
    createdPerso.accelerationY = 50;
    createdPerso.dirX = 0;
    createdPerso.dirY = 0;

    return createdPerso;
}

void showPerso(Perso* perso) {
    drawRect(perso->width, perso->height, perso->x, perso->y, perso->r, perso->g, perso->b, 1);
}


int collidesP(float x, float y, float width, float height, Perso P) {

    // Bords horiz du perso
    int Pg = x - width/2;
    int Pd = x + width/2;

    // Bords vertic du perso
    int Ph = y + height/2;
    int Pb = y - height/2;

    // Bords horiz de R
    int Rg = P.x - P.width/2;
    int Rd = P.x + P.width/2;

    // Bords vertic de R
    int Rh = P.y + P.height/2;
    int Rb = P.y - P.height/2;


    if (Pg>Rd || Pd<Rg || Ph<Rb || Pb>Rh) {
        return 0;
    }

   else return 1;

}



void updatePosPerso(Perso* perso, Uint32 elapsedTime, QuadTree Q, Perso* team[6], int nbPersos, int k, int activePerso,RectDecor* listeRectDecorAnim[256], int nbRectDecorAnim) {
    int showDebug = 0;
    if (showDebug) {
        printf("x=%f, y=%f \n", perso->x, perso->y);
        printf("Vx=%f, Vy=%f \n", perso->vitesseX, perso->vitesseY);
        printf("Ax=%f, Ay=%f \n", perso->accelerationX, perso->accelerationY);
        printf("dirX=%f, dirY=%f \n", perso->dirX, perso->dirY);
        printf("canJumpAgain=%d\n", perso->canJumpAgain);
    }

    float testFriction = 1.5;
    float gravity = 0.6;
    
    perso->dirY += (perso->fallForce/10) * (elapsedTime/10.0) * gravity;



    //Collisions X avec les RectDecor du QuadTree
        for (int i = 0; i<Q.nbRectDecor; i++ ) {
            if (collides(perso->x+perso->vitesseX*elapsedTime/1000.0, perso->y, perso->width, perso->height, Q.listeRectDecor[i])) {

                if (perso->vitesseX > 0) perso->x = - perso->width/2 + Q.listeRectDecor[i].x - Q.listeRectDecor[i].w/2 - 1;
                if (perso->vitesseX < 0) perso->x =  perso->width/2 + Q.listeRectDecor[i].x + Q.listeRectDecor[i].w/2 + 1 ;

                perso->vitesseX=0;
                perso->dirX=0;
            }
    }

   

    // Collisions X avec les persos de la team
    for (int i = 0; i<nbPersos; i++) {
        if (i!=k && collidesP(perso->x+perso->vitesseX*elapsedTime/1000.0, perso->y, perso->width, perso->height, *team[i])) {

            if (perso->vitesseX > 0) perso->x = - perso->width/2 + team[i]->x - team[i]->width/2 - 2;
            if (perso->vitesseX < 0) perso->x =  perso->width/2 + team[i]->x + team[i]->width/2 + 2;

            perso->vitesseX=0;
            perso->dirX=0;
        }
    }


    // Collisions X avec RectDecorAnim
    for (int i = 0; i<nbRectDecorAnim; i++) {
        if (collides(perso->x+perso->vitesseX*elapsedTime/1000.0, perso->y, perso->width, perso->height, *listeRectDecorAnim[i])) {
            float speedRect = 0;
            if (listeRectDecorAnim[i]->animations->listeAnim[listeRectDecorAnim[i]->animations->animActuelle].instruction == 'X') {
                speedRect = listeRectDecorAnim[i]->animations->listeAnim[listeRectDecorAnim[i]->animations->animActuelle].animSpeed;
            }

            printf("diff speed : %f\n",perso->vitesseX-speedRect);
            if (perso->vitesseX+speedRect <= 0 && perso->x <listeRectDecorAnim[i]->x) perso->x = - perso->width/2 + listeRectDecorAnim[i]->x - listeRectDecorAnim[i]->w/2 - 5;
            if (perso->vitesseX+speedRect >= 0&& perso->x >listeRectDecorAnim[i]->x) perso->x =  perso->width/2 + listeRectDecorAnim[i]->x + listeRectDecorAnim[i]->w/2 + 5;

            perso->vitesseX=0;
            perso->dirX=0;
        }
    }







    // Calcul de la vitesse
    // X
    perso->vitesseX = perso->vitesseX * (1 - testFriction * elapsedTime/100.0) + elapsedTime/100.0 * perso->dirX * perso->accelerationX;

    // Y        
    perso->vitesseY = perso->vitesseY * (1 - gravity * elapsedTime/100.0) + elapsedTime/100.0 * perso->dirY * perso->accelerationY;

    // Cap vitesse
    if (perso->vitesseX > 500) // X+
        perso->vitesseX = 500;
    if (perso->vitesseX < -500) // X-
        perso->vitesseX = -500;
    if (perso->vitesseY < -500) // Y-
        perso->vitesseY = -500;
    if (perso->vitesseY > 1000) // Y+
        perso->vitesseY = 1000;
    
    // Calcul de la position
    perso->x += perso->vitesseX * elapsedTime/1000.0;
    perso->y += perso->vitesseY * elapsedTime/1000.0;


    // Collisions Y avec les RectDecor du QuadTree
    for (int i = 0; i<Q.nbRectDecor; i++ ) {
        int C = (perso->y-perso->height/2) < (Q.listeRectDecor[i].y + Q.listeRectDecor[i].h/2 - 20);
        int C2 = (perso->y+perso->height/2) > (Q.listeRectDecor[i].y - Q.listeRectDecor[i].h/2 + 20);
        if (collides(perso->x, perso->y+perso->vitesseY*elapsedTime/1000.0, perso->width, perso->height, Q.listeRectDecor[i])) {

            if (perso->vitesseY > 0 && !C2) perso->y = - perso->height/2 + Q.listeRectDecor[i].y - Q.listeRectDecor[i].h/2 - 1;
            if (perso->vitesseY < 0 && !C) perso->y =  perso->height/2 + Q.listeRectDecor[i].y + Q.listeRectDecor[i].h/2 + 1 ;
            perso->vitesseY=0;
            perso->dirY=0;
            //if (perso->y>Q.listeRectDecor[i].y) perso->onGround = 1;
            perso->onGround = !C;
        }
    }


    // Collisions Y avec les persos de la team 
    for (int i = 0; i<nbPersos; i++) {
        int C = (perso->y-perso->height/2) < (team[i]->y + team[i]->height/2 - 20);
        int C2 = (perso->y+perso->height/2) > (team[i]->y - team[i]->height/2 + 20);
        if (i!=k && collidesP(perso->x, perso->y+perso->vitesseY*elapsedTime/1000.0, perso->width, perso->height, *team[i])) {

            if (perso->vitesseY > 0 && !C2) {
                perso->y = - perso->height/2 + team[i]->y - team[i]->height/2 - 1;
            }
            if (perso->vitesseY < 0 && !C) {
                perso->y =  perso->height/2 + team[i]->y + team[i]->height/2 + 1 ;
                if (k != activePerso){
                    perso->vitesseX = team[i]->vitesseX;
                    perso->accelerationX = team[i]->accelerationX;
                    perso->dirX = team[i]->dirX;
                }
            }
            perso->vitesseY=0;
            perso->dirY=0;
            perso->onGround = !C;
        }
    }


    // Collisions Y avec RectDecorAnim
    for (int i = 0; i<nbRectDecorAnim; i++) {

        float speedRectX = 0;
        if (listeRectDecorAnim[i]->animations->listeAnim[listeRectDecorAnim[i]->animations->animActuelle].instruction == 'X') {
            speedRectX = listeRectDecorAnim[i]->animations->listeAnim[listeRectDecorAnim[i]->animations->animActuelle].animSpeed;
        }
        int C = (perso->y-perso->height/2) < (listeRectDecorAnim[i]->y + listeRectDecorAnim[i]->h/2 - 20);
        int C2 = (perso->y+perso->height/2) > (listeRectDecorAnim[i]->y - listeRectDecorAnim[i]->h/2 + 20);
        if (collides(perso->x, perso->y+perso->vitesseY*elapsedTime/1000.0, perso->width, perso->height, *listeRectDecorAnim[i])) {

            if (perso->vitesseY > 0 && !C2) {
                perso->y = - perso->height/2 + listeRectDecorAnim[i]->y - listeRectDecorAnim[i]->h/2 - 1;
            }
            if (perso->vitesseY < 0 && !C) {
                perso->y =  perso->height/2 + listeRectDecorAnim[i]->y + listeRectDecorAnim[i]->h/2 + 1 ;
                if (k != activePerso){
                    perso->vitesseX += speedRectX;
                    //perso->accelerationX = listeRectDecorAnim[i]->accelerationX;
                    //perso->dirX = listeRectDecorAnim[i]->dirX;
                }
            }
            perso->vitesseY=0;
            perso->dirY=0;
            perso->onGround = !C;
        }
    }

}
