#include "map.h"


RectDecor createRectDecor(float w, float h, float x, float y, float r, float g, float b) {
    RectDecor R;
    R.x=x;
    R.y=y;
    R.w=w;
    R.h=h;
    R.r=r;
    R.g=g;
    R.b=b;

    R.isAnimated=0;
    
    return R;
} 

void animateRectDecor(RectDecor* R, ListeAnimation* LA) {
    R->isAnimated=1;
    R->animations= LA;
}

void drawRectDecor(RectDecor R) {

    float dx=0;
    float dy=0;

    if (R.isAnimated == 1) {
        playListeAnimation(&dx, &dy, R.animations);
        printf("dx : %f \n", dx);
    }

    drawRect(R.w, R.h, R.x+dx, R.y+dy, R.r, R.g, R.b, 1);

}

void drawRectDecorFin(RectDecorFin R) {
    drawRect(R.w, R.h, R.x, R.y, R.r, R.g, R.b, 0);
}

Map createMap(float w, float h) {
    Map M;
    M.w=w;
    M.h=h;
    M.nbRectDecor=0;
    M.nbRectDecorFin=0;
    return M;
}

void addRectDecorToMap(RectDecor R, Map* M) {
    M->listeRectDecor[M->nbRectDecor] = R;
    M->nbRectDecor++;    
}

void addRectDecorFinToMap(RectDecorFin R, Map* M) {
    M->listeRectDecorFin[M->nbRectDecorFin] = R;
    M->nbRectDecorFin++;    
}


void drawMap(Map M) {
    for (int i=0; i<M.nbRectDecor; i++) {
        drawRectDecor(M.listeRectDecor[i]);
    }
    for (int i=0; i<M.nbRectDecorFin; i++) {
        drawRectDecorFin(M.listeRectDecorFin[i]);
    }
}