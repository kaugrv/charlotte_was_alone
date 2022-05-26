#ifndef DESIGN_H
#define DESIGN_H

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


float lerp(float a , float b, float coeff);

float distance(float x1, float y1, float x2, float y2);

void drawTexturedRect(float w, float h, float x, float y, char* adresse);

void drawSquare(int full);

void drawRect(float w, float h, float x, float y, float r, float g, float b, int full);


void affichenumNiveau(int NiveauActuel, float r, float g, float b);

void selectActivePlayer(float x, float y, float h, float r, float g, float b);



#endif