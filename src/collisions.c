#include "collisions.h"



int collides(float x, float y, float width, float height, RectDecor R) {

    // Bords horiz du perso
    int Pg = x - width/2;
    int Pd = x + width/2;

    // Bords vertic du perso
    int Ph = y + height/2;
    int Pb = y - height/2;

    // Bords horiz de R
    int Rg = R.x - R.w/2;
    int Rd = R.x + R.w/2;

    // Bords vertic de R
    int Rh = R.y + R.h/2;
    int Rb = R.y - R.h/2;


    if (Pg>Rd || Pd<Rg || Ph<Rb || Pb>Rh) {
        return 0;
    }

   else return 1;

}





