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

    Niveau N0 = createNiveau0();
    Niveau N1 = createNiveau1();
    // Niveau N2 = createNiveau2();
    // Niveau N3 = createNiveau3();
    // Niveau N4 = createNiveau4();
    // Niveau N5 = createNiveau5();
    // Niveau N6 = createNiveau6();
    // Niveau N7 = createNiveau7();
    // Niveau N8 = createNiveau8();
    // Niveau N9 = createNiveau9();


    addNiveautoJeu(&N0, &J);
    addNiveautoJeu(&N1, &J);
    // addNiveautoJeu(&N2, &J);
    // addNiveautoJeu(&N3, &J);
    // addNiveautoJeu(&N4, &J);
    // addNiveautoJeu(&N5, &J);
    // addNiveautoJeu(&N6, &J);
    // addNiveautoJeu(&N7, &J);
    // addNiveautoJeu(&N8, &J);
    // addNiveautoJeu(&N9, &J);





    Niveau* N = J.liste[J.NiveauActuel];

