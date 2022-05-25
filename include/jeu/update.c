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
                updatePosPerso(N->player.team[i], elapsedTime, N->Q, N->player.team, N->player.nbPersos, i,N->player.activePerso,N->M);
            }
        }