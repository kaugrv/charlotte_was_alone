#include "collisions.h"


// To be continued
int isNearX(Perso P, RectDecor R) {
    float dx = P.vitesseX/1000.0;
    
    if ((R.x - R.w/2)-(P.x + P.width/2) <= dx && dx >=0 && P.x <= R.x) return 1; // gauche

    if ((P.x + P.width/2) - (R.x + R.w/2) >= -dx && dx <=0 ) return -1; // gauche


    else return 0;
}

