    int loop = 1;
    int debug = 0;
    int pause = 0;

    int currentline = 1;
    int GAMESTATE = 1;

    // Variable d'input
    int keyLeft = 0, keyUp = 0, keyRight = 0, keySwitch = 0;

    onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);


    Niveau N1 = createNiveau1();
    Niveau N2 = createNiveau2();

    Niveau* N = &N2; 