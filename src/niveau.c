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



// Rose avec plateforme qui bouge
Niveau createNiveau0() {

    struct Perso* persoTest = malloc(sizeof(struct Perso));
    struct Perso* Wooly = malloc(sizeof(struct Perso));
    struct Perso* Charlie = malloc(sizeof(struct Perso));
    struct Perso* Arthur = malloc(sizeof(struct Perso));


    *persoTest = createPerso(60,90, 0.,1.,0., 20-1000,-1200, 100,100, 200);
    *Wooly = createPerso(90,60, 1.,0.,1., 300-1000,-1200, 500,100, 100);
    *Charlie = createPerso(50,120, 0.,1.,1., 200-1000,-1200, 600,100, 500);
    *Arthur = createPerso(200,200, 0.,0.,1., -200-1000,-1200, 900,100, 30);

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


    Animation A1 = createAnimation('X',500,15);
    Animation A2 = createAnimation('X',500,-15);
    struct ListeAnimation *L1 = malloc(sizeof(struct ListeAnimation));
    *L1 = initListe();
    addAnimToList(A1, L1);
    addAnimToList(A2, L1);
    listeLoop(1, L1);
    struct RectDecor* Ranim = malloc(sizeof(struct RectDecor));
    *Ranim = createRectDecor(300,50,0,-1400,r,g,b);
    animateRectDecor(Ranim,L1);
    addRectDecorAnimToMap(Ranim,&M);


    Animation A3 = createAnimation('Y',50,5);
    Animation A4 = createAnimation('Y',50,-5);
    struct ListeAnimation *L2 = malloc(sizeof(struct ListeAnimation));
    *L2 = initListe();
    addAnimToList(A3, L2);
    addAnimToList(A4, L2);
    listeLoop(1, L2);
    struct RectDecor* Ranim2 = malloc(sizeof(struct RectDecor));
    *Ranim2 = createRectDecor(300,50,-200,-1400,r,g,b);
    animateRectDecor(Ranim2,L2);
    addRectDecorAnimToMap(Ranim2,&M);







    // Contours de la map
    RectDecor R1 = createRectDecor(3000,50,0,-1475,r,g,b);
    addRectDecorToMap(R1, &M);
    RectDecor R2 = createRectDecor(3000,50,0,1475,r,g,b);
    addRectDecorToMap(R2, &M);
    RectDecor R3 = createRectDecor(50,3000,1475,0,r,g,b);
    addRectDecorToMap(R3, &M);
    RectDecor R4 = createRectDecor(50,3000,-1475,0,r,g,b);
    addRectDecorToMap(R4, &M);


    // Les 4 cases de fin
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


// Rose avec obstacles
Niveau createNiveau1(){

    struct Perso* persoTest = malloc(sizeof(struct Perso));
    struct Perso* Wooly = malloc(sizeof(struct Perso));
    struct Perso* Charlie = malloc(sizeof(struct Perso));

    *persoTest = createPerso(60,90, 0.,1.,0., 20-1000,-1200, 100,100, 200);
    *Wooly = createPerso(90,60, 1.,0.,1., 300-1000,-1200, 500,100, 100);
    *Charlie = createPerso(50,120, 0.,1.,1., 200-1000,-1200, 600,100, 500);

    struct Perso** team = malloc(6*sizeof(struct Perso));

    team[0] = persoTest;
    team[1] = Wooly;
    team[2] = Charlie;


    struct Player* player = malloc(sizeof(struct Player));
    *player = createPlayer(team, 3);

    Camera camTest = createCamera(player->team[player->activePerso]->posStartX, player->team[player->activePerso]->posStartY, 1.5, 1.5);


    Map M = createMap(3000,3000); // taille de la map et creation de la map

    // défintion de la couleur du décors
    float r = 00/255.0;
    float g = 00/255.0;
    float b = 0/255.0;

    // Animation A1 = createAnimation('Y',500,15);
    // Animation A2 = createAnimation('Y',500,-15);
    // struct ListeAnimation *L1 = malloc(sizeof(struct ListeAnimation));
    // *L1 = initListe();
    // addAnimToList(A1, L1);
    // addAnimToList(A2, L1);
    // listeLoop(1, L1);
    // struct RectDecor* Ranim = malloc(sizeof(struct RectDecor));
    // *Ranim = createRectDecor(300,50,0,-1400,1.0,0,0);
    // animateRectDecor(Ranim,L1);
    // addRectDecorAnimToMap(Ranim,&M);







    // Contours de la map
    RectDecor R1 = createRectDecor(3000,50,0,-1475,r,g,b);
    addRectDecorToMap(R1,&M);
    RectDecor R2 = createRectDecor(3000,50,0,1475,r,g,b);
    addRectDecorToMap(R2,&M);
    RectDecor R3 = createRectDecor(50,3000,1475,0,r,g,b);
    addRectDecorToMap(R3,&M);
    RectDecor R4 = createRectDecor(50,3000,-1475,0,r,g,b);
    addRectDecorToMap(R4,&M);


    // Les 4 cases de fin
    RectDecorFin RpersoTest = createRectDecor(persoTest->width, persoTest->height, -persoTest->posStartX,R1.y+R1.h/2+persoTest->height/2, 1,1,1);
    addRectDecorFinToMap(RpersoTest, &M);
    RectDecorFin RWooly = createRectDecor(Wooly->width, Wooly->height, -Wooly->posStartX,R1.y+R1.h/2+Wooly->height/2, 1,1,1);
    addRectDecorFinToMap(RWooly, &M);
    RectDecorFin RCharlie = createRectDecor(Charlie->width, Charlie->height, -Charlie->posStartX,R1.y+R1.h/2+Charlie->height/2, 1,1,1);
    addRectDecorFinToMap(RCharlie, &M);


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