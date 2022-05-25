#include "jeu.h"



int main(int argc, char** argv) {

    #include "fenetre/createSDLwindowandcontext.c"

    int loop = 1;
    int debug = 0;
    int pause = 0;

    int currentline = 1;
    int GAMESTATE = 1;

    // Variable d'input
    int keyLeft = 0, keyUp = 0, keyRight = 0, keySwitch = 0;

    onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);


    Niveau N1 = createNiveau1();

    Niveau* N = &N1; 
    // Niveau actuel !

   
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
        handlePlayerInput(&N->player, &keyLeft, &keyUp, &keyRight, &keySwitch);
        
        // On update la position de la camera sur le perso actif
        updatePosCamera(&N->C, N->player.team[N->player.activePerso], elapsedTime);
        
        // On update la position de tous les persos si en jeu
        if (!pause){
                for (int i = 0; i < N->player.nbPersos; i++) {
                updatePosPerso(N->player.team[i], elapsedTime, N->Q);
            }
        }
    }

    #include "fenetre/freeSDLressources.c"
    

}
