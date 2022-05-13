#include <SDL2/SDL.h>
#include "fakesdlimage.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>

#include "camera.h"



void gestionCamera(float x, float y, float wp, float hp, float speedX,float speedY,Map map) {
    glScalef(2,2,0);
    glTranslatef(-x+speedX,0,0);
    glTranslatef(0,-y+speedY,0);
}

float max(float a, float b){
    if (a>b) return a; 
    return b;
}

float min(float a, float b){
    if (a>b) return b; 
    return a;
}
