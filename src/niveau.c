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



// Template 4 persos + rectangle qui bouge

// Niveau createNiveau0() {

    // struct Perso* persoTest = malloc(sizeof(struct Perso));
    // struct Perso* Wooly = malloc(sizeof(struct Perso));
    // struct Perso* Charlie = malloc(sizeof(struct Perso));
    // struct Perso* Arthur = malloc(sizeof(struct Perso));


    // *persoTest = createPerso(60,90, 0.,1.,0., 20-1000,-1200, 100,100, 100);
    // *Wooly = createPerso(90,100, 1.,0.,1., 300-1000,-1200, 500,100, 400);
    // *Charlie = createPerso(50,120, 0.,1.,1., 200-1000,-1200, 600,100, 100);
    // *Arthur = createPerso(200,200, 0.,0.,1., -200-1000,-1200, 900,100, 50);

    // struct Perso** team = malloc(6*sizeof(struct Perso));

    // team[0] = persoTest;
    // team[1] = Wooly;
    // team[2] = Charlie;
    // team[3] = Arthur;

    // struct Player* player = malloc(sizeof(struct Player));
    // *player = createPlayer(team, 4);

//     Camera camTest = createCamera(player->team[player->activePerso]->posStartX, player->team[player->activePerso]->posStartY, 1.5, 1.5);

//     Map M = createMap(3000,3000); // taille de la map et creation de la map

//     float r = 238/255.0;
//     float g = 158/255.0;
//     float b = 204/255.0;


//     Animation A1 = createAnimation('X',300,5);
//     Animation A2 = createAnimation('Y',300,5);
//     Animation A3 = createAnimation('X',300, -5);
//     Animation A4 = createAnimation('Y', 300, -5);

//     struct ListeAnimation *L1 = malloc(sizeof(struct ListeAnimation));
//     *L1 = initListe();
//     addAnimToList(A1, L1);
//     addAnimToList(A2, L1);
//     addAnimToList(A3, L1);
//     addAnimToList(A4, L1);
//     listeLoop(1, L1);
//     struct RectDecor* Ranim = malloc(sizeof(struct RectDecor));
//     *Ranim = createRectDecor(300,50,-400,-1400,r,g,b);
//     animateRectDecor(Ranim,L1);
//     addRectDecorAnimToMap(Ranim,&M);






//     // Contours de la map
//     RectDecor R1 = createRectDecor(3000,50,0,-1475,r,g,b);
//     addRectDecorToMap(R1, &M);
//     RectDecor R2 = createRectDecor(3000,50,0,1475,r,g,b);
//     addRectDecorToMap(R2, &M);
//     RectDecor R3 = createRectDecor(50,3000,1475,0,r,g,b);
//     addRectDecorToMap(R3, &M);
//     RectDecor R4 = createRectDecor(50,3000,-1475,0,r,g,b);
//     addRectDecorToMap(R4, &M);


    // // Les 4 cases de fin
    // RectDecorFin RpersoTest = createRectDecor(persoTest->width, persoTest->height, -persoTest->posStartX,R1.y+R1.h/2+persoTest->height/2, 1,1,1);
    // addRectDecorFinToMap(RpersoTest, &M);
    // RectDecorFin RWooly = createRectDecor(Wooly->width, Wooly->height, -Wooly->posStartX,R1.y+R1.h/2+Wooly->height/2, 1,1,1);
    // addRectDecorFinToMap(RWooly, &M);
    // RectDecorFin RCharlie = createRectDecor(Charlie->width, Charlie->height, -Charlie->posStartX,R1.y+R1.h/2+Charlie->height/2, 1,1,1);
    // addRectDecorFinToMap(RCharlie, &M);
    // RectDecorFin RArthur = createRectDecor(Arthur->width, Arthur->height, -Arthur->posStartX,R1.y+R1.h/2+Arthur->height/2, 1,1,1);
    // addRectDecorFinToMap(RArthur, &M);


//     // Quadtree shit
//     QuadTree Q = initRootFromMap(M);
//     buildQuadTree(&Q);


//     return createNiveau(0, M, Q, *player, camTest);
// }



