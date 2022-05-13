#ifndef PERSO_H
#define PERSO_H

#include <SDL2/SDL.h>
#include "fakesdlimage.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "design.h"

typedef struct Perso {
    ///////////////Caractéristiques
    float width;
    float height;
    //Couleur
    float r;
    float g;
    float b;
    //Position de depart
    float posStartX;
    float posStartY;
    //Position d'arrivee
    float posGoalX;
    float posGoalY;
    //Physique
    float jumpForce;
    float fallForce;
    float vitesseX;
    float vitesseY;
    float accelerationX;
    float accelerationY;
    float dirX;
    float dirY;
    //Position actuelle
    float x;
    float y;

} Perso;


void inputPerso(SDL_Event e, int* gameState, int* f);

Perso createPerso(float width, float height, float r, float g, float b, float posStartX, float posStartY, float posGoalX, float posGoalY, float jumpForce);

void showPerso(Perso* perso);

void updatePosPerso(Perso* perso, Uint32 elapsedTime);

#endif