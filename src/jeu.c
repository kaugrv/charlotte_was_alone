#include "jeu.h"



int main(int argc, char** argv) {

    #include "fenetre/createSDLwindowandcontext.c"
    #include "jeu/init.c"
    int loop = 1;
    int debug = 0;
    int pause = 0;
    int win = 0;

    int currentline = 1;
    int GAMESTATE = 0;

    // Variable d'input
    int keyLeft = 0, keyUp = 0, keyRight = 0, keySwitch = 0;

    onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);

    Niveaux J = createJeu();

    Niveau N1 = createNiveau1();
    Niveau N2 = createNiveau2();
    Niveau N3 = createNiveau3();


    
    addNiveautoJeu(&N3, &J);
    addNiveautoJeu(&N2, &J);
    addNiveautoJeu(&N1, &J);

    Niveau* N = J.liste[J.NiveauActuel];



    // Niveau actuel !

    // Boucle principale 

    while(loop) {

        //printListeAnimation(N->M.listeRectDecorAnim[0]->animations);
        #include "jeu/display.c"
        #include "jeu/inputs.c"
        #include "jeu/update.c"
    }

    #include "fenetre/freeSDLressources.c"
    

}
