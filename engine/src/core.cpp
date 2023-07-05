#include <iostream>
#include <oola.h>
#include <SDL2/SDL.h>

using namespace Oola;

Render::Renderer *GlobalRender;

Core::Rectangle2D::Rectangle2D(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {}

int main()
{
    Core::EarlyStart(); // function defined in the game ran before everything

    // init engine
    std::cout << "Oola " << OOLA_VERSION << std::endl;

    GlobalRender = new Oola::Render::OpenGLRenderer; // create a new opengl renderer
    GlobalRender->Start();                           // start the renderer

    // call game start function
    Core::Start();

    // event loop
    while (GlobalRender->isActive)
    {
        GlobalRender->Tick(); // tick the renderer
        Core::Tick();         // tick the game
    }
}