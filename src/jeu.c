#include "jeu.h"



int main(int argc, char** argv) {

    #include "fenetre/createSDLwindowandcontext.c"
    #include "jeu/init.c"
    int loop = 1;
    int debug = 0;
    int pause = 0;
    int win = 0;
    int currentline = 1;
    int GAMESTATE = 0;

    // Variable d'input
    int keyLeft = 0, keyUp = 0, keyRight = 0, keySwitch = 0;

    onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);

    Niveaux J = createJeu();

    Niveau N1 = createNiveau1();
    Niveau N2 = createNiveau2();
    Niveau N3 = createNiveau3();

    addNiveautoJeu(&N3, &J);
    addNiveautoJeu(&N2, &J);
    addNiveautoJeu(&N1, &J);

  
    Niveau* N = J.liste[J.NiveauActuel]; 





    // Boucle principale 

    while(loop) {

        #include "jeu/display.c"
        #include "jeu/inputs.c"
        #include "jeu/update.c"
         /* Calcul du temps ecoule */
        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        
        if(elapsedTime < FRAMERATE_MILLISECONDS) {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
            elapsedTime = SDL_GetTicks() - startTime;
        }

        switch (GAMESTATE) {

            
            case 0:; // MENU PRINCIPAL
                break;

            case 1:; // UN NIVEAU
                N = J.liste[J.NiveauActuel]; 
                 printf("%d\n", J.NiveauActuel);

                // A-t-on fini le niveau actuel ?
                switchNiveau(&J, &win);

                // On gere les inputs du perso actif
                handlePlayerInput(&N->player, &keyLeft, &keyUp, &keyRight, &keySwitch);
                
                // On update la position de la camera sur le perso actif
                updatePosCamera(&N->C, N->player.team[N->player.activePerso], elapsedTime);
                
                // On update la position de tous les persos
                if (!pause){
                        for (int i = 0; i < N->player.nbPersos; i++) {
                        updatePosPerso(N->player.team[i], elapsedTime, N->Q, N->player.team, N->player.nbPersos, i,N->player.activePerso);
                    }
                }

                
                break;

        }

    }

    #include "fenetre/freeSDLressources.c"
    

}
