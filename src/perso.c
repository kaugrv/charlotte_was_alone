#include "perso.h"
#include "gestionSDL.h"


// /!\
// Pour l'instant les input sont dans le perso mais
// après y aura un player.c avec les inputs
// \!/

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

void updatePosPerso(Perso* perso, Uint32 elapsedTime, QuadTree Q) {
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


    // A REMPLACER PAR COLLISIONS PLUS TARD
    // IF (collision verticale)
    //     perso->dirX = 0;

    for (int i = 0; i<Q.nbRectDecor; i++ ) {
        if (collides(perso->x+perso->vitesseX*elapsedTime/1000.0, perso->y, perso->width, perso->height, Q.listeRectDecor[i])) {

            if (perso->vitesseX > 0) perso->x = - perso->width/2 + Q.listeRectDecor[i].x - Q.listeRectDecor[i].w/2 - 1;
            if (perso->vitesseX < 0) perso->x =  perso->width/2 + Q.listeRectDecor[i].x + Q.listeRectDecor[i].w/2 + 1 ;

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

    // // A REMPLACER PAR COLLISIONS PLUS TARD
    // if (perso->y < 0 + perso->height/2) {
    //     perso->y = 0 + perso->height/2;
    //     perso->onGround = 1;
    // }

    for (int i = 0; i<Q.nbRectDecor; i++ ) {

        // int c1 = (perso->y+perso->height/2) > (Q.listeRectDecor[i].y -  Q.listeRectDecor[i].h/2);
        // int c2 = (perso->y+perso->height/2) < (Q.listeRectDecor[i].y +  Q.listeRectDecor[i].h/2);
        // // Haut du P entre le haut et le bas

        // int c3 = (perso->y-perso->height/2) > (Q.listeRectDecor[i].y - Q.listeRectDecor[i].h/2);
        // int c4 = (perso->y-perso->height/2) < (Q.listeRectDecor[i].y +  Q.listeRectDecor[i].h/2);
        // // Bas du P entre le haut et le bas

        // int c5 = (perso->y+perso->height/2) > (Q.listeRectDecor[i].y +  Q.listeRectDecor[i].h/2);
        // int c6 = (perso->y-perso->height/2) < (Q.listeRectDecor[i].y -  Q.listeRectDecor[i].h/2);
        // // Haut au dessus du haut, bas en dessous du bas


        // int C = (c1&&c2) || (c3&&c4) || (c5&&c6);

        int C = (perso->y-perso->height/2) < (Q.listeRectDecor[i].y + Q.listeRectDecor[i].h/2 - 10);
        int C2 = (perso->y+perso->height/2) > (Q.listeRectDecor[i].y - Q.listeRectDecor[i].h/2 + 10);


        if (collides(perso->x, perso->y+perso->vitesseY*elapsedTime/1000.0, perso->width, perso->height, Q.listeRectDecor[i])) {

            if (perso->vitesseY > 0 && !C2) perso->y = - perso->height/2 + Q.listeRectDecor[i].y - Q.listeRectDecor[i].h/2 - 1;
            if (perso->vitesseY < 0 && !C) perso->y =  perso->height/2 + Q.listeRectDecor[i].y + Q.listeRectDecor[i].h/2 + 1 ;
            
            perso->vitesseY=0;
            perso->dirY=0;
            //if (perso->y>Q.listeRectDecor[i].y) perso->onGround = 1;
            perso->onGround = !C;
        }

    }


    printf("%d\n", perso->onGround);
    printf("%f\n", perso->vitesseY);
}
