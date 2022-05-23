#ifndef CAMERA_H
#define CAMERA_H
#include "perso.h"

typedef struct Camera {
    //Position
    float x;
    float y;
    //Scale
    float scaleX;
    float scaleY;
} Camera;

Camera createCamera(float x, float y, float scaleX, float scaleY);
void showCamera(Camera* cam);
void updatePosCamera(Camera* cam, Perso* perso, Uint32 elapsedTime);
float max(float a, float b);
float min(float a, float b);




#endif