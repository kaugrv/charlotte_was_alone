#include "animation.h"

void playListeAnimation(float *dx, float *dy, ListeAnimation* LA){
    Animation animActuelle = LA->listeAnim[LA->animActuelle];

    float step = animActuelle.value/animActuelle.animSpeed;
    LA->progress += step;

    playAnimation(dx,dy,animActuelle,LA->progress);
    
    if(LA->progress >= 1.0){
        LA->progress = 0.0;
        LA->animActuelle++;
    }

}

void playAnimation(float *dx, float *dy, Animation A, float progress){
    switch (A.instruction)
    {
    case 'X':
        *dx = A.value/A.animSpeed;
        *dy = 0;
        break;
    
    case 'Y':
        *dx = 0;
        *dy = A.value/A.animSpeed;

    default:
        *dx = 0;
        *dy = 0;
        break;
    }


}

Animation createAnimationVide(){
    Animation res;
    res.instruction = '\0';
    res.value = 0;
    res.animSpeed = 0;
    return res;
}


// cette fonction ne marche pas pour le moment...
ListeAnimation initListe(){
    ListeAnimation res;
    res.animActuelle = 0;
    res.isLoop = 0;
    res.nbAnim = 0;
    res.progress = 0;
    Animation LA[256];
    for (int i = 0; i<256; i++) {
        LA[i] = createAnimationVide();
    }
    //res.listeAnim = LA;
}


Animation createAnimation(char instruction, float value, float animSpeed){
    Animation res;
    //Animation* res = new Animation; (en c++)
    res.instruction = instruction;
    res.value = value;
    res.animSpeed = animSpeed;
    return res;
}

void Loop(int loop, ListeAnimation* LA){
    LA->isLoop = loop;
}

void printAnimation (Animation* anim){
    if (anim != NULL) printf("instruction : %c // value : %f // animSpeed : %f \n", anim->instruction, anim->value, anim->animSpeed);
    else printf("NULL \n");
}   

void printListeAnimation (ListeAnimation* liste){
    if (liste == NULL){
        printf("liste NULL \n");
        return;
    }

    for (int i = 0; i<liste->nbAnim; i++){
        printAnimation(&liste->listeAnim[i]);
    }
}
