#include <SDL2/SDL.h>
#include "fakesdlimage.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>

#include "camera.h"



void gestionCamera(float x, float y) {
    glScalef(2,2,0);
    glTranslatef(-x,0,0);
    glTranslatef(0,-y,0);
}

float max(float a, float b){
    if (a>b) return a; 
    return b;
}

float min(float a, float b){
    if (a>b) return b; 
    return a;
}
