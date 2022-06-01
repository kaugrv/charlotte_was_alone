
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

        if (win && N->n==J.nbNiveaux-1) {
            printf("suiv\n");
            GAMESTATE=2;
            win = 0;

            J.NiveauActuel = 0;
            N = J.liste[0];

            restartNiveau(&N);
            break;
        }

        // A-t-on fini le niveau actuel ?
        switchNiveau(&J, &win);
        
        // On gere les inputs du perso actif
        handlePlayerInput(&N->player, &keyLeft, &keyUp, &keyRight, &keySwitch);
        
        // On update la position de la camera sur le perso actif
        updatePosCamera(&N->C, N->player.team[N->player.activePerso], elapsedTime);
        
        // On update la position de tous les persos
        if (!pause){
                for (int i = 0; i < N->player.nbPersos; i++) {
                updatePosPerso(N->player.team[i], elapsedTime, fillQuadTreeFromSearch(N->Q, N->player.team[i]->x, N->player.team[i]->y, N->player.team[i]->width, N->player.team[i]->height, N->M), N->player.team, N->player.nbPersos, i,N->player.activePerso,N->M.listeRectDecorAnim,N->M.nbRectDecorAnim);
                //updatePosPerso(N->player.team[i], elapsedTime, N->Q, N->player.team, N->player.nbPersos, i,N->player.activePerso,N->M.listeRectDecorAnim,N->M.nbRectDecorAnim);                       
            }
        }

+
        
        break;




}

