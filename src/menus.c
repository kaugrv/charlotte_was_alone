#include "menus.h"
#include "quadtree.h"
#include "gestionSDL.h"


// Gamestate = 0
void inputMenuPrincipal(SDL_Event e, int* gameState, int* currentline, int* loop) {
    
    int lastline = 3;

    switch(e.type) {
        
        /* Touche clavier */
        case SDL_KEYDOWN:

            if (e.key.keysym.sym == 1073741906) { // Haut
                if (*currentline==1) *currentline=lastline;
                else *currentline-=1;
            } 
            
            if (e.key.keysym.sym == 1073741905) { // Bas
                if (*currentline==lastline) *currentline=1; 
                else *currentline +=1;
   
            }

            if (e.key.keysym.sym == 13 || e.key.keysym.sym==1073741912) { // Entree : changement de gamestate
                if (*currentline !=3) {
                    *gameState=*currentline;   
                    *currentline=1;
                } 

                else { // quitter jeu
                    *loop = 0;
                    break;
                }
            }

            printf("touche pressee (code = %d)\n", e.key.keysym.sym);
            break;

        case SDL_KEYUP:
            break;

            
        default:
            break;
    }
}


void afficheMenu(int currentline) {

    glColor3f(1,1,1);

    char * fond;
    fond = "doc/textures/menus/rose.png";
    drawTexturedRect(3000,3000,0,0, fond);


    char * adresse;
    
    if (currentline==1) {
        adresse = "doc/textures/menus/1.png";
    }

    if (currentline==2) {
        adresse = "doc/textures/menus/2.png";
    }

    if (currentline==3) {
        adresse = "doc/textures/menus/3.png";
    }


    drawTexturedRect(WINDOW_WIDTH,WINDOW_HEIGHT,0,0, adresse);

}


void affichePause(int currentline) {
    glColor3f(1,1,1);

    char * fond;
    fond = "doc/textures/menus/roseT.png";
    drawTexturedRect(3000,3000,0,0, fond);

    char * adresse;
    
    if (currentline==1) {
        adresse = "doc/textures/menus/pause1.png";
    }

    if (currentline==2) {
        adresse = "doc/textures/menus/pause2.png";
    }

    drawTexturedRect(1280,1280,0,0, adresse);

}


// Gamestate = 1
void input1(SDL_Event e, int* gameState, int * f){

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

            if (e.key.keysym.sym == 1073741906) { // Haut
                *f=1;
            } 
            
            if (e.key.keysym.sym == 1073741903) { // Droite
                *f=2;
            }

            else if (e.key.keysym.sym == 1073741905) { // Bas
                *f=3;
            }            
            

            if (e.key.keysym.sym == SDLK_ESCAPE){
                *gameState=3;
            }

            break;

        case SDL_KEYUP:
            *f =5;
            break;
            
        default:
            break;
    }
}



void inputPause(SDL_Event e, int* gameState, int* currentline) {
    
    int lastline = 2;

    switch(e.type) {
        
        /* Touche clavier */
        case SDL_KEYDOWN:

            if (e.key.keysym.sym == 1073741906) { // Haut
                if (*currentline==1) *currentline=lastline;
                else *currentline-=1;
            } 
            
            if (e.key.keysym.sym == 1073741905) { // Bas
                if (*currentline==lastline) *currentline=1; 
                else *currentline +=1;
   
            }

            if (e.key.keysym.sym == 13 || e.key.keysym.sym==1073741912) { // Entree : changement de gamestate
                if (*currentline==1) {*gameState=2;}  
                if (*currentline==2) {*gameState=0;}

                *currentline=1;
            }

            printf("touche pressee (code = %d)\n", e.key.keysym.sym);
            break;

        case SDL_KEYUP:
            break;

            
        default:
            break;
    }
}
