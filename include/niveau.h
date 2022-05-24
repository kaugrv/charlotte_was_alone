#ifndef NIVEAU_H
#define NIVEAU_H

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
#include "quadtree.h"
#include "perso.h"
#include "camera.h"
#include "animation.h"
#include "collisions.h"


typedef struct Niveau {
    int n;

    Map M;
    QuadTree Q;

    Perso P;
    Camera C;
    
} Niveau;


Niveau createNiveau(int n, Map M, QuadTree Q, Perso P, Camera C);

Niveau createNiveau1();
Niveau createNiveau2();
Niveau createNiveau3();

void displayNiveau(Niveau* N, int debug);



#endif