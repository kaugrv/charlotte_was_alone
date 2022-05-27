// initialisation des variables globales et création des niveaux

    int loop = 1;
    int debug = 0;
    int pause = 0;
    int win = 0;
    int currentline = 1;
    int GAMESTATE = 0;

    // Variable d'input
    int keyLeft = 0, keyUp = 0, keyRight = 0, keySwitch = 0;

    onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);

    Niveaux J = createJeu();

    Niveau N1 = createNiveau1();
    Niveau N2 = createNiveau2();

    addNiveautoJeu(&N1, &J);
    addNiveautoJeu(&N2, &J);

  
    Niveau* N = J.liste[J.NiveauActuel];