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



// Template avec 4 persos + rectangle qui bouge

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

    struct Perso* Charlotte = malloc(sizeof(struct Perso));

    *Charlotte = createPerso(60, 90, 224/255.0,153/255.0,177/255.0, -980, -1200, 100, 100, 60);

    struct Perso** team = malloc(1*sizeof(struct Perso));


    team[0] = Charlotte;

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

    RectDecor R5 = createRectDecor(600, 200, 0, R1.y+R1.h/2+100, r,g,b);
    addRectDecorToMap(R5, &M);

    RectDecor R6 = createRectDecor(200, 150, -400, R1.y+R1.h/2+150/2, r,g,b);
    addRectDecorToMap(R6, &M);


    

    // Cases de fin
    RectDecorFin RCharlotte = createRectDecor(Charlotte->width, Charlotte->height, 980, R1.y+R1.h/2+Charlotte->height/2, 1,1,1);
    addRectDecorFinToMap(RCharlotte, &M);



    // Quadtree shit
    QuadTree Q = initRootFromMap(M);
    buildQuadTree(&Q);

    return createNiveau(0, M, Q, *player, camTest);
}



Niveau createNiveau1(){

    struct Perso* Charlotte = malloc(sizeof(struct Perso));
    struct Perso* Orange = malloc(sizeof(struct Perso));

    *Charlotte = createPerso(60, 90, 224/255.0,153/255.0,177/255.0, -1200, -1200, 100, 100, 60);
    *Orange = createPerso(30, 150, 250/255.0,205/255.0,170/255.0, -1100, -1200, 100, 100, 400);

    struct Perso** team = malloc(2*sizeof(struct Perso));


    team[0] = Charlotte;
    team[1] = Orange;

    struct Player* player = malloc(sizeof(struct Player));
    *player = createPlayer(team, 2);

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

    RectDecor R5 = createRectDecor(600, 200, -500, R1.y+R1.h/2+100, r,g,b);
    addRectDecorToMap(R5, &M);

    RectDecor R6 = createRectDecor(600, 500, 1200, R1.y+R1.h/2+250, r,g,b);
    addRectDecorToMap(R6, &M);




    Animation A1 = createAnimation('X',550,5);
    Animation A2 = createAnimation('X', 550, -5);

    struct ListeAnimation *L1 = malloc(sizeof(struct ListeAnimation));
    *L1 = initListe();
    addAnimToList(A1, L1);
    addAnimToList(A2, L1);
    listeLoop(1, L1);
    struct RectDecor* Ranim = malloc(sizeof(struct RectDecor));
    *Ranim = createRectDecor(400,50,50,-1400+300,r,g,b);
    animateRectDecor(Ranim,L1);
    addRectDecorAnimToMap(Ranim,&M);


    // Cases de fin

    RectDecorFin RCharlotte = createRectDecor(Charlotte->width, Charlotte->height, -Charlotte->posStartX, R1.y+R1.h/2+Charlotte->height/2+500, 1,1,1);
    addRectDecorFinToMap(RCharlotte, &M);
    RectDecorFin ROrange = createRectDecor(Orange->width, Orange->height, -Orange->posStartX,R1.y+R1.h/2+Orange->height/2+500, 1,1,1);
    addRectDecorFinToMap(ROrange, &M);


    // Quadtree shit
    QuadTree Q = initRootFromMap(M);
    buildQuadTree(&Q);

    return createNiveau(1, M, Q, *player, camTest);
}

