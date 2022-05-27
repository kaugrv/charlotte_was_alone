#include "jeu.h"


int main(int argc, char** argv) {

    #include "fenetre/createSDLwindowandcontext.c"
    #include "jeu/init.c"
    // initialisation des variables globales et création des niveaux

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

    Niveau N0 = createNiveau0();
    //printListeAnimation(N0.M.listeRectDecorAnim[0]->animations);

    printf("%p\n", N0.M.listeRectDecorAnim[0]->animations);

    Niveau N1 = createNiveau1();
    // //printListeAnimation(N0.M.listeRectDecorAnim[0]->animations);
    printf("%p\n", N0.M.listeRectDecorAnim[0]->animations);
    printf("%p\n", N1.M.listeRectDecorAnim[0]->animations);


    addNiveautoJeu(&N0, &J);
    addNiveautoJeu(&N1, &J);

    Niveau* N = J.liste[J.NiveauActuel];



    // Boucle principale 
    while(loop) {

        #include "jeu/display.c"
        #include "jeu/inputs.c"
        #include "jeu/update.c"
      

    }

    #include "fenetre/freeSDLressources.c"
    

}
