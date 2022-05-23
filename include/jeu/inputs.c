
// Boucle traitant les événements

SDL_Event e;

while(SDL_PollEvent(&e)) {

    #include "fenetre/manageSDLwindow.c"
    
    switch(GAMESTATE) {

        case 0: // MENU
            inputMenuPrincipal(e, &GAMESTATE, &currentline, &loop);
            break;

        case 1: // UN NIVEAU
            input1(e, &GAMESTATE, &f, &debug);
            break;

        case 2: // MENU PAUSE
            inputPause(e, &GAMESTATE, &currentline);

    }
}