#include "niveau.h"


Niveau createNiveau(int n, Map M, QuadTree Q, Player player, Camera C) {
    Niveau N;
    N.n = n;
    N.M = M;
    N.Q = Q;
    N.player = player;
    N.C = C;
    return N;
}

Niveau createNiveau1() {

    Perso persoTest = createPerso(60,90, 0.,1.,0., 20,100, 100,100, 200);
    Perso Wooly = createPerso(90,60, 1.,0.,1., 300,100, 500,100, 100);
    Perso Charlie = createPerso(50,120, 0.,1.,1., 200,100, 600,100, 500);
    Perso Arthur = createPerso(200,200, 0.,0.,1., -200,500, 900,100, 30);

    Perso* team[6];
    team[0] = &persoTest;
    team[1] = &Wooly;
    team[2] = &Charlie;
    team[3] = &Arthur;
    
    Player player = createPlayer(team, 4);

    Camera camTest = createCamera(player.team[player.activePerso]->posStartX, player.team[player.activePerso]->posStartY, 1.5, 1.5);


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


    return createNiveau(1, M, Q, player, camTest);
}




Niveau createNiveau2();
Niveau createNiveau3();


void displayNiveau(Niveau* N, int debug) {

drawRect(3000,3000,0,0,1,1,1,1); //fond

    glPushMatrix();

        showCamera(&N->C);
        drawMap(N->M);
        showPersos(&N->player);    
        
        RectDecor Rperso = createRectDecor(N->player.team[N->player.activePerso]->width, N->player.team[N->player.activePerso]->height, N->player.team[N->player.activePerso]->x, N->player.team[N->player.activePerso]->y, N->player.team[N->player.activePerso]->r, N->player.team[N->player.activePerso]->g, N->player.team[N->player.activePerso]->b);
        
        if (distance(N->M.listeRectDecorFin[0].x, N->M.listeRectDecorFin[0].y, N->player.team[N->player.activePerso]->x, N->player.team[N->player.activePerso]->y) <= N->M.listeRectDecorFin[0].w/2) { // Perso dans sa case RectDecorFin = rouge
            drawRect(N->player.team[N->player.activePerso]->width, N->player.team[N->player.activePerso]->height, N->player.team[N->player.activePerso]->x, N->player.team[N->player.activePerso]->y, 0.8, 0,0,1);
        }

        else { // Perso pas dans sa case
            drawRect(N->player.team[N->player.activePerso]->width, N->player.team[N->player.activePerso]->height, N->player.team[N->player.activePerso]->x, N->player.team[N->player.activePerso]->y, N->player.team[N->player.activePerso]->r, N->player.team[N->player.activePerso]->g, N->player.team[N->player.activePerso]->b,1);
        }


        if (debug) { // Mode debug : affichage QUADTREE (si B a été pressé)
            printQuadTree(&N->Q);
            debugQuadTrees(N->Q, Rperso, N->M);
        }


    glPopMatrix();

    
}