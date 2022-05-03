
    /* Liberation des ressources associees a la SDL */
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;