Niveau createNiveau0(){

    struct Perso* persoTest = malloc(sizeof(struct Perso));
    struct Perso* Wooly = malloc(sizeof(struct Perso));
    struct Perso* Charlie = malloc(sizeof(struct Perso));
    struct Perso* Arthur = malloc(sizeof(struct Perso));


    *persoTest = createPerso(60,90, 0.,1.,0., 20-1000,-1200, 100,100, 100);
    *Wooly = createPerso(90,100, 1.,0.,1., 300-1000,-1200, 500,100, 400);
    *Charlie = createPerso(50,120, 0.,1.,1., 200-1000,-1200, 600,100, 100);
    *Arthur = createPerso(200,200, 0.,0.,1., -200-1000,-1200, 900,100, 50);

    struct Perso** team = malloc(6*sizeof(struct Perso));

    team[0] = persoTest;
    team[1] = Wooly;
    team[2] = Charlie;
    team[3] = Arthur;

    struct Player* player = malloc(sizeof(struct Player));
    *player = createPlayer(team, 4);

    Camera camTest = createCamera(player->team[player->activePerso]->posStartX, player->team[player->activePerso]->posStartY, 1.5, 1.5);


    Map M = createMap(3000,3000); // taille de la map et creation de la map

    float r = 238/255.0;
    float g = 158/255.0;
    float b = 204/255.0;


    // Contours de la map
    RectDecor R1 = createRectDecor(3000,50,0,-1475,r,g,b);
    addRectDecorToMap(R1,&M);
    RectDecor R2 = createRectDecor(3000,50,0,1475,r,g,b);
    addRectDecorToMap(R2,&M);
    RectDecor R3 = createRectDecor(50,3000,1475,0,r,g,b);
    addRectDecorToMap(R3,&M);
    RectDecor R4 = createRectDecor(50,3000,-1475,0,r,g,b);
    addRectDecorToMap(R4,&M);

    RectDecor R5 = createRectDecor(600, 500, 0, R1.y+R1.h/2+250, r,g,b);
    addRectDecorToMap(R5, &M);

    RectDecor R6 = createRectDecor(200, 250, -400, R1.y+R1.h/2+250/2, r,g,b);
    addRectDecorToMap(R6, &M);


    // RectDecor R7 = createRectDecor(50, 50, -600, -1300, r,g,b);
    // addRectDecorToMap(R7, &M);

    // RectDecor R8 = createRectDecor(50, 50, -600, -1200, r,g,b);
    // addRectDecorToMap(R8, &M);

    // RectDecor R9 = createRectDecor(50, 50, -600, -1100, r,g,b);
    // addRectDecorToMap(R9, &M);
    
    // RectDecor R10 = createRectDecor(50, 50, -600, -1000, r,g,b);
    // addRectDecorToMap(R10, &M);

    // RectDecor R11 = createRectDecor(50, 50, -600, -900, r,g,b);
    // addRectDecorToMap(R11, &M);

    // RectDecor R12 = createRectDecor(50, 50, -500, -1000, r,g,b);
    // addRectDecorToMap(R12, &M);

    // RectDecor R13 = createRectDecor(50, 50, -500, -900, r,g,b);
    // addRectDecorToMap(R13, &M);


    // Cases de fin

    RectDecorFin RpersoTest = createRectDecor(persoTest->width, persoTest->height, -persoTest->posStartX,R1.y+R1.h/2+persoTest->height/2, 1,1,1);
    addRectDecorFinToMap(RpersoTest, &M);
    RectDecorFin RWooly = createRectDecor(Wooly->width, Wooly->height, -Wooly->posStartX,R1.y+R1.h/2+Wooly->height/2, 1,1,1);
    addRectDecorFinToMap(RWooly, &M);
    RectDecorFin RCharlie = createRectDecor(Charlie->width, Charlie->height, -Charlie->posStartX,R1.y+R1.h/2+Charlie->height/2, 1,1,1);
    addRectDecorFinToMap(RCharlie, &M);
    RectDecorFin RArthur = createRectDecor(Arthur->width, Arthur->height, -Arthur->posStartX,R1.y+R1.h/2+Arthur->height/2, 1,1,1);
    addRectDecorFinToMap(RArthur, &M);



    // Quadtree shit
    QuadTree Q = initRootFromMap(M);
    buildQuadTree(&Q);

    return createNiveau(0, M, Q, *player, camTest);
}

