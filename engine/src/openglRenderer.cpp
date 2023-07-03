#include <oola.h>
#include <SDL2/SDL.h>
#include <iostream>

using namespace Oola::Render;

void OpenGLRenderer::Start()
{
    SDL_Init(SDL_INIT_EVERYTHING);                                                                                       // init SDL2
    this->window = SDL_CreateWindow("Oola " OOLA_VERSION, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN); // create a window with 800x600 resolution
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);                                     // create a renderer on first driver

    if (!window || !renderer) // check for initialisation errors
    {
        std::cout << "Failed to initialise renderer" << std::endl;
        SDL_Quit();
        abort();
    }

    this->isActive = true;
}

void OpenGLRenderer::Tick()
{
    // handle sdl events
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            this->isActive = false;
    }
}