#include <SDL2/SDL.h>
#include "fakesdlimage.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>

#include "camera.h"

Camera createCamera(float x, float y, float scaleX, float scaleY) {
    Camera createdCam;

    createdCam.x = x;
    createdCam.y = y;
    createdCam.scaleX = scaleX;
    createdCam.scaleY = scaleY;

    return createdCam;
}

void showCamera(Camera* cam) {
    glScalef(cam->scaleX, cam->scaleY, 0);
    glTranslatef(-cam->x, 0, 0);
    glTranslatef(0, -cam->y, 0);
}

void updatePosCamera(Camera* cam, Perso* perso, Uint32 elapsedTime) {
    // La gestion de la camera pour l'axe x utilise une cible

    //float cibleX = perso->x + (perso->vitesseX*1.2) * elapsedTime/100.; // TestCible en amont du joueur
    float cibleX = perso->x; //Cible sur le joueur

    if (cam->x != cibleX) {
        float delta = cam->x - cibleX;
        cam->x += (-delta * elapsedTime/100.);
    }

    // La gestion de la camera pour l'axe y est basique
    if (cam->y != perso->y) {
        float delta = cam->y - perso->y;
        cam->y += -delta * elapsedTime/1000.;
    }
}

float max(float a, float b){
    if (a>b) return a; 
    return b;
}

float min(float a, float b){
    if (a>b) return b; 
    return a;
}
