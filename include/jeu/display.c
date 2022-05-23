
// Partie affichage de la boucle principale

/*
// réduction de la speed (test de la cam) // prochainement la speed physique du player
if (speedX >0) speedX = max (speedX-8,0.0);
if (speedX <0) speedX = min (speedX+8,0.0);
if (speedY >0) speedY = max (speedY-8,0.0);
if (speedY <0) speedY = min (speedY+8,0.0);
printf("speedX : %f // speedY : %f \n", speedX,speedY);*/

/* Recuperation du temps au debut de la boucle */
Uint32 startTime = SDL_GetTicks();

/* Placer ici le code de dessin */

glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

glPushMatrix();


switch (GAMESTATE) {

    case 0:; // MENU
        afficheMenu(currentline);
        break;


    case 1:; // UN NIVEAU
        drawRect(3000,3000,0,0,1,1,1,1); //fond
        glPushMatrix();

            showCamera(&camTest);
            drawMap(M);
            // drawRectDecor(R6);

            showPerso(&persoTest);    
            
            RectDecor Rperso = createRectDecor(persoTest.width, persoTest.height, persoTest.x, persoTest.y, persoTest.r, persoTest.g, persoTest.b);

            
            if (distance(R9.x, R9.y, persoTest.x, persoTest.y) <= R9.w/2) { // Perso dans sa case RectDecorFin = rouge
                drawRect(persoTest.width, persoTest.height, persoTest.x, persoTest.y, 0.8, 0,0,1);
            }

            else { // Perso pas dans sa case
                drawRect(persoTest.width, persoTest.height, persoTest.x, persoTest.y, persoTest.r, persoTest.g, persoTest.b,1);
            }

            if (debug) { // Mode debug : affichage QUADTREE (si B a été pressé)
                printQuadTree(&Q);
                debugQuadTrees(Q, Rperso, M);

            }

        glPopMatrix();
        
        break;

    case 2:; // MENU PAUSE

        drawRect(3000,3000,0,0,1,1,1,1); //fond

        glPushMatrix();
            showCamera(&camTest);
            drawMapFromQ(Q);
            
            //drawRect(persoTest.width,persoTest.height, persoTest.x, persoTest.y, 0,0,0,1);
            showPerso(&persoTest);
            if (debug) {
                printQuadTree(&Q);
                debugQuadTrees(Q, Rperso, M);
            }
        glPopMatrix();

        affichePause(currentline);
        break;

        }

        glPopMatrix();




    /* Echange du front et du back buffer : mise a jour de la fenetre */
    SDL_GL_SwapWindow(window);