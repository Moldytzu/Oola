#include <iostream>
#include <oola.h>
#include <SDL2/SDL.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
bool isOpen = true;

void SDLRendererInit()
{
    SDL_Init(SDL_INIT_EVERYTHING);                                                                                 // init SDL2
    window = SDL_CreateWindow("oola", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN); // create a window with 800x600 resolution
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);                                           // create a renderer on first driver

    if (!window || !renderer) // check for initialisation errors
    {
        std::cout << "Failed to initialise renderer" << std::endl;
        SDL_Quit();
        abort();
    }
}

int main()
{
    Oola::EarlyStart(); // function defined in the game ran before everything

    // init engine
    std::cout << "Oola " << OOLA_VERSION << std::endl;

    SDLRendererInit();

    // call game start function
    Oola::Start();

    // event loop
    while (isOpen)
    {
        // handle sdl events
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                isOpen = false;
        }

        // tick the game
        Oola::Tick();
    }
}