#include <iostream>
#include <chrono>
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
        auto a = std::chrono::system_clock::now(); 

        Render::GlobalRender->Prepare(); // tick the renderer
        Core::Tick();                    // tick the game
        Render::GlobalRender->Render();  // render objects

        auto b = std::chrono::system_clock::now();
        double nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(b - a).count();
        Time::DeltaTime = nanos / Time::NanosecondsToSeconds;

        Log::Info("dt: %f FPS: %f",Time::DeltaTime, 1/Time::DeltaTime);
    }
}