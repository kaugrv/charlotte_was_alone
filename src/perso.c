#include "perso.h"
#include "gestionSDL.h"


// /!\
// Pour l'instant les input sont dans le perso mais
// après y aura un player.c avec les inputs
// \!/

void inputPerso(SDL_Event e, int* gameState, Perso* perso, int* left, int* up, int* right, int* debug){
    switch(e.type) {
        case SDL_KEYDOWN:
            if (e.key.keysym.sym == 1073741904) { // Gauche
                *left = 1;
            } 
            else if (e.key.keysym.sym == 1073741906) { // Haut
                *up = 1;
            }
            else if (e.key.keysym.sym == 1073741903) { // Droite
                *right = 1;
            }
            else if (e.key.keysym.sym == SDLK_ESCAPE){
                *gameState = 2;
            }

            if (e.key.keysym.sym == 98) { // B
                *debug=!*debug;
            }     

            break;

        case SDL_KEYUP:
            if (e.key.keysym.sym == 1073741904) { // Gauche
                *left = 0;
            }
            else if (e.key.keysym.sym == 1073741906) { // Haut
                *up = 0;
            }
            else if (e.key.keysym.sym == 1073741903) { // Droite
                *right = 0;
            }
            break;

        default:
            break;
    }
}


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

void handleInput(Perso* perso, int* left, int* up, int* right) {
    //printf("left:%d, right:%d, up:%d\n", *left, *right, *up);

    if (*left && *right) {
        perso->dirX = 0;
    }
    else if (*left) {
        perso->dirX -= 1;
    }
    else if (*right) {
        perso->dirX += 1;
    }
    else
        perso->dirX = 0;

    if (*up) {
        if (perso->onGround)
            perso->dirY += perso->jumpForce;
    }
    else
        perso->dirY = 0;
}

void updatePosPerso(Perso* perso, Uint32 elapsedTime) {
    int showDebug = 0;
    if (showDebug) {
        printf("x=%f, y=%f \n", perso->x, perso->y);
        printf("Vx=%f, Vy=%f \n", perso->vitesseX, perso->vitesseY);
        printf("Ax=%f, Ay=%f \n", perso->accelerationX, perso->accelerationY);
        printf("dirX=%f, dirY=%f \n", perso->dirX, perso->dirY);
    }

    float testFriction = 1.5;
    float gravity = 0.9;

    // Gestion chute
    if (perso->dirY > 0) {
        perso->onGround = 0;
        //perso->dirY += (perso->fallForce/10) * (elapsedTime/10.0);
    }
    
    if (!perso->onGround)
        perso->dirY += (perso->fallForce/10) * (elapsedTime/10.0) * gravity;
    else
        perso->dirY = 0;

    // Calcul de la vitesse
    // X
    perso->vitesseX = perso->vitesseX * (1 - testFriction * elapsedTime/100.0) + elapsedTime/100.0 * perso->dirX * perso->accelerationX;

    // Y        
    perso->vitesseY = perso->vitesseY * (1 - gravity * elapsedTime/100.0) + elapsedTime/100.0 * perso->dirY * perso->accelerationY;

    // Cap vitesse
    // X+
    if (perso->vitesseX > 500)
        perso->vitesseX = 500;
    // X-
    if (perso->vitesseX < -500)
        perso->vitesseX = -500;
    // Y-
    if (perso->vitesseY < -500)
        perso->vitesseY = -500;
    
    // Calcul de la position
    perso->x += perso->vitesseX * elapsedTime/1000.0;
    perso->y += perso->vitesseY * elapsedTime/1000.0;

    // Cap du sol de test
    if (perso->y < 0) {
        perso->y = 0;
        perso->onGround = 1;
    }
}
