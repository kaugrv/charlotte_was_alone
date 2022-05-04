#include "gestionSDL.h"


void onWindowResized(unsigned int width, unsigned int height)
{ 
    float aspectRatio = width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if( aspectRatio > 1) 
    {
        gluOrtho2D(
        -GL_VIEW_SIZE / 2. * aspectRatio, GL_VIEW_SIZE / 2. * aspectRatio, 
        -GL_VIEW_SIZE / 2., GL_VIEW_SIZE / 2.);
    }
    else
    {
        gluOrtho2D(
        -GL_VIEW_SIZE / 2., GL_VIEW_SIZE / 2.,
        -GL_VIEW_SIZE / 2. / aspectRatio, GL_VIEW_SIZE / 2. / aspectRatio);
    }
}

GLuint loadingRessources(char* adresse){    


    // chargement des ressources !
    SDL_Surface* imgLoad = IMG_Load(adresse);
    
    // Ici On charge les ressources dans la RAM
    GLuint textureID;

    // chargement texture sur surface et paramètres
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,imgLoad->w,imgLoad->h,0,GL_RGBA, GL_UNSIGNED_BYTE, imgLoad->pixels);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    // libère surface
    SDL_FreeSurface(imgLoad);

    return textureID;

}

