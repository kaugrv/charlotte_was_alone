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

#include "gestionSDL.h"
#include "design.h"



int main(int argc, char** argv) {

    #include "fenetre/createSDLwindowandcontext.c"

    /* Boucle principale */
    int loop = 1;
    int f = 5;
    float x;
    float y;
    int GAMESTATE = 0;
    char* adresse;
    
    onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);

    while(loop) {

        printf(" le gamestate actuel : %d \n", GAMESTATE);

        /* Recuperation du temps au debut de la boucle */
        Uint32 startTime = SDL_GetTicks();
    
        /* Placer ici le code de dessin */
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        switch (GAMESTATE) {
            case 0:;
                adresse = "doc/textures/menu.png";
                drawTexturedRect(90,60,0,10, adresse);
                drawRect(6,9,x,y, 1.0,1.0,1.0);
                switch(f) {
                    case 0:
                        x--;
                        break;
                        
                    case 2:
                        x++;
                        break;

                    f=5; 
                }
                break;

            case 1: ;
                drawRect(6,9,x,y, 0.5,0.5,0.5);
                adresse = "doc/textures/pause.png";
                drawTexturedRect(90,60,0,10, adresse);
                break;
        }

        /* Echange du front et du back buffer : mise a jour de la fenetre */
        SDL_GL_SwapWindow(window);

        /* Boucle traitant les evenements */
    
        SDL_Event e;

        while(SDL_PollEvent(&e)) {

            #include "fenetre/manageSDLwindow.c"
            
            switch(GAMESTATE) {
                case 0:
                    inputMenuPrincipal(e, &GAMESTATE, &f);
                    break;

                case 1:
                    inputPause(e, &GAMESTATE);
                    break;
            }

        }

        /* Calcul du temps ecoule */
        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        if(elapsedTime < FRAMERATE_MILLISECONDS) {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        }
    }

    #include "fenetre/freeSDLressources.c"
    
}