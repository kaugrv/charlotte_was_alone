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



int main(int argc, char** argv) {

    #include "fenetre/createSDLwindowandcontext.c"

    /* Boucle principale */

    int loop = 1;

    //Player test
    int f = 5;
    float x;
    float y;
    
    float speedX = 0;
    float speedY = 0;
    float wp=30;
    float hp=45;



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
        
        // réduction de la speed (test de la cam) // prochainement la speed physique du player
        if (speedX >0) speedX = max (speedX-8,0.0);
        if (speedX <0) speedX = min (speedX+8,0.0);
        if (speedY >0) speedY = max (speedY-8,0.0);
        if (speedY <0) speedY = min (speedY+8,0.0);

        printf("speedX : %f // speedY : %f \n", speedX,speedY);

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
                
                drawRect(3000,3000,0,0,1,1,1,1); //fond
                glPushMatrix();
                    gestionCamera(x,y,wp,hp,speedX,speedY,M);
                    drawMapFromQ(Q);
                    printQuadTree(&Q);

                    RectDecor Rperso = createRectDecor(wp,hp,x,y,1,1,1);

                    drawRect(wp,hp, x, y, 0,0,0,1);
                    debugQuadTrees(Q, Rperso, M);


                glPopMatrix();



                switch(f) {
                    case 0:
                        x-=10;
                        speedX -= 10;
                        break;
                    case 1:
                        y+=10;
                        speedY += 10;
                        break;
                    case 2:
                        x+=10;
                        speedX += 10;
                        break;
                    case 3:
                        y-=10;
                        speedY -= 10;
                        break;
                    f=5; 
                }
        
                break;

            case 3:;
               drawRect(3000,3000,0,0,1,1,1,1); //fond

                glPushMatrix();
                    gestionCamera(x,y,wp,hp,speedX,speedY,M);
                    drawMapFromQ(Q);
                    printQuadTree(&Q);
                    drawRect(wp,hp, x, y, 0,0,0,1);
                    debugQuadTrees(Q, Rperso, M);
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
                    input1(e, &GAMESTATE, &f);
                    break;

                case 2:
                    input1(e, &GAMESTATE, &f);
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
    }

    #include "fenetre/freeSDLressources.c"
    
}

