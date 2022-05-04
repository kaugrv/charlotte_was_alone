#include "quadtree.h"

// Renvoie 1 si Q est une feuille
int isLeaf(QuadTree Q) {
    if (Q.BottomLeft==NULL && Q.BottomRight==NULL && Q.TopLeft==NULL && Q.TopRight==NULL) {
        return 1;
    }
    return 0;
}

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

    printf("malloc success\n");

    TL->size = Q->size/2;
    TR->size = Q->size/2;
    BL->size = Q->size/2;
    BR->size = Q->size/2;

    TL->xTopLeft = Q->xTopLeft;
    TL->yTopLeft = Q->yTopLeft;

    TR->xTopLeft = Q->xTopLeft+Q->size/2;
    TR->yTopLeft = Q->yTopLeft;

    BL->xTopLeft = Q->xTopLeft;
    BL->yTopLeft = Q->yTopLeft-Q->size/2;

    BR->xTopLeft = Q->xTopLeft+Q->size/2;
    BR->yTopLeft = Q->yTopLeft-Q->size/2;

    TL->nbRectDecor=0;
    TR->nbRectDecor=0;
    BL->nbRectDecor=0;
    BR->nbRectDecor=0;

    TL->TopLeft=NULL;
    TL->TopRight=NULL;
    TL->BottomLeft=NULL;
    TL->BottomRight=NULL;

    TR->TopLeft=NULL;
    TR->TopRight=NULL;
    TR->BottomLeft=NULL;
    TR->BottomRight=NULL;

    BL->TopLeft=NULL;
    BL->TopRight=NULL;
    BL->BottomLeft=NULL;
    BL->BottomRight=NULL;

    BR->TopLeft=NULL;
    BR->TopRight=NULL;
    BR->BottomLeft=NULL;
    BR->BottomRight=NULL;

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

    for (int i=0; i<M.nbRectDecor; i++) {
        Q.listeRectDecor[i] = M.listeRectDecor[i];
    }

    Q.nbRectDecor = M.nbRectDecor;

    Q.xTopLeft = -M.w/2;
    Q.yTopLeft = M.h/2;

    Q.size = M.w;

    Q.TopLeft=NULL;
    Q.TopRight=NULL;
    Q.BottomLeft=NULL;
    Q.BottomRight=NULL;

    return Q;
}


// Remplit le quadtree final
void buildQuadTree(QuadTree* Q) {

    printf("nbRectDecor=%d\n", Q->nbRectDecor);

    createChildren(Q);
    
    heritedRectDecor(Q->TopLeft, Q->listeRectDecor, Q->nbRectDecor);
    heritedRectDecor(Q->TopRight, Q->listeRectDecor, Q->nbRectDecor);
    heritedRectDecor(Q->BottomLeft, Q->listeRectDecor, Q->nbRectDecor);
    heritedRectDecor(Q->BottomRight, Q->listeRectDecor, Q->nbRectDecor);


    if (Q->nbRectDecor > 4) {
        if (Q->TopLeft!= NULL && Q->TopLeft->nbRectDecor > 4) {
            buildQuadTree(Q->TopLeft);
        }

        if (Q->TopRight!=NULL && Q->TopRight->nbRectDecor > 4) {
            buildQuadTree(Q->TopRight);
        }

        if (Q->BottomLeft!=NULL && Q->BottomLeft->nbRectDecor > 4) {
            buildQuadTree(Q->BottomLeft);
        }

        if (Q->BottomRight!=NULL  && Q->BottomRight->nbRectDecor > 4) {
            buildQuadTree(Q->BottomRight);
        }
    
    }

    printf("Tree is built!\n");


}




// Affichage du QuadTree + dessin quadrillages sur écran
void printQuadTree(QuadTree* Q) {

    if (Q!=NULL) {

        drawQuadrillage(Q->xTopLeft+Q->size/2,Q->yTopLeft-Q->size/2, Q->size);

        if (isLeaf(*Q)) {
            return ;
        }
        
        else {
            if (Q->TopRight!=NULL && Q->TopRight->nbRectDecor>4) printQuadTree(Q->TopRight);
            if (Q->TopLeft!=NULL && Q->TopLeft->nbRectDecor>4) printQuadTree(Q->TopLeft);
            if (Q->BottomLeft!=NULL&& Q->BottomLeft->nbRectDecor>4) printQuadTree(Q->BottomLeft);
            if (Q->BottomRight!=NULL&& Q->BottomRight->nbRectDecor>4) printQuadTree(Q->BottomRight);
        }

    }

    return;
}


void printQ(QuadTree* Q) {
    printf("TL Nul? %d \n", Q->TopLeft==NULL);
    printf("TR Nul? %d \n", Q->TopRight==NULL);
    printf("BL Nul? %d \n", Q->BottomLeft==NULL);
    printf("BR Nul? %d \n", Q->BottomRight==NULL);

    printf("xTopLeft=%f\n", Q->xTopLeft);
    printf("yTopLeft=%f\n", Q->yTopLeft);

    printf("size=%f\n", Q->size);

    printf("nbRectDecor : %d\n", Q->nbRectDecor);

    printf("------------\n");

    if (Q->TopLeft!=NULL) {
        printf("Enfant TL :\n");
        printQ(Q->TopLeft);

    } 

    if (Q->TopRight!=NULL){
        printf("Enfant TR :\n");
        printQ(Q->TopRight);
    }

    if (Q->BottomLeft!=NULL) {
        printf("Enfant BL : \n");
        printQ(Q->BottomLeft) ;
    }
    
    if (Q->BottomRight!=NULL) {
        printf("Enfant BR : \n");
        printQ(Q->BottomRight);
    }

}


void drawMapFromQ(QuadTree Q) {
    for (int i=0; i<Q.nbRectDecor; i++) {
        drawRectDecor(Q.listeRectDecor[i]);
    }
}