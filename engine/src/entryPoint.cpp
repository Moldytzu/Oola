#include <iostream>
#include <oola.h>
#include <SDL2/SDL.h>

void SDLRendererInit()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("oola" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 800 , 600 , SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window , -1 , SDL_RENDERER_ACCELERATED);

}

int main()
{
    Oola::EarlyStart(); // function defined in the game ran before everything
    
    // init engine
    std::cout << "Oola " << OOLA_VERSION << std::endl;

    SDLRendererInit();
    
    // call game start function
    Oola::Start();

    while(true)
    {
        Oola::Tick();
    }
}