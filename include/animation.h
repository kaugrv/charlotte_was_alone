#ifndef ANIMATION_H
#define ANIMATION_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


typedef struct Animation{
    char instruction; // R pour rotate ; X pour translate X ; Y pour translate Y
    float value;
    float animSpeed;
} Animation;


typedef struct ListeAnimation{
    Animation listeAnim[256];
    int isLoop; // 0 : ne loop pas ; 1 elle loop
    int nbAnim; // nb d'anim dans la liste
    float progress; // entre 0 et 1, donne la progression dans l'animation actuelle
    int animActuelle;
} ListeAnimation;

Animation createAnimationVide(); // cette fonction marche !!

Animation createAnimation(char instruction, float value, float animSpeed);

void playListeAnimation(float *dx, float *dy, ListeAnimation* LA);
void playAnimation(float *dx, float *dy, Animation A,float progress);

void Loop(int loop, ListeAnimation* LA);

void printAnimation (Animation* anim);

void printListeAnimation (ListeAnimation* liste);
#endif