#include "jeu.h"



int main(int argc, char** argv) {

    #include "fenetre/createSDLwindowandcontext.c"
    #include "jeu/init.c"

    // Niveau actuel !
    // Boucle principale 

    while(loop) {
        #include "jeu/display.c"
        #include "jeu/inputs.c"
        #include "jeu/update.c"
    }

    #include "fenetre/freeSDLressources.c"
    

}
