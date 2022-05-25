
// Partie affichage de la boucle principale

/* Recuperation du temps au debut de la boucle */
Uint32 startTime = SDL_GetTicks();

/* Placer ici le code de dessin */

glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

glPushMatrix();


switch (GAMESTATE) {

    case 0:; // MENU
        afficheMenu(currentline);
        break;

    case 1:; // UN NIVEAU
        displayNiveau(N, debug);
        if (pause) {
            affichePause(currentline);
        }
        break;

        }

        glPopMatrix();


    /* Echange du front et du back buffer : mise a jour de la fenetre */
    SDL_GL_SwapWindow(window);