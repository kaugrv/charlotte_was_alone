#include "player.h"

/*
    - struct player 
        - Perso* team[6]
        - int nb Perso
        - int activePerso
    - createPlayer(*) 
    - updatePlayer(*) 
    - getPerso(int n) // renvoie le n ième peros
    - focusPerso(Perso* perso)
*/

Player createPlayer(Perso* team[], int nbPersos) {
    Player createdPlayer;

    for (int i = 0; i < nbPersos; i++) {
        createdPlayer.team[i] = team[i];
    }
    createdPlayer.nbPersos = nbPersos;
    createdPlayer.activePerso = 1;
    createdPlayer.hasSwitched = 0;

    return createdPlayer;
}

Perso* getPerso(Player* player, int n) {
    return player->team[n];
}

void showPersos(Player* player) {
    for (int i = 0; i < player->nbPersos; i++)
        showPerso(player->team[i]);
}

#define UP 32
#define LEFT 1073741904
#define RIGHT 1073741903
#define SWITCH 9

void inputPlayer(SDL_Event e, int* gameState, Player* player, int* leftKey, int* upKey, int* rightKey, int* switchKey, int* debug) {
    switch(e.type) {
        case SDL_KEYDOWN: {
            if (e.key.keysym.sym == LEFT) // Gauche
                *leftKey = 1;
            if (e.key.keysym.sym == UP) // Haut
                *upKey = 1;
            if (e.key.keysym.sym == RIGHT) // Droite
                *rightKey = 1;
            if (e.key.keysym.sym == SWITCH) // Switch key (tab)
                *switchKey = 1;
            if (e.key.keysym.sym == SDLK_ESCAPE)
                *gameState = 2;
            if (e.key.keysym.sym == 98) // B
                *debug=!*debug;
            break;
        }

        case SDL_KEYUP: {
            if (e.key.keysym.sym == LEFT) // Gauche
                *leftKey = 0;
            else if (e.key.keysym.sym == UP) // Haut
                *upKey = 0;
            else if (e.key.keysym.sym == RIGHT) // Droite
                *rightKey = 0;
            else if (e.key.keysym.sym == SWITCH) // Switch key (tab)
                *switchKey = 0;
            break;
        }

        default:
            break;
    }
}

void handlePlayerInput(Player* player, int* leftKey, int* upKey, int* rightKey, int* switchKey) {
    Perso* perso = player->team[player->activePerso];

    // LEFT & RIGHT
    if (*leftKey && *rightKey) {
        perso->dirX = 0;
    }
    else if (*leftKey) {
        perso->dirX -= 1;
    }
    else if (*rightKey) {
        perso->dirX += 1;
    }
    else
        perso->dirX = 0;

    // JUMP KEY
    if (*upKey) {
        // If on ground it can jump
        if (perso->onGround && perso->canJumpAgain) {
            perso->dirY += perso->jumpForce;
            perso->onGround = 0;
            if (perso->dirY < 0)
                perso->canJumpAgain = 0;
        }
    }
    else {
        perso->dirY = 0;
        // A REMPLACER PAR COLLISIONS PLUS TARD
        if (perso->y <= 0 + perso->height/2)
            perso->canJumpAgain = 1;
    }

    // TOUCHE DE SWITCH
    if (*switchKey && !player->hasSwitched) {
        player->team[player->activePerso]->dirX = 0;
        player->team[player->activePerso]->dirY = 0;
        player->activePerso = (player->activePerso + 1) %player->nbPersos;
        player->hasSwitched = 1;
    }
    else if (!*switchKey && player->hasSwitched)
        player->hasSwitched = 0;
}