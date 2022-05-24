// Boucle traitant les événements

SDL_Event e;

while(SDL_PollEvent(&e) != 0) {

    #include "fenetre/manageSDLwindow.c"
    
    switch(GAMESTATE) {

        case 0: // MENU
            inputMenuPrincipal(e, &GAMESTATE, &currentline, &loop);
            break;

        case 1: // UN NIVEAU
            inputPlayer(e, &GAMESTATE, &N1.player, &keyLeft, &keyUp, &keyRight, &keySwitch, &debug);
            break;

        case 2: // MENU PAUSE
            inputPause(e, &GAMESTATE, &currentline);

    }
}