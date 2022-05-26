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
    Animation X20_2 = createAnimation('Y',300,0.01);
    Animation oppoX20_2 = createAnimation('Y',300,-0.01);

    float dx=0;
    float dy=0;

    ListeAnimation Listetest = initListe();
    addAnimToList(X20_2, &Listetest);
    addAnimToList(oppoX20_2, &Listetest);
    listeLoop(1, &Listetest);


    Map M = createMap(1280,1280); // taille de la map et creation de la map

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

    RectDecor R10 = createRectDecor(50,50,20,20,253/255.0,108/255.0,158/255.0);


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




Niveau createNiveau2(){
    Perso persoTest = createPerso(60,90, 0.,1.,0., 20-1000,-1200, 100,100, 200);
    Perso Wooly = createPerso(90,60, 1.,0.,1., 300-1000,-1200, 500,100, 100);
    Perso Charlie = createPerso(50,120, 0.,1.,1., 200-1000,-1200, 600,100, 500);
    Perso Arthur = createPerso(200,200, 0.,0.,1., -200-1000,-1200, 900,100, 30);

    Perso* team[6];
    team[0] = &persoTest;
    team[1] = &Wooly;
    team[2] = &Charlie;
    team[3] = &Arthur;
    
    Player player = createPlayer(team, 4);

    Camera camTest = createCamera(player.team[player.activePerso]->posStartX, player.team[player.activePerso]->posStartY, 1.5, 1.5);

///////////////////////////////////////
    Animation testAnimVide = createAnimationVide();
    Animation X300_3 = createAnimation('X',300,3);
    Animation oppoX300_1 = createAnimation('X',300,-1);

    float dx=0;
    float dy=0;

    ListeAnimation Listetest = initListe();
    addAnimToList(X300_3, &Listetest);
    addAnimToList(oppoX300_1, &Listetest);
    listeLoop(1, &Listetest);

///////////////////////////////////////

    // défintion de la couleur du décors
    float r = 253/255.0;
    float g = 108/255.0;
    float b = 158/255.0;
    
    
    Map M = createMap(3000,3000); // taille de la map et creation de la map

    
    
    // création du contour de la map
    RectDecor R1 = createRectDecor(3000,50,0,-1475,r,g,b);
    addRectDecorToMap(R1, &M);

    RectDecor R2 = createRectDecor(3000,50,0,1475,r,g,b);
    addRectDecorToMap(R2, &M);

    RectDecor R3 = createRectDecor(50,3000,1475,0,r,g,b);
    addRectDecorToMap(R3, &M);

    RectDecor R4 = createRectDecor(50,3000,-1475,0,r,g,b);
    addRectDecorToMap(R4, &M);
    /////////////////



    // RectDecor R5 = createRectDecor(200,50,-500,R1.y+R1.h/2+25,r,g,b);
    // addRectDecorToMap(R5, &M);

    // RectDecor R6 = createRectDecor(200,200,-500+R5.w,R1.y+R1.h/2+100,r,g,b);
    // addRectDecorToMap(R6, &M);

    // RectDecor R7 = createRectDecor(200,200,-100+R5.w,R1.y+R1.h/2+100,r,g,b);
    // addRectDecorToMap(R7, &M);



    RectDecorFin RpersoTest = createRectDecor(persoTest.width, persoTest.height, -persoTest.posStartX,R1.y+R1.h/2+persoTest.height/2, 0.8,0,0);
    addRectDecorFinToMap(RpersoTest, &M);

    RectDecorFin RWooly = createRectDecor(Wooly.width, Wooly.height, -Wooly.posStartX,R1.y+R1.h/2+Wooly.height/2, 0.8,0,0);
    addRectDecorFinToMap(RWooly, &M);

    RectDecorFin RCharlie = createRectDecor(Charlie.width, Charlie.height, -Charlie.posStartX,R1.y+R1.h/2+Charlie.height/2, 0.8,0,0);
    addRectDecorFinToMap(RCharlie, &M);

    RectDecorFin RArthur = createRectDecor(Arthur.width, Arthur.height, -Arthur.posStartX,R1.y+R1.h/2+Arthur.height/2, 0.8,0,0);
    addRectDecorFinToMap(RArthur, &M);


    QuadTree Q = initRootFromMap(M);
    buildQuadTree(&Q);


    return createNiveau(2, M, Q, player, camTest);
}


