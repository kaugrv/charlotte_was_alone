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
    return R;
}

void drawRectDecor(RectDecor R) {
    drawRect(R.w, R.h, R.x, R.y, R.r, R.g, R.b, 1);
}

Map createMap(float w, float h) {
    Map M;
    M.w=w;
    M.h=h;
    M.nbRectDecor=0;
    return M;
}

void addRectDecorToMap(RectDecor R, Map* M) {
    M->listeRectDecor[M->nbRectDecor] = R;
    M->nbRectDecor++;    
}

void drawMap(Map M) {
    for (int i=0; i<M.nbRectDecor; i++) {
        drawRectDecor(M.listeRectDecor[i]);
    }
}