#include "animation.h"
#include <math.h>

 
Animation createAnimation(char instruction, float value, float animSpeed){
    Animation res;
    res.instruction = instruction;
    res.value = value;
    res.animSpeed = animSpeed;
    return res;
}


Animation createAnimationVide(){
    return  createAnimation('\0', 0, 0);
}


ListeAnimation initListe(){
    ListeAnimation res;
    res.isLoop = 0;
    res.nbAnim = 0;
    res.animActuelle = 0;
    res.progressAnimActuelle = 0;

    for(int i = 0;i < 256; i++){
        res.listeAnim[i] = createAnimationVide();
    }

    return res;
}

void addAnimToList(Animation Anim, ListeAnimation* List) {
    List->listeAnim[List->nbAnim] = Anim;
    List->nbAnim++;
}

void listeLoop(int loop, ListeAnimation* LA){
    LA->isLoop = loop;
}

void printAnimation (Animation* anim){
    if (anim != NULL) printf("instruction : %c alue : %f // animSpeed : %f \n", anim->instruction, anim->value, anim->animSpeed);
    else printf("NULL \n");
}   

void printListeAnimation (ListeAnimation* liste){
    if (liste == NULL){
        printf("Liste NULL \n");
        return;
    }
    for (int i=0; i<liste->nbAnim; i++){
        printf("%d-ième animation : ", i);
        printAnimation(&liste->listeAnim[i]);

        printf("Animation Actuelle : %d // progress : %f \n", liste->animActuelle, liste->progressAnimActuelle);
    }
}

void playAnimation(float *dx, float *dy, Animation A){
    switch (A.instruction){
        case 'X':
                *dx = A.animSpeed; // avancée de position
                break;
        
        case 'Y':
                *dy = A.animSpeed;
                break;
            
        default:
            *dx = 0;
            *dy = 0;
            break;
    }
}

void playListeAnimation(float *dx, float *dy, ListeAnimation* LA){
    Animation animActuelle = LA->listeAnim[LA->animActuelle];
    float delta = 0;
    // printListeAnimation(LA);

    if (animActuelle.value !=0) delta = animActuelle.animSpeed/animActuelle.value;
    LA->progressAnimActuelle += fabs(delta);

    //LA->progressAnimActuelle = fabs(LA->progressAnimActuelle);

    playAnimation(dx,dy,animActuelle);
    
    if(LA->progressAnimActuelle >= 1){ // si j'ai fini l'animActuelle
            LA->progressAnimActuelle = 1.0; // passage à la suivante.

        

        if (LA->animActuelle < LA->nbAnim-1) {
            LA->progressAnimActuelle = 0.0; // passage à la suivante.
            LA->animActuelle++;

        }

        else  {
            if (LA->isLoop) {
                LA->progressAnimActuelle = 0.0; // passage à la suivante.
                LA->animActuelle = 0;
            }

            else {
                *dx = 0;
                *dy = 0;
                return;
            }
        }
    }

}

