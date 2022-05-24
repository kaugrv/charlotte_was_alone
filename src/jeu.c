#include "jeu.h"



int main(int argc, char** argv) {

    #include "fenetre/createSDLwindowandcontext.c"

    int loop = 1;
    int debug = 0;

    int currentline = 1;
    int GAMESTATE = 1;

    // Variable d'input
    int keyLeft = 0, keyUp = 0, keyRight = 0;

    onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);

    Niveau N1 = createNiveau1();

   
    // Boucle principale 

    while(loop) {

        #include "jeu/display.c"
        #include "jeu/inputs.c"

        /* Calcul du temps ecoule */
        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        
        if(elapsedTime < FRAMERATE_MILLISECONDS) {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
            elapsedTime = SDL_GetTicks() - startTime;
        }

        handleInput(&N1.P, &keyLeft, &keyUp, &keyRight);        
        updatePosCamera(&N1.C, &N1.P, elapsedTime);
        updatePosPerso(&N1.P, elapsedTime);

    }

    #include "fenetre/freeSDLressources.c"
    
}

