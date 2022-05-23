// Boucle traitant les événements

SDL_Event e;

while(SDL_PollEvent(&e) != 0) {

    #include "fenetre/manageSDLwindow.c"
    
    switch(GAMESTATE) {

        case 0: // MENU
            inputMenuPrincipal(e, &GAMESTATE, &currentline, &loop);
            break;

        case 1: // UN NIVEAU
            inputPerso(e, &GAMESTATE, &persoTest, &keyLeft, &keyUp, &keyRight);
            break;

        case 2: // MENU PAUSE
            inputPause(e, &GAMESTATE, &currentline);

    }
}