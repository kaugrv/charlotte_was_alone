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


/* Dimensions initiales et titre de la fenetre */
static const unsigned int WINDOW_WIDTH = 1280;
static const unsigned int WINDOW_HEIGHT = 720;
static const char WINDOW_TITLE[] = "JEU";

/* Espace fenetre virtuelle */
static const float GL_VIEW_SIZE = 100.;

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;


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



// Retourne textureID pour charger textures
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


// draw le chiffre n : A GARDER POUR TEXTURES
void drawChiffre(int n) {

    char adresse[70];
    sprintf(adresse, "doc/numbers/%d.png", n);
    GLuint textID = loadingRessources(&adresse);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindTexture(GL_TEXTURE_2D, textID);


    // dessin du chiffre
    glPushMatrix();
        glTranslatef(-0.5,0,0);
        glScalef(0.2,0.5,0);
        glBegin(GL_QUADS);

            glTexCoord2f(0,0);
            glVertex2f(-0.5,0.5);

            glTexCoord2f(1,0);
            glVertex2f(0.5,0.5);

            glTexCoord2f(1,1);
            glVertex2f(0.5,-0.5);

            glTexCoord2f(0,1);
            glVertex2f(-0.5,-0.5);

        glEnd();
    glPopMatrix();

        
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    glDeleteTextures(1, &textID);
}


void drawSquare(int full) {
    int g;
    if (full == 0) { 
        g = GL_LINE_LOOP ;
    }
    if (full == 1) {
        g = GL_POLYGON ;
    }

        glBegin(g);
            glColor3f(1, 1, 1); 
            glVertex2f(0.5,0.5);
            glVertex2f(0.5,-0.5);
            glVertex2f(-0.5,-0.5);
            glVertex2f(-0.5,0.5);
          
        glEnd();

}


void drawRect(float w, float h, float x, float y) {
    glPushMatrix();
        glTranslatef(x,y,0);
        glScalef(w,h,1);
        drawSquare(1);
    glPopMatrix();

}

int main(int argc, char** argv) 
{
    /* Initialisation de la SDL */
    if(SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        const char* error = SDL_GetError();
        fprintf(
            stderr, 
            "Erreur lors de l'intialisation de la SDL : %s\n", error);

        SDL_Quit();
        return EXIT_FAILURE;
    }
	
    /* Ouverture d'une fenetre et creation d'un contexte OpenGL */
    SDL_Window* window;
    {
        window = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

        if(NULL == window) 
        {
            const char* error = SDL_GetError();
            fprintf(
                stderr,
                "Erreur lors de la creation de la fenetre : %s\n", error);

            SDL_Quit();
            return EXIT_FAILURE;
        }
    }
    
    SDL_GLContext context;
    {
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

            SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        context = SDL_GL_CreateContext(window);
    
        if(NULL == context) 
        {
            const char* error = SDL_GetError();
            fprintf(
                stderr,
                "Erreur lors de la creation du contexte OpenGL : %s\n", error);

            SDL_DestroyWindow(window);
            SDL_Quit();
            return EXIT_FAILURE;
        }
    }
  


    /* Boucle principale */
    int loop = 1;
    int f;
    float x;
    float y;

    time_t rawtime;
    struct tm* timeinfo;

    onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);


    while(loop) 
    {

        /* Recuperation du temps au debut de la boucle */
        Uint32 startTime = SDL_GetTicks();
        
        /* Placer ici le code de dessin */
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();



        // DESSIN
       ///////////////////////////////////
       ///////////////////////////////////
       ///////////////////////////////////
       ///////////////////////////////////
       ///////////////////////////////////
       ///////////////////////////////////



        drawRect(6,9,x,y);

        switch(f) {
            case 0:
                x--;
                break;
                
            case 2:
                x++;
                break;

        f=5;
           
        }

        // time(&rawtime);
        // timeinfo = localtime(&rawtime);






        
        /* Echange du front et du back buffer : mise a jour de la fenetre */
        SDL_GL_SwapWindow(window);
        
        /* Boucle traitant les evenements */
        SDL_Event e;
       
        while(SDL_PollEvent(&e)) 
        {
            /* L'utilisateur ferme la fenetre : */
			if(e.type == SDL_QUIT) 
			{
				loop = 0;
				break;
			}
		
			if(	e.type == SDL_KEYDOWN 
				&& (e.key.keysym.sym == SDLK_q || e.key.keysym.sym == SDLK_ESCAPE))
			{
				loop = 0; 
				break;
			}
            
            switch(e.type) 
            {
                case SDL_WINDOWEVENT:
                    switch (e.window.event) 
                    {
                        /* Redimensionnement fenetre */
                        case SDL_WINDOWEVENT_RESIZED:
                            onWindowResized(e.window.data1, e.window.data2);                
                            break;

                        default:
                            break; 
                    }
                    break;

                /* Clic souris */
                case SDL_MOUSEBUTTONUP:
                    printf("clic en (%d, %d)\n", e.button.x, e.button.y);
                    break;
                
                /* Touche clavier */
                case SDL_KEYDOWN:

                    if (e.key.keysym.sym == 1073741904) { // Gauche
                        f=0;
                    } 
                    else if (e.key.keysym.sym == 1073741903) { // Droite
                        f=2;
                    }

                    else f=5;

                    printf("%d", f);
                    printf("touche pressee (code = %d)\n", e.key.keysym.sym);
                    break;

                case SDL_KEYUP:
                    f=5;
                    
                default:
                    break;
            }
        }

        /* Calcul du temps ecoule */
        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        /* Si trop peu de temps s'est ecoule, on met en pause le programme */
        if(elapsedTime < FRAMERATE_MILLISECONDS) 
        {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        }
    }

    /* Liberation des ressources associees a la SDL */
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}