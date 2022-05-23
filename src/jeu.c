#include "jeu.h"


int main(int argc, char** argv) {

    #include "fenetre/createSDLwindowandcontext.c"

    int loop = 1;
    int debug = 0;

    // Player test
    int f = 5;
    Perso persoTest = createPerso(60,90, 0.,0.,0., 20,20, 100,100, 10);
    

    // Speed camera
    float speedX = 0;
    float speedY = 0;

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


    ///////////////
    ///////////////
    /////////////// TEST DES ANIMATIONS INIT
    ///////////////
    ///////////////
    
    Animation testAnimVide = createAnimationVide();
    Animation X20_2 = createAnimation('X',20,2);

    float dx=0;
    float dy=0;
    printf ("avant anim 1 : dx : %f // dy : %f \n", dx, dy);

    ListeAnimation Listetest = initListe();
    addAnimToList(X20_2, &Listetest);
    addAnimToList(X20_2, &Listetest);
    addAnimToList(X20_2, &Listetest);


    listeLoop(1, &Listetest);





   
    // Boucle principale 

    while(loop) {

        playListeAnimation(&dx, &dy, &Listetest);
        printListeAnimation(&Listetest);
        printf("Loop = %d \n", Listetest.isLoop);


        printf ("dx : %f // dy : %f \n", dx, dy);

        #include "jeu/display.c"
        #include "jeu/inputs.c"

        /* Calcul du temps ecoule */
        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        if(elapsedTime < FRAMERATE_MILLISECONDS) {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        }

        updatePosPerso(&persoTest, elapsedTime);

    }

    #include "fenetre/freeSDLressources.c"
    
}

