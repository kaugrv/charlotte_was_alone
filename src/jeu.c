#include "jeu.h"
#include "camera.h"


int main(int argc, char** argv) {

    #include "fenetre/createSDLwindowandcontext.c"

    int loop = 1;
    int debug = 0;

    //Player test
    Perso persoTest = createPerso(60,90, 0.,1.,0., 20,100, 100,100, 200);
    Perso Wooly = createPerso(90,60, 1.,0.,1., 300,100, 500,100, 100);
    Perso Charlie = createPerso(50,120, 0.,1.,1., 200,100, 600,100, 500);
    Perso Arthur = createPerso(200,200, 0.,0.,1., -200,500, 900,100, 30);

    Perso* team[6];
    team[0] = &persoTest;
    team[1] = &Wooly;
    team[2] = &Charlie;
    team[3] = &Arthur;
    
    Player player = createPlayer(team, 4);
    // Variable d'input
    int keyLeft = 0, keyUp = 0, keyRight = 0, keySwitch = 0;

    // Position camera
    Camera camTest = createCamera(player.team[player.activePerso]->posStartX, player.team[player.activePerso]->posStartY, 1.5, 1.5);

    int currentline = 1;
    
    int GAMESTATE = 1;

    onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);

    


    ///////////////
    ///////////////
    /////////////// TEST DES ANIMATIONS INIT
    ///////////////
    ///////////////
    
    Animation testAnimVide = createAnimationVide();
    Animation X20_2 = createAnimation('Y',300,1);

    float dx=0;
    float dy=0;
    printf ("avant anim 1 : dx : %f // dy : %f \n", dx, dy);

    ListeAnimation Listetest = initListe();
    addAnimToList(X20_2, &Listetest);
    listeLoop(1, &Listetest);





    Map M = createMap(1280,1280);

    RectDecor R1 = createRectDecor(640,100,-320,-310,253/255.0,108/255.0,158/255.0);
    RectDecor R2 = createRectDecor(200,250,100,-235,253/255.0,108/255.0,158/255.0);
    RectDecor R3 = createRectDecor(150,200,285,200,253/255.0,108/255.0,158/255.0);
    RectDecor R4 = createRectDecor(50,50,0,240,253/255.0,108/255.0,158/255.0);
    RectDecor R5 = createRectDecor(100,100,-200,200,253/255.0,108/255.0,158/255.0);
    
    RectDecor R6 = createRectDecor(50,50,40,40,108/255.0,108/255.0,108/255.0);
    animateRectDecor(&R6, &Listetest);
    
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

        playListeAnimation(&dx, &dy, &Listetest);
        printListeAnimation(&Listetest);

        //printf("Loop = %d \n", Listetest.isLoop);
        //printf ("dx : %f // dy : %f \n", dx, dy);

        #include "jeu/display.c"
        #include "jeu/inputs.c"

        /* Calcul du temps ecoule */
        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        if(elapsedTime < FRAMERATE_MILLISECONDS) {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        }


        // On gere les inputs du perso actif
        handlePlayerInput(&player, &keyLeft, &keyUp, &keyRight, &keySwitch);
        
        // On update la position de la camera sur le perso actif
        updatePosCamera(&camTest, player.team[player.activePerso], elapsedTime);
        
        // On update la position de tous les persos
        for (int i = 0; i < player.nbPersos; i++)
            updatePosPerso(player.team[i], elapsedTime);
    }

    #include "fenetre/freeSDLressources.c"
    
}

