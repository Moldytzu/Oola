#include <iostream>
#include <oola.h>
#include <SDL2/SDL.h>

Oola::Render::Renderer *GlobalRender;

int main()
{
    Oola::EarlyStart(); // function defined in the game ran before everything

    // init engine
    std::cout << "Oola " << OOLA_VERSION << std::endl;

    GlobalRender = new Oola::Render::OpenGLRenderer; // create a new opengl renderer
    GlobalRender->Start();                           // start the renderer

    // call game start function
    Oola::Start();

    // event loop
    while (GlobalRender->isActive)
    {
        GlobalRender->Tick(); // tick the renderer
        Oola::Tick();         // tick the game
    }
}