#include "jeu.h"
#include "camera.h"


int main(int argc, char** argv) {

    #include "fenetre/createSDLwindowandcontext.c"

    int loop = 1;
    int debug = 0;

    //Player test
    Perso persoTest = createPerso(60,90, 0.,0.,0., 20,20, 100,100, 100);
    // Variable d'input
    int keyLeft = 0, keyUp = 0, keyRight = 0;

    // Position camera
    Camera camTest = createCamera(persoTest.posStartX, persoTest.posStartY, 2, 2);

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

    RectDecorFin R9 = createRectDecor(persoTest.width,persoTest.height,-300,0, 0.8,0,0);

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

   
    // Boucle principale 

    while(loop) {

        #include "jeu/display.c"
        #include "jeu/inputs.c"

        /* Calcul du temps ecoule */
        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        if(elapsedTime < FRAMERATE_MILLISECONDS) {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        }

        handleInput(&persoTest, &keyLeft, &keyUp, &keyRight);        
        updatePosCamera(&camTest, &persoTest, elapsedTime);
        updatePosPerso(&persoTest, elapsedTime);

    }

    #include "fenetre/freeSDLressources.c"
    
}

