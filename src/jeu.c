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
#include "menus.h"


int main(int argc, char** argv) {

    #include "fenetre/createSDLwindowandcontext.c"

    /* Boucle principale */

    int loop = 1;

    //Player test
    int f = 5;
    float x;
    float y;
    float wp=30;
    float hp=45;



    int currentline = 1;
    
    int GAMESTATE = 2;

    onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);

    Map M = createMap(1280,1280);

    RectDecor R1 = createRectDecor(640,100,-320,-310,253/255.0,108/255.0,158/255.0);
    RectDecor R2 = createRectDecor(200,250,100,-235,253/255.0,108/255.0,158/255.0);
    RectDecor R3 = createRectDecor(150,200,285,200,253/255.0,108/255.0,158/255.0);
    RectDecor R4 = createRectDecor(50,50,0,240,253/255.0,108/255.0,158/255.0);
    RectDecor R5 = createRectDecor(100,100,-200,200,253/255.0,108/255.0,158/255.0);
    RectDecor R6 = createRectDecor(50,50,40,40,253/255.0,108/255.0,158/255.0);
    RectDecor R7 = createRectDecor(50,50,80,80,253/255.0,108/255.0,158/255.0);
    RectDecor R8 = createRectDecor(50,50,80,140,253/255.0,108/255.0,158/255.0);


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
                afficheMenu(currentline);
                break;
            
            case 1:; // Bouger rectangle
        
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

            case 2: ; // QUADTREE
                
                drawRect(1280,1280,0,0,1,1,1,1); //fond
                glPushMatrix();
                    gestionCamera(x,y,wp,hp);
                    drawMapFromQ(Q);
                    printQuadTree(&Q);

                    drawRect(wp,hp, x, y, 0,0,0,1);

                    RectDecor Rperso = createRectDecor(wp,hp,x,y,1,1,1);

                    QuadTree* Q1 = searchQuadtrees(Rperso, &Q,M).TopLeft;
                    QuadTree* Q2 = searchQuadtrees(Rperso, &Q,M).TopRight;
                    QuadTree* Q3 = searchQuadtrees(Rperso, &Q,M).BottomRight;
                    QuadTree* Q4 = searchQuadtrees(Rperso, &Q,M).BottomLeft;

                    // printQ(Q1);
                    // printQ(Q2);
                    // printQ(Q3);
                    // printQ(Q4);

                    printf("x=%f, y=%f \n", x,y);


                    drawQuadrillage(Q1->xTopLeft + Q1->size/2, Q1->yTopLeft - Q1->size/2, Q1->size, 0.0, 1.0, 0.0);
                    drawQuadrillage(Q2->xTopLeft + Q2->size/2, Q2->yTopLeft - Q2->size/2, Q2->size, 0.0, 1.0, 0.0);
                    drawQuadrillage(Q3->xTopLeft + Q3->size/2, Q3->yTopLeft - Q3->size/2, Q3->size, 0.0, 1.0, 0.0);
                    drawQuadrillage(Q4->xTopLeft + Q4->size/2, Q4->yTopLeft - Q4->size/2, Q4->size, 0.0, 1.0, 0.0);
                glPopMatrix();



                switch(f) {
                    case 0:
                        x-=10;
                        break;
                    case 1:
                        y+=10;
                        break;
                    case 2:
                        x+=10;
                        break;
                    case 3:
                        y-=10;
                        break;
                    f=5; 
                }
        
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
                    inputMenuPrincipal(e, &GAMESTATE, &currentline, &loop);
                    break;

                case 1:
                    input1(e, &GAMESTATE, &f);
                    break;

                case 2:
                    input1(e, &GAMESTATE, &f);
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

