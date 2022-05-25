#ifndef MENUS_H
#define MENUS_H

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

void inputMenuPrincipal(SDL_Event e, int* gameState, int* currentline, int* loop);

void afficheMenu(int currentline);

void affichePause(int currentline);

void input1(SDL_Event e, int* gameState, int* f, int* debug);

void inputPause(SDL_Event e, int* gameState, int* currentline, int* pause);






#endif