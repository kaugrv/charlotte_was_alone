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
            displayTeam(N->player);


            if (pause) {
                affichePause(currentline);
            }

            



            break;

        case 2: // Fin
            afficheFin();
            break;
    }

glPopMatrix();


SDL_GL_SwapWindow(window);