Niveau createNiveau1(){

    struct Perso* persoTest = malloc(sizeof(struct Perso));

    *persoTest = createPerso(60,90, 1.,1.,0., 20-1000,-1200, 100,100, 200);

    struct Perso** team = malloc(6*sizeof(struct Perso));

    team[0] = persoTest;

    struct Player* player = malloc(sizeof(struct Player));
    *player = createPlayer(team, 1);

    Camera camTest = createCamera(player->team[player->activePerso]->posStartX, player->team[player->activePerso]->posStartY, 1.5, 1.5);


    Map M = createMap(3000,3000); // taille de la map et creation de la map

    float r = 238/255.0;
    float g = 158/255.0;
    float b = 204/255.0;


    // Contours de la map
    RectDecor R1 = createRectDecor(3000,50,0,-1475,r,g,b);
    addRectDecorToMap(R1,&M);
    RectDecor R2 = createRectDecor(3000,50,0,1475,r,g,b);
    addRectDecorToMap(R2,&M);
    RectDecor R3 = createRectDecor(50,3000,1475,0,r,g,b);
    addRectDecorToMap(R3,&M);
    RectDecor R4 = createRectDecor(50,3000,-1475,0,r,g,b);
    addRectDecorToMap(R4,&M);

    RectDecor R5 = createRectDecor(600, 800, 0, R1.y+R1.h/2+400, r,g,b);
    addRectDecorToMap(R5, &M);


    RectDecor R6 = createRectDecor(600, 1600, 1000, R1.y+R1.h/2+800, r,g,b);
    addRectDecorToMap(R6, &M);


    Animation A1 = createAnimation('X',100,5);
    Animation A2 = createAnimation('Y',600,5);
    Animation A3 = createAnimation('X',100, -5);
    Animation A4 = createAnimation('Y', 600, -5);
    struct ListeAnimation *L1 = malloc(sizeof(struct ListeAnimation));
    *L1 = initListe();
    addAnimToList(A1, L1);
    addAnimToList(A2, L1);
    addAnimToList(A3, L1);
    addAnimToList(A4, L1);
    listeLoop(1, L1);
    struct RectDecor* Ranim = malloc(sizeof(struct RectDecor));
    *Ranim = createRectDecor(200,50,-600,-1400,r,g,b);
    animateRectDecor(Ranim,L1);
    addRectDecorAnimToMap(Ranim,&M);


    Animation A5 = createAnimation('Y', 1000, 5);
    Animation A6 = createAnimation('Y', 1000, -5);
    struct ListeAnimation *L2 = malloc(sizeof(struct ListeAnimation));
    *L2 = initListe();
    addAnimToList(A5, L2);
    addAnimToList(A6, L2);
    listeLoop(1, L2);
    struct RectDecor* Ranim2 = malloc(sizeof(struct RectDecor));
    *Ranim2 = createRectDecor(400,50,500,-1000,r,g,b);
    animateRectDecor(Ranim2,L2);
    addRectDecorAnimToMap(Ranim2,&M);


    // Cases de fin
    RectDecorFin RpersoTest = createRectDecor(persoTest->width, persoTest->height,1375,R1.y+R1.h/2+persoTest->height/2, 1,1,1);
    addRectDecorFinToMap(RpersoTest, &M);


    // Quadtree shit
    QuadTree Q = initRootFromMap(M);
    buildQuadTree(&Q);

    return createNiveau(1, M, Q, *player, camTest);
}




int displayNiveau(Niveau* N, int debug) {


    drawRect(3000,3000,0,0,68/255.0,40/255.0,83/255.0,1); //fond


    glPushMatrix();


        showCamera(&N->C);

        float r = 238/255.0;
        float g = 158/255.0;
        float b = 204/255.0;

        affichenumNiveau(N->n, r,g,b);
     
        drawMap(N->M);

        showPersos(&N->player);   

        // Perso actif devant 
        drawRect(N->player.team[N->player.activePerso]->width, N->player.team[N->player.activePerso]->height, N->player.team[N->player.activePerso]->x, N->player.team[N->player.activePerso]->y, N->player.team[N->player.activePerso]->r, N->player.team[N->player.activePerso]->g, N->player.team[N->player.activePerso]->b,1);

        selectActivePlayer(N->player.team[N->player.activePerso]->x, N->player.team[N->player.activePerso]->y, N->player.team[N->player.activePerso]->height,N->player.team[N->player.activePerso]->r, N->player.team[N->player.activePerso]->g, N->player.team[N->player.activePerso]->b);

        // Gestion fin du niveau
        int levelFinished = 1;
    
        for (int i=0; i<N->player.nbPersos;i++) {
            if (distance(N->M.listeRectDecorFin[i].x, N->M.listeRectDecorFin[i].y, N->player.team[i]->x, N->player.team[i]->y) <= N->M.listeRectDecorFin[i].w/2) { // Perso dans sa case RectDecorFin = rouge
                drawRect(N->player.team[i]->width, N->player.team[i]->height, N->player.team[i]->x, N->player.team[i]->y, 1, 1,1,1);
            }
            else {
                levelFinished = 0;
            }
        }
        if (levelFinished){
            return 1;
        }

        // Mode debug : affichage QUADTREE (si B a été pressé)
        if (debug) { 
            printQuadTree(&N->Q);

                    float xp= N->player.team[N->player.activePerso]->x;
                    float yp= N->player.team[N->player.activePerso]->y;
                    float wp= N->player.team[N->player.activePerso]->width;
                    float hp= N->player.team[N->player.activePerso]->height;

                    debugQuadTrees(N->Q, xp, yp, wp, hp, N->M);

                    debugRectQ(fillQuadTreeFromSearch(N->Q,N->player.team[N->player.activePerso]->x,N->player.team[N->player.activePerso]->y,N->player.team[N->player.activePerso]->width,N->player.team[N->player.activePerso]->height, N->M));
               
        
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
        restartNiveau(J->liste[J->NiveauActuel]);
        *win=0;
        J->NiveauActuel++;
        return;
    }

}
