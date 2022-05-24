#include "jeu.h"



int main(int argc, char** argv) {

    #include "fenetre/createSDLwindowandcontext.c"

    int loop = 1;
    int debug = 0;

    int currentline = 1;
    int GAMESTATE = 1;

    // Variable d'input
    int keyLeft = 0, keyUp = 0, keyRight = 0, keySwitch = 0;

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

        // On gere les inputs du perso actif
        handlePlayerInput(&N1.player, &keyLeft, &keyUp, &keyRight, &keySwitch);
        
        // On update la position de la camera sur le perso actif
        updatePosCamera(&N1.C, N1.player.team[N1.player.activePerso], elapsedTime);
        
        // On update la position de tous les persos
        for (int i = 0; i < N1.player.nbPersos; i++)
            updatePosPerso(N1.player.team[i], elapsedTime, N1.Q);
    }

    #include "fenetre/freeSDLressources.c"
    
}

