#include "quadtree.h"


void drawQuadrillage(float x, float y, float size) {

    glPushMatrix();

    glTranslatef(x,y,0);

    glColor3f(1,0,0);
    glBegin(GL_LINES);
        

        glVertex2f(-size/2,0.0);
        glVertex2f(size/2,0.0);
        
        glColor3f(1,0,0);
        glVertex2f(0.0,-size/2);
        glVertex2f(0.0, size/2);

       
    glEnd();
    glPopMatrix();


}

// renvoie 0 si RectDecor R n'a aucun de ses 4 coins dans la zone carrée de taille size et de coin supérieur gauche xTopLeft, yTopLeft
int rectDecorInZone(RectDecor R, float xTopLeft, float yTopLeft, float size){
    
    // calcul des coordonnées des 4 coins de R
    float aX = R.x - R.w/2;
    float aY = R.y + R.h/2;

    float bX = R.x + R.w/2;
    float bY = R.y + R.h/2;

    float cX = R.x - R.w/2;
    float cY = R.y - R.h/2;

    float dX = R.x + R.w/2;
    float dY = R.y - R.h/2;

    float T[8]  = {aX, aY, bX, bY, cX, cY, dX, dY};

    // test si le point est dans le carré 
    for (int i = 0; i<7; i+=2){
        if (T[i] >=xTopLeft && T[i] <= xTopLeft+size && T[i+1] <= yTopLeft && T[i+1] >= yTopLeft-size) return 1;
    }

    return 0;

}


// subdivise la zone en ses quatre enfants
void createChildren(QuadTree* Q) {

    struct QuadTree *TL = malloc(sizeof(struct QuadTree));
    struct QuadTree *TR = malloc(sizeof(struct QuadTree));
    struct QuadTree *BL = malloc(sizeof(struct QuadTree));
    struct QuadTree *BR = malloc(sizeof(struct QuadTree));

    TL->size = Q->size/2;
    TR->size = Q->size/2;
    BL->size = Q->size/2;
    BR->size = Q->size/2;

    TL->xTopLeft = Q->xTopLeft;
    TL->yTopLeft = Q->yTopLeft;

    TR->xTopLeft = Q->xTopLeft+TR->size;
    TR->yTopLeft = Q->yTopLeft;

    BL->xTopLeft = Q->xTopLeft;
    BL->yTopLeft = Q->yTopLeft-BL->size;

    BR->xTopLeft = Q->xTopLeft+BR->size;
    BR->yTopLeft = Q->yTopLeft-BR->size;

    TL->nbRectDecor=0;
    TR->nbRectDecor=0;
    BL->nbRectDecor=0;
    BR->nbRectDecor=0;

    Q->TopLeft=TL;
    Q->TopRight=TR;
    Q->BottomLeft=BL;
    Q->BottomRight=BR;


}


// remplit le quadtree enfant des rectdecors de la liste du parent qui s'y trouvent
void heritedRectDecor(QuadTree* Q, RectDecor listeRectDecorParent[256], int nbRectDecorParent) {
    for (int i=0; i<nbRectDecorParent; i++) {
        if (rectDecorInZone(listeRectDecorParent[i], Q->xTopLeft, Q->yTopLeft, Q->size)) {
            Q->listeRectDecor[Q->nbRectDecor] = listeRectDecorParent[i];
            Q->nbRectDecor++;
        }
    }
}

// crée la racine du QuadTree depuis les rectangles de la Map
QuadTree initRootFromMap(Map M) {
    QuadTree Q;
    Q.listeRectDecor = M.listeRectDecor;
    Q.nbRectDecor = M.nbRectDecor;

    Q.xTopLeft = -M.w/2;
    Q.yTopLeft = -M.h/2;

    Q.size = M.w;

    Q.TopLeft=NULL;
    Q.TopRight=NULL;
    Q.BottomLeft=NULL;
    Q.BottomRight=NULL;

    return Q;
}


// Remplit le quadtree final
void buildQuadTree(QuadTree* Q) {

    createChildren(Q);

    heritedRectDecor(Q->TopLeft, Q->listeRectDecor, Q->nbRectDecor);
    heritedRectDecor(Q->TopRight, Q->listeRectDecor, Q->nbRectDecor);
    heritedRectDecor(Q->BottomLeft, Q->listeRectDecor, Q->nbRectDecor);
    heritedRectDecor(Q->BottomRight, Q->listeRectDecor, Q->nbRectDecor);

    if (Q->TopLeft->nbRectDecor > 4) {
        buildQuadTree(Q->TopLeft);
    }

    if (Q->TopRight->nbRectDecor > 4) {
        buildQuadTree(Q->TopRight);
    }

    if (Q->BottomLeft->nbRectDecor > 4) {
        buildQuadTree(Q->BottomLeft);
    }

    if (Q->BottomRight->nbRectDecor > 4) {
        buildQuadTree(Q->BottomRight);
    }

}

// Renvoie 1 si Q est une feuille
int isLeaf(QuadTree Q) {
    if (Q.BottomLeft==NULL && Q.BottomRight==NULL && Q.TopLeft==NULL && Q.TopRight==NULL) {
        return 1;
    }
    return 0;
}


// Affichage du QuadTree + dessin quadrillages sur écran
void printQuadTree(QuadTree* Q) {
    printf("Nombre de rect présents : %d\n", Q->nbRectDecor);

    if (isLeaf(*Q)) {
        return ;
    }
    else {
        drawQuadrillage(Q->xTopLeft+Q->size/2,Q->yTopLeft-Q->size/2, Q->size);
        printQuadTree(Q->TopRight);
        printQuadTree(Q->TopLeft);
        printQuadTree(Q->BottomLeft);
        printQuadTree(Q->BottomRight);

    }
}
