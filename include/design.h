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

void drawTexturedRect(float w, float h, float x, float y, char* adresse);

void drawSquare(int full);

void drawRect(float w, float h, float x, float y, float r, float g, float b, int full);


#endif