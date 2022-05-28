#include "jeu.h"


int main(int argc, char** argv) {

    #include "fenetre/createSDLwindowandcontext.c"
    #include "jeu/init.c"
    // initialisation des variables globales et création des niveaux

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

    Niveau N0 = createNiveau0();
    Niveau N1 = createNiveau1();


    addNiveautoJeu(&N0, &J);
    addNiveautoJeu(&N1, &J);


    Niveau* N = J.liste[J.NiveauActuel];



    // Boucle principale 
    while(loop) {

        #include "jeu/display.c"
        // Partie affichage de la boucle principale

/* Recuperation du temps au debut de la boucle */
Uint32 startTime = SDL_GetTicks();

glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

glPushMatrix();


    switch (GAMESTATE) {

        case 0:; // MENU
            afficheMenu(currentline);
            break;

        case 1:; // UN NIVEAU

            win = displayNiveau(N, debug);

            if (pause) {
                affichePause(currentline);
            }
            break;
    }

glPopMatrix();


SDL_GL_SwapWindow(window);
        #include "jeu/inputs.c"
        // Boucle traitant les événements

SDL_Event e;

while(SDL_PollEvent(&e) != 0) {

    #include "fenetre/manageSDLwindow.c"
    
    switch(GAMESTATE) {

        case 0: // MENU
            inputMenuPrincipal(e, &GAMESTATE, &currentline, &loop);
            restartNiveau(N);
            break;

        case 1: // UN NIVEAU
            if (!pause) inputPlayer(e, &GAMESTATE, &N->player, &keyLeft, &keyUp, &keyRight, &keySwitch, &debug, &pause);
            if (pause) inputPause(e, &GAMESTATE, &currentline, &pause);

            switch(e.type) {
                case SDL_KEYDOWN : 
                    if (e.key.keysym.sym == SDLK_r)  {
                        restartNiveau(N);
                    }
                    if (e.key.keysym.sym == SDLK_n) {
                        win=1;
                    }
                break;

                default:
                    break;
            }

            break;
    }
}
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

                // A-t-on fini le niveau actuel ?
                switchNiveau(&J, &win);

                // On gere les inputs du perso actif
                handlePlayerInput(&N->player, &keyLeft, &keyUp, &keyRight, &keySwitch);
                
                // On update la position de la camera sur le perso actif
                updatePosCamera(&N->C, N->player.team[N->player.activePerso], elapsedTime);
                
                // On update la position de tous les persos
                if (!pause){
                        for (int i = 0; i < N->player.nbPersos; i++) {
                        updatePosPerso(N->player.team[i], elapsedTime, N->Q, N->player.team, N->player.nbPersos, i,N->player.activePerso,N->M.listeRectDecorAnim,N->M.nbRectDecorAnim);
                    }
                }

                
                break;

        }

      

    }

    #include "fenetre/freeSDLressources.c"
    

}
