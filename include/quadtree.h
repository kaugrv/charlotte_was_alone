#ifndef QUADTREE_H
#define QUADTREE_H

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
#include "map.h"

typedef struct QuadTree {

    struct QuadTree* TopLeft;
    struct QuadTree* TopRight;
    struct QuadTree* BottomLeft;
    struct QuadTree* BottomRight;

    float xTopLeft;
    float yTopLeft;
    // coordonnées du coin topleft de la zone

    float size; // taille en pixels de la zone

    RectDecor listeRectDecor[256];
    int nbRectDecor;

} QuadTree ;

int isLeaf(QuadTree Q);

void drawQuadrillage(float x, float y, float size);

int rectDecorInZone(RectDecor R, float xTopLeft, float yTopLeft, float size);

void createChildren(QuadTree* Q);

void heritedRectDecor(QuadTree* Q, RectDecor listeRectDecorParent[256], int nbRectDecorParent);

QuadTree initRootFromMap(Map M);

void buildQuadTree(QuadTree* Q);

void printQuadTree(QuadTree* Q);

void printQ(QuadTree* Q);

void drawMapFromQ(QuadTree Q);


QuadTree* QuadTreeContainPoint (float x, float y, QuadTree* Q);
#endif