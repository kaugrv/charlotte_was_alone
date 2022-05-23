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
#include "camera.h"
#include "design.h"
#include "map.h"
#include "quadtree.h"
#include "menus.h"
#include "perso.h"



int main(int argc, char** argv) {

    #include "fenetre/createSDLwindowandcontext.c"

    /* Boucle principale */

    int loop = 1;
    int debug = 0;

    //Player test
    int f = 2;
    Perso persoTest = createPerso(60,90, 0.,0.,0., 20,20, 100,100, 100);

    // Position camera
    float camX = persoTest.posStartX;
    float camY = persoTest.posStartY;

    int currentline = 1;
    
    int GAMESTATE = 0;

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

    RectDecorFin R9 = createRectDecor(persoTest.width,persoTest.height,-300,100, 0.8,0,0);



    addRectDecorToMap(R1, &M);
    addRectDecorToMap(R2, &M);
    addRectDecorToMap(R3, &M);
    addRectDecorToMap(R4, &M);
    addRectDecorToMap(R5, &M);
    addRectDecorToMap(R6, &M);
    addRectDecorToMap(R7, &M);
    addRectDecorToMap(R8, &M);

    addRectDecorFinToMap(R9, &M);



    QuadTree Q = initRootFromMap(M);
    buildQuadTree(&Q);


   

    while(loop) {
        
        // réduction de la speed (test de la cam) // prochainement la speed physique du player
        /*
        if (speedX >0) speedX = max (speedX-8,0.0);
        if (speedX <0) speedX = min (speedX+8,0.0);
        if (speedY >0) speedY = max (speedY-8,0.0);
        if (speedY <0) speedY = min (speedY+8,0.0);

        printf("speedX : %f // speedY : %f \n", speedX,speedY);
        */

        /* Recuperation du temps au debut de la boucle */
        Uint32 startTime = SDL_GetTicks();
    
        /* Placer ici le code de dessin */
        
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glPushMatrix();

      

        switch (GAMESTATE) {

            case 0:
                afficheMenu(currentline);
                break;
            
            case 1: // Bouger rectangle
        
                showPerso(&persoTest);
                switch(f) {
                    case 0:
                        persoTest.x += 10;
                        break;
                    case 2:
                        persoTest.x +=10;
                        break;
                    f=5; 
                }

                break;

            case 2: // QUADTREE
                
                drawRect(3000,3000,0,0,1,1,1,1); //fond
                glPushMatrix();
                    gestionCamera(camX, camY);
                    drawMap(M);
                    printQuadTree(&Q);

                    showPerso(&persoTest);
                    //drawRect(persoTest.width, persoTest.height, persoTest.x, persoTest.y, persoTest.r, persoTest.g, persoTest.b, 1);
                    //drawRect(persoTest.width,persoTest.height, 0,0, 0,0,0, 1);

                    RectDecor Rperso = createRectDecor(persoTest.width, persoTest.height, persoTest.x, persoTest.y, persoTest.r, persoTest.g, persoTest.b);

                    if (distance(R9.x, R9.y, Rperso.x, Rperso.y) <= R9.w/2) {
                        drawRect(persoTest.width, persoTest.height, persoTest.x, persoTest.y, persoTest.r, persoTest.g, persoTest.b,1);
                    }
                    else {
                        drawRect(persoTest.width, persoTest.height, persoTest.x, persoTest.y, persoTest.r, persoTest.g, persoTest.b,1);
                    }
                    if (debug) {
                        printQuadTree(&Q);
                        debugQuadTrees(Q, Rperso, M);

                    }


                glPopMatrix();

                /*
                switch(f) {
                    case 0:
                        persoTest.dirX -= 1;
                        break;
                    case 1:
                        if (persoTest.onGround)
                            persoTest.dirY += persoTest.jumpForce;
                        break;
                    case 2:
                        persoTest.dirX += 1;
                        break;
                    case 5:
                        persoTest.dirX = 0;
                        persoTest.dirY = 0;
                    f=5;
                }
        
                break;
                */

            case 3:
               drawRect(3000,3000,0,0,1,1,1,1); //fond

                glPushMatrix();
                    //gestionCamera(persoTest.x,persoTest.y,persoTest.width,persoTest.height,speedX,speedY,M);
                    drawMapFromQ(Q);
                    
                    //drawRect(persoTest.width,persoTest.height, persoTest.x, persoTest.y, 0,0,0,1);
                    showPerso(&persoTest);
                    if (debug) {
                        printQuadTree(&Q);
                        debugQuadTrees(Q, Rperso, M);
                    }
                glPopMatrix();

                affichePause(currentline);
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
                    input1(e, &GAMESTATE, &f, &debug);
                    break;
                case 2:
                    inputPerso(e, &GAMESTATE, &persoTest);
                    break;
                case 3:
                    inputPause(e, &GAMESTATE, &currentline);
            }
        }

        /* Calcul du temps ecoule */
        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        if(elapsedTime < FRAMERATE_MILLISECONDS) {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        }

        updatePosPerso(&persoTest, elapsedTime);

    }

    #include "fenetre/freeSDLressources.c"
    
}

