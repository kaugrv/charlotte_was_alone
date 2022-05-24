#include "niveau.h"


Niveau createNiveau(int n, Map M, QuadTree Q, Perso P, Camera C) {
    Niveau N;
    N.n = n;
    N.M = M;
    N.Q = Q;
    N.P = P;
    N.C = C;
    return N;
}

Niveau createNiveau1() {

    Perso persoTest = createPerso(60,90, 0.,0.,0., 20,20, 100,100, 100);
    Camera camTest = createCamera(persoTest.posStartX, persoTest.posStartY, 2, 2);


    Animation testAnimVide = createAnimationVide();
    Animation X20_2 = createAnimation('Y',300,3);
    Animation oppoX20_2 = createAnimation('Y',300,-1);

    float dx=0;
    float dy=0;

    ListeAnimation Listetest = initListe();
    addAnimToList(X20_2, &Listetest);
    addAnimToList(oppoX20_2, &Listetest);
    listeLoop(1, &Listetest);


    Map M = createMap(1280,1280);

    RectDecor R1 = createRectDecor(640,100,-320,-310,253/255.0,108/255.0,158/255.0);
    RectDecor R2 = createRectDecor(200,250,100,-235,253/255.0,108/255.0,158/255.0);
    RectDecor R3 = createRectDecor(150,200,285,200,253/255.0,108/255.0,158/255.0);
    RectDecor R4 = createRectDecor(50,50,0,240,253/255.0,108/255.0,158/255.0);
    RectDecor R5 = createRectDecor(100,100,-200,200,253/255.0,108/255.0,158/255.0);
    
    RectDecor R6 = createRectDecor(50,50,40,40,108/255.0,108/255.0,108/255.0);
    animateRectDecor(&R6, &Listetest);
    
    RectDecor R7 = createRectDecor(50,50,80,80,253/255.0,108/255.0,158/255.0);
    RectDecor R8 = createRectDecor(50,50,80,140,253/255.0,108/255.0,158/255.0);

    RectDecorFin R9 = createRectDecor(persoTest.width,persoTest.height,-300,0, 0.8,0,0);

    RectDecor R10 = createRectDecor(50,50,20,40,253/255.0,108/255.0,158/255.0);


    addRectDecorToMap(R1, &M);
    addRectDecorToMap(R2, &M);
    addRectDecorToMap(R3, &M);
    addRectDecorToMap(R4, &M);
    addRectDecorToMap(R5, &M);

    addRectDecorAnimToMap(&R6, &M);

    addRectDecorToMap(R7, &M);
    addRectDecorToMap(R8, &M);

    addRectDecorFinToMap(R9, &M);

    addRectDecorToMap(R10, &M);

    

    QuadTree Q = initRootFromMap(M);
    buildQuadTree(&Q);


    return createNiveau(1, M, Q, persoTest, camTest);
}




Niveau createNiveau2();
Niveau createNiveau3();


void displayNiveau(Niveau* N, int debug) {

drawRect(3000,3000,0,0,1,1,1,1); //fond

    glPushMatrix();

        showCamera(&N->C);
        drawMap(N->M);
        showPerso(&N->P);    
        
        RectDecor Rperso = createRectDecor(N->P.width, N->P.height, N->P.x, N->P.y, N->P.r, N->P.g, N->P.b);
        
        if (distance(N->M.listeRectDecorFin[0].x, N->M.listeRectDecorFin[0].y, N->P.x, N->P.y) <= N->M.listeRectDecorFin[0].w/2) { // Perso dans sa case RectDecorFin = rouge
            drawRect(N->P.width, N->P.height, N->P.x, N->P.y, 0.8, 0,0,1);
        }

        else { // Perso pas dans sa case
            drawRect(N->P.width, N->P.height, N->P.x, N->P.y, N->P.r, N->P.g, N->P.b,1);
        }


        if (debug) { // Mode debug : affichage QUADTREE (si B a été pressé)
            printQuadTree(&N->Q);
            debugQuadTrees(N->Q, Rperso, N->M);
        }


    glPopMatrix();

    
}