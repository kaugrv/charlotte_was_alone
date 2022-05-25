#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "fakesdlimage.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "perso.h"

typedef struct Player {
    Perso* team[6];
    int nbPersos;
    int activePerso;
    int hasSwitched;
} Player;

Player createPlayer(Perso* team[], int nbPersos);
Perso* getPerso(Player* player, int n);
void showPersos(Player* player);

void inputPlayer(SDL_Event e, int* gameState, Player* player, int* leftKey, int* upKey, int* rightKey, int* switchKey, int* debug, int* pause);
void handlePlayerInput(Player* player, int* leftKey, int* upKey, int* rightKey, int* switchKey);

#endif