Niveau createNiveau3() {
    Perso persoTest = createPerso(60,90, 0.,1.,0., 20-1000,-1200, 100,100, 200);
    Perso Wooly = createPerso(90,60, 1.,0.,1., 300-1000,-1200, 500,100, 100);
    Perso Charlie = createPerso(50,120, 0.,1.,1., 200-1000,-1200, 600,100, 500);
    Perso Arthur = createPerso(200,200, 0.,0.,1., -200-1000,-1200, 900,100, 30);

    Perso* team[6];
    team[0] = &persoTest;
    team[1] = &Wooly;
    team[2] = &Charlie;
    team[3] = &Arthur;
    
    Player player = createPlayer(team, 4);

    Camera camTest = createCamera(player.team[player.activePerso]->posStartX, player.team[player.activePerso]->posStartY, 1.5, 1.5);


//ANIMATION
///////////////////////////////////////
    Animation A1 = createAnimation('X',300,0.01);
    Animation A2 = createAnimation('X',300,-0.01);
    printAnimation(&A1);



    ListeAnimation Listetest = initListe();
    addAnimToList(A1, &Listetest);
    addAnimToList(A2, &Listetest);
    listeLoop(1, &Listetest);

    printListeAnimation(&Listetest);


///////////////////////////////////////

    // défintion de la couleur du décors
    float r = 0;
    float g = 0;
    float b = 1;
    
    
    Map M = createMap(3000,3000); // taille de la map et creation de la map

    
    
    // création du contour de la map
    RectDecor R1 = createRectDecor(3000,50,0,-1475,r,g,b);
    addRectDecorToMap(R1, &M);

    RectDecor R2 = createRectDecor(3000,50,0,1475,r,g,b);
    addRectDecorToMap(R2, &M);

    RectDecor R3 = createRectDecor(50,3000,1475,0,r,g,b);
    addRectDecorToMap(R3, &M);
    

    RectDecor R4 = createRectDecor(50,3000,-1475,0,r,g,b);
    addRectDecorToMap(R4, &M);
    //////////////////

    //printf("nb anim dans liste 0: %d\n",M.listeRectDecorAnim[0]->animations->nbAnim);

    // rectDecor animé
    RectDecor Ranim = createRectDecor(300,50,0,-1400,1.0,0,0);

    animateRectDecor(&Ranim,&Listetest);


    addRectDecorAnimToMap(&Ranim,&M);


    // V
    ///////////////////////

    RectDecorFin RpersoTest = createRectDecor(persoTest.width, persoTest.height, -persoTest.posStartX,R1.y+R1.h/2+persoTest.height/2, 0.8,0,0);
    addRectDecorFinToMap(RpersoTest, &M);

    RectDecorFin RWooly = createRectDecor(Wooly.width, Wooly.height, -Wooly.posStartX,R1.y+R1.h/2+Wooly.height/2, 0.8,0,0);
    addRectDecorFinToMap(RWooly, &M);

    RectDecorFin RCharlie = createRectDecor(Charlie.width, Charlie.height, -Charlie.posStartX,R1.y+R1.h/2+Charlie.height/2, 0.8,0,0);
    addRectDecorFinToMap(RCharlie, &M);

    RectDecorFin RArthur = createRectDecor(Arthur.width, Arthur.height, -Arthur.posStartX,R1.y+R1.h/2+Arthur.height/2, 0.8,0,0);
    addRectDecorFinToMap(RArthur, &M);


    QuadTree Q = initRootFromMap(M);
    buildQuadTree(&Q);


    return createNiveau(3, M, Q, player, camTest);
}


int displayNiveau(Niveau* N, int debug) {

    printf("nb anim dans liste 1: %d\n",N->M.listeRectDecorAnim[0]->animations->nbAnim);

    drawRect(3000,3000,0,0,1,1,1,1); //fond

    glPushMatrix();

        showCamera(&N->C);
        drawMap(N->M);
        
        showPersos(&N->player);    
        
        drawRect(N->player.team[N->player.activePerso]->width, N->player.team[N->player.activePerso]->height, N->player.team[N->player.activePerso]->x, N->player.team[N->player.activePerso]->y, N->player.team[N->player.activePerso]->r, N->player.team[N->player.activePerso]->g, N->player.team[N->player.activePerso]->b,1);

        int levelFinished = 1;
        
        for (int i=0; i<N->player.nbPersos;i++) {


            if (distance(N->M.listeRectDecorFin[i].x, N->M.listeRectDecorFin[i].y, N->player.team[i]->x, N->player.team[i]->y) <= N->M.listeRectDecorFin[i].w/2) { // Perso dans sa case RectDecorFin = rouge
                //printf("%f\n", distance(N->M.listeRectDecorFin[i].x, N->M.listeRectDecorFin[i].y, N->player.team[i]->x, N->player.team[i]->y));
                drawRect(N->player.team[i]->width, N->player.team[i]->height, N->player.team[i]->x, N->player.team[i]->y, 0.8, 0,0,1);
            
            }
            else {
                levelFinished = 0;
            }

        }

        if (levelFinished){
            return 1;
        }


        if (debug) { // Mode debug : affichage QUADTREE (si B a été pressé)
            printQuadTree(&N->Q);
            //debugQuadTrees(N->Q, Rperso, N->M);
        }
    


    glPopMatrix();

    return 0;

    
}

void restartNiveau(Niveau* N) {
    for (int i=0; i<N->player.nbPersos; i++) {
        N->player.team[i]->x = N->player.team[i]->posStartX;
        N->player.team[i]->y = N->player.team[i]->posStartY;
    }
}



Niveaux createJeu() {
    Niveaux L;
    L.nbNiveaux = 0;
    L.NiveauActuel=0;
    return L;
}

void addNiveautoJeu(Niveau* N, Niveaux* L) {
    L->liste[L->nbNiveaux] = N;
    L->nbNiveaux++;
}

void switchNiveau(Niveaux* J, int *win) {
    if (*win==0) return;
    else if (J->NiveauActuel < J->nbNiveaux-1) {
        *win=0;
        restartNiveau(J->liste[J->NiveauActuel]);
        J->NiveauActuel++;
        return;
    }


}