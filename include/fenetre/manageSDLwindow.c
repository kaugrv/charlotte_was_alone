
/* L'utilisateur ferme la fenetre : */
if(e.type == SDL_QUIT) {
    loop = 0;
    break;
}

if(	e.type == SDL_KEYDOWN 
    && (e.key.keysym.sym == SDLK_q)) {
    loop = 0; 
    break;
}

if (e.type==SDL_WINDOWEVENT) {
    switch (e.window.event) {
        /* Redimensionnement fenetre */
        case SDL_WINDOWEVENT_RESIZED:
            onWindowResized(e.window.data1, e.window.data2);                
            break;

        default:
            break; 
    }
}
