#include <iostream>
#include <oola.h>
#include <SDL2/SDL.h>

using namespace Oola;

Core::Rectangle2D::Rectangle2D(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {}
Core::Point2D::Point2D(double x, double y) : x(x), y(y) {}

int main()
{
    Core::EarlyStart(); // function defined in the game ran before everything

    // init engine
    Log::Info("Starting Oola version %s", OOLA_VERSION);

    Render::GlobalRender = new Oola::Render::OpenGLRenderer; // create a new opengl renderer
    Render::GlobalRender->Start();                           // start the renderer

    Log::Info("Initialising game");

    // call game start function
    Core::Start();

    Log::Info("Running event loop");

    // event loop
    while (Render::GlobalRender->isActive)
    {
        Render::GlobalRender->Prepare(); // tick the renderer
        Core::Tick();                    // tick the game
        Render::GlobalRender->Render();  // render objects
    }
}