Niveau createNiveau2(){

    struct Perso* Charlotte = malloc(sizeof(struct Perso));
    struct Perso* Orange = malloc(sizeof(struct Perso));
    struct Perso* Mauve = malloc(sizeof(struct Perso));

    *Charlotte = createPerso(60, 90, 224/255.0,153/255.0,177/255.0, -1000, -1200, 100, 100, 60);
    *Orange = createPerso(30, 150, 250/255.0,205/255.0,170/255.0, -1100, -1200, 100, 100, 400);
    *Mauve = createPerso(170, 40, 192/255.0,157/255.0,250/255.0, -1300, -1200, 100, 100, 30);

    

    struct Perso** team = malloc(2*sizeof(struct Perso));


    team[0] = Charlotte;
    team[1] = Orange;
    team[2] = Mauve;

    struct Player* player = malloc(sizeof(struct Player));
    *player = createPlayer(team, 3);

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

    RectDecor R5 = createRectDecor(600, 200, -500, R1.y+R1.h/2+100+50, r,g,b);
    addRectDecorToMap(R5, &M);

    RectDecor R6 = createRectDecor(500, 1400, 1500-300, R1.y+R1.h/2+1400/2+50, r,g,b);
    addRectDecorToMap(R6, &M);

    RectDecor R7 = createRectDecor(300, 100, 100, 500, r,g,b);
    addRectDecorToMap(R7, &M);






    Animation A1 = createAnimation('Y',550,5);
    Animation A2 = createAnimation('Y', 550, -5);

    struct ListeAnimation *L1 = malloc(sizeof(struct ListeAnimation));
    *L1 = initListe();
    addAnimToList(A1, L1);
    addAnimToList(A2, L1);
    listeLoop(1, L1);
    struct RectDecor* Ranim = malloc(sizeof(struct RectDecor));
    *Ranim = createRectDecor(400,50,50,-1300,r,g,b);
    animateRectDecor(Ranim,L1);
    addRectDecorAnimToMap(Ranim,&M);


    Animation A3 = createAnimation('Y',550,-5);
    Animation A4 = createAnimation('Y', 550, 5);

    struct ListeAnimation *L2 = malloc(sizeof(struct ListeAnimation));
    *L2 = initListe();
    addAnimToList(A3, L2);
    addAnimToList(A4, L2);
    listeLoop(1, L2);
    struct RectDecor* Ranim2 = malloc(sizeof(struct RectDecor));
    *Ranim2 = createRectDecor(550,50,600,-100,r,g,b);
    animateRectDecor(Ranim2,L2);
    addRectDecorAnimToMap(Ranim2,&M);


    Animation A5 = createAnimation('Y',550,5);
    Animation A6 = createAnimation('X', 700, -5);
    Animation A7 = createAnimation('Y',550,-5);
    Animation A8 = createAnimation('X', 700, 5);

    struct ListeAnimation *L3 = malloc(sizeof(struct ListeAnimation));
    *L3 = initListe();
    addAnimToList(A5, L3);
    addAnimToList(A6, L3);
    addAnimToList(A7, L3);
    addAnimToList(A8, L3);
    listeLoop(1, L3);
    struct RectDecor* Ranim3 = malloc(sizeof(struct RectDecor));
    *Ranim3 = createRectDecor(100,50,1500-300, 100,r,g,b);
    animateRectDecor(Ranim3,L3);
    addRectDecorAnimToMap(Ranim3,&M);



    // Cases de fin

    RectDecorFin RCharlotte = createRectDecor(Charlotte->width, Charlotte->height, R7.x-50, R7.y+R7.h/2+Charlotte->height/2, 1,1,1);
    addRectDecorFinToMap(RCharlotte, &M);
    RectDecorFin ROrange = createRectDecor(Orange->width, Orange->height, R7.x+50,R7.y+R7.h/2+Orange->height/2, 1,1,1);
    addRectDecorFinToMap(ROrange, &M);
    RectDecorFin RMauve = createRectDecor(Mauve->width, Mauve->height,-Mauve->posStartX,R1.y+R1.h/2+Mauve->height/2, 1,1,1);
    addRectDecorFinToMap(RMauve, &M);


    // Quadtree shit
    QuadTree Q = initRootFromMap(M);
    buildQuadTree(&Q);

    return createNiveau(2, M, Q, *player, camTest);
}




Niveau createNiveau3(){

    struct Perso* Charlotte = malloc(sizeof(struct Perso));
    struct Perso* Mauve = malloc(sizeof(struct Perso));
    struct Perso* Bleu = malloc(sizeof(struct Perso));
    struct Perso* Orange = malloc(sizeof(struct Perso));

    *Charlotte = createPerso(60, 90, 224/255.0,153/255.0,177/255.0, 980, -1200, 100, 100, 60);
    *Mauve = createPerso(170, 40, 192/255.0,157/255.0,250/255.0, 1200, -1200, 100, 100, 30);


    *Bleu = createPerso(150, 150, 163/255.0,209/255.0,240/255.0, -800, -1200, 100, 100, 30);
    *Orange = createPerso(30, 150, 250/255.0,205/255.0,170/255.0, -600, -1200, 100, 100, 400);

    struct Perso** team = malloc(4*sizeof(struct Perso));


    team[0] = Bleu;
    team[1] = Orange;
    
    team[2] = Charlotte;
    team[3] = Mauve;

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

    RectDecor R5 = createRectDecor(600, 200, 0, R1.y+R1.h/2+100, r,g,b);
    addRectDecorToMap(R5, &M);

    RectDecor R6 = createRectDecor(200, 150, -400, R1.y+R1.h/2+150/2, r,g,b);
    addRectDecorToMap(R6, &M);
    

    // Cases de fin

    RectDecorFin RBleu = createRectDecor(Bleu->width, Bleu->height, -Bleu->posStartX,R1.y+R1.h/2+Bleu->height/2, 1,1,1);
    addRectDecorFinToMap(RBleu, &M);
    RectDecorFin ROrange = createRectDecor(Orange->width, Orange->height, -Orange->posStartX,R1.y+R1.h/2+Orange->height/2, 1,1,1);
    addRectDecorFinToMap(ROrange, &M);

    RectDecorFin RCharlotte = createRectDecor(Charlotte->width, Charlotte->height, -980, R1.y+R1.h/2+Charlotte->height/2, 1,1,1);
    addRectDecorFinToMap(RCharlotte, &M);
    RectDecorFin RMauve = createRectDecor(Mauve->width, Mauve->height,-1200,R1.y+R1.h/2+Mauve->height/2, 1,1,1);
    addRectDecorFinToMap(RMauve, &M);



    // Quadtree shit
    QuadTree Q = initRootFromMap(M);
    buildQuadTree(&Q);

    return createNiveau(3, M, Q, *player, camTest);
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
