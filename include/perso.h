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
#include "collisions.h"
#include "quadtree.h"

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
    //Informations
    int onGround;
    int canJumpAgain;
    float innerVitesseX;
    float innerVitesseY;

} Perso;


Perso createPerso(float width, float height, float r, float g, float b, float posStartX, float posStartY, float posGoalX, float posGoalY, float jumpForce);
void showPerso(Perso* perso);

int collidesP(float x, float y, float width, float height, Perso P);


void updatePosPerso(Perso* perso, Uint32 elapsedTime, QuadTree Q, Perso* team[6], int nbPersos, int k, int activePerso,RectDecor* listeRectDecorAnim[256], int nbRectDecorAnim);

#endif