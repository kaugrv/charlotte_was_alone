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
    int animActuelle;
    float progressAnimActuelle; // entre 0 et value de l'animation actuelle
} ListeAnimation;


Animation createAnimation(char instruction, float value, float animSpeed);
Animation createAnimationVide(); 
ListeAnimation initListe();
void addAnimToList(Animation Anim, ListeAnimation* List);



void listeLoop(int loop, ListeAnimation* LA);

void printAnimation (Animation* anim);
void printListeAnimation (ListeAnimation* liste);



void playAnimation(float *dx, float *dy, Animation A);
void playListeAnimation(float *dx, float *dy, ListeAnimation* LA);


#endif