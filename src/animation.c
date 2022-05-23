#include "animation.h"

// V 
Animation createAnimation(char instruction, float value, float animSpeed){
    Animation res;
    res.instruction = instruction;
    res.value = value;
    res.animSpeed = animSpeed;
    return res;
}

// V
Animation createAnimationVide(){
    return  createAnimation('\0', 0, 0);
}


// V
ListeAnimation initListe(){
    ListeAnimation res;
    res.isLoop = 0;
    res.nbAnim = 0;
    res.animActuelle = 0;
    res.progressAnimActuelle = 0;

    
    for (int i = 0; i<256; i++) {
        res.listeAnim[i] = createAnimationVide();
    }
    return res;
}

// V
void addAnimToList(Animation Anim, ListeAnimation* List) {
    List->listeAnim[List->nbAnim] = Anim;
    List->nbAnim++;
}

void listeLoop(int loop, ListeAnimation* LA){
    LA->isLoop = loop;
}

// V
void printAnimation (Animation* anim){
    if (anim != NULL) printf("instruction : %c // value : %f // animSpeed : %f \n", anim->instruction, anim->value, anim->animSpeed);
    else printf("NULL \n");
}   

// V
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

// V
void playAnimation(float *dx, float *dy, Animation A){
    switch (A.instruction){
        case 'X':
                *dx = A.value; // avancée de position
                break;
        
        case 'Y':
                *dy = A.value;
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

    if (animActuelle.value !=0) delta = animActuelle.animSpeed/animActuelle.value;

    LA->progressAnimActuelle += delta;

    playAnimation(dx,dy,animActuelle);
    *dx *=LA->progressAnimActuelle;
    *dy *=LA->progressAnimActuelle;

    
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

