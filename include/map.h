#ifndef MAP_H
#define MAP_H

// Inclusion librairies
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

typedef struct RectDecor {
    float x;
    float y;
    float w;
    float h;
    float r;
    float g;
    float b;
} RectDecor;

RectDecor createRectDecor(float w, float h, float x, float y, float r, float g, float b);
void drawRectDecor(RectDecor R);


typedef struct Map {
    float w;
    float h;
    RectDecor listeRectDecor[256];
    int nbRectDecor;
} Map ;

Map createMap(float w, float h);
void addRectDecorToMap(RectDecor R, Map* M);

void drawMap(Map M);





#endif