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
#include "map.h"
#include "quadtree.h"


int main(int argc, char** argv) {

    #include "fenetre/createSDLwindowandcontext.c"

    /* Boucle principale */
    int loop = 1;
    int f = 5;
    float x;
    float y;
    
    int GAMESTATE = 1;
    char* adresse;
    
    onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);

    Map M = createMap(1280,1280);

    RectDecor R1 = createRectDecor(640,100,-320,-310,1,1,1);
    RectDecor R2 = createRectDecor(200,250,100,-235,1,1,1);
    RectDecor R3 = createRectDecor(150,200,285,200,1,1,1);
    RectDecor R4 = createRectDecor(50,50,0,240,1,1,1);
    RectDecor R5 = createRectDecor(100,100,-200,200,1,1,1);

    RectDecor R6 = createRectDecor(50,50,40,40,1,1,1);
    RectDecor R7 = createRectDecor(50,50,80,80,1,1,1);
    RectDecor R8 = createRectDecor(50,50,80,140,1,1,1);


    // RectDecor R1 = createRectDecor(50,50,0,0,1,1,1);
    // RectDecor R2 = createRectDecor(50,50,-320,-310,1,1,1);
    // RectDecor R3 = createRectDecor(50,50,320,-310,1,1,1);
    // RectDecor R4 = createRectDecor(50,50,320,310,1,1,1);
    // RectDecor R5 = createRectDecor(50,50,-320,310,1,1,1);


    addRectDecorToMap(R1, &M);
    addRectDecorToMap(R2, &M);
    addRectDecorToMap(R3, &M);
    addRectDecorToMap(R4, &M);
    addRectDecorToMap(R5, &M);

    addRectDecorToMap(R6, &M);
    addRectDecorToMap(R7, &M);
    addRectDecorToMap(R8, &M);

    QuadTree Q = initRootFromMap(M);

    buildQuadTree(&Q);
    //printQ(&Q);
   

    // for (int i =0; i<=7; i++){
    //     printf( "le rectangle R%d est dans la zone TR ? %d \n", i+1, rectDecorInZone(Q.listeRectDecor[i],Q.TopRight->xTopLeft,Q.TopRight->yTopLeft,Q.TopRight->size));
    // }

    while(loop) {


        /* Recuperation du temps au debut de la boucle */
        Uint32 startTime = SDL_GetTicks();
    
        /* Placer ici le code de dessin */
        
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glPushMatrix();

        switch (GAMESTATE) {
            case 0:;
                adresse = "doc/textures/menu.png";

                drawTexturedRect(1280,720,0,10, adresse);
                drawRect(60,90, x, y, 1.0,1.0,1.0,1);
                switch(f) {
                    case 0:
                        x-=10;
                        break;
                        
                    case 2:
                        x+=10;
                        break;

                    f=5; 
                }
                break;

            case 1: ;
                drawMapFromQ(Q);
                printQuadTree(&Q);
        
                break;
        }
        glPopMatrix();

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

