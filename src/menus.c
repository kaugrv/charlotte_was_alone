#include "menus.h"


// Gamestate = 0
void inputMenuPrincipal(SDL_Event e, int* gameState, int* f){
    switch(e.type) {

        /* Clic souris */
        case SDL_MOUSEBUTTONUP:
            printf("clic en (%d, %d)\n", e.button.x, e.button.y);
            break;
        
        /* Touche clavier */
        case SDL_KEYDOWN:

            if (e.key.keysym.sym == 1073741904) { // Gauche
                *f=0;
            } 
            else if (e.key.keysym.sym == 1073741903) { // Droite
                *f=2;
            }
            

            if (e.key.keysym.sym == SDLK_ESCAPE){
                *gameState = 1;
            }

            printf("touche pressee (code = %d)\n", e.key.keysym.sym);
            break;

        case SDL_KEYUP:
            *f=5;
            break;

            
        default:
            break;
    }
}

// Gamestate = 1
void inputPause(SDL_Event e, int* gameState){



    switch(e.type) {

        /* Clic souris */
        case SDL_MOUSEBUTTONUP:
            printf("clic en (%d, %d)\n", e.button.x, e.button.y);
            break;
        
        /* Touche clavier */
        case SDL_KEYDOWN:


            if (e.key.keysym.sym == SDLK_ESCAPE){
                *gameState = 0;
            }


            printf("touche pressee (code = %d)\n", e.key.keysym.sym);
            break;

    


            
        default:
            break;
    }
}
