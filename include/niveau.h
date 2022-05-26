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
#include "player.h"
#include "camera.h"
#include "animation.h"
#include "collisions.h"


typedef struct Niveau {
    int n;

    Map M;
    QuadTree Q;

    Player player;
    Camera C;
    
} Niveau;

typedef struct Niveaux {
    int nbNiveaux;
    int NiveauActuel;
    Niveau* liste[256];
} Niveaux;

Niveau createNiveau(int n, Map M, QuadTree Q, Player player, Camera C);

Niveau createNiveau1();
Niveau createNiveau2();
Niveau createNiveau3();

Niveaux createJeu();
void addNiveautoJeu(Niveau* N, Niveaux* L);

void restartNiveau(Niveau* N);
int displayNiveau(Niveau* N, int debug);

void switchNiveau(Niveaux* J, int* win);



#endif