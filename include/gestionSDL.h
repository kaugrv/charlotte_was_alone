#ifndef GESTIONSDL_H
#define GESTIONSDL_H


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


// Valeurs
/* Dimensions initiales et titre de la fenetre */
static const unsigned int WINDOW_WIDTH = 1280;
static const unsigned int WINDOW_HEIGHT = 1280;
static const char WINDOW_TITLE[] = "Charlotte Was Alone";



/* Espace fenetre virtuelle */
static const float GL_VIEW_SIZE = 1280.;

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;


static float aspectRatio = 1.0* WINDOW_WIDTH/WINDOW_HEIGHT;



// Prototypage fonctions

void onWindowResized(unsigned int width, unsigned int height);

GLuint loadingRessources(char* adresse); // Retourne textureID pour charger textures


#endif