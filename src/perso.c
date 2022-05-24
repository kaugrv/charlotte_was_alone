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

void updatePosPerso(Perso* perso, Uint32 elapsedTime) {
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
    
    // Falling force if in air
    if (!perso->onGround) {
        perso->dirY += (perso->fallForce/10) * (elapsedTime/10.0) * gravity;
    }
    // Negates force if on ground
    else {
        perso->dirY = 0;
    }

    // A REMPLACER PAR COLLISIONS PLUS TARD
    // IF (collision verticale)
    //     perso->dirX = 0;


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

    // A REMPLACER PAR COLLISIONS PLUS TARD
    if (perso->y < 0 + perso->height/2) {
        perso->y = 0 + perso->height/2;
        perso->onGround = 1;
    }
}
