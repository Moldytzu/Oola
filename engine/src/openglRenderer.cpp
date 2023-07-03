#include <oola.h>
#include <SDL2/SDL.h>
#include <SDL_opengl.h>
#include <GL/glu.h>
#include <iostream>

using namespace Oola::Render;

void OpenGLRenderer::Start()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL_Init failed with " << SDL_GetError() << std::endl;
        SDL_Quit();
        abort();
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2); // we want opengl 2.1
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1); //

    this->window = SDL_CreateWindow("Oola " OOLA_VERSION, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, /*todo: replace these hardcoded values*/ SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN); // create a window with 800x600 resolution
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);                                                                                                                // create a renderer on first driver
    SDL_GL_CreateContext(this->window);                                                                                                                                                             // create a context for opengl

    if (!window || !renderer) // check for initialisation errors
    {
        std::cout << "Renderer/Window creation failed with " << SDL_GetError() << std::endl;
        SDL_Quit();
        abort();
    }

    this->isActive = true;

    // initialise opengl
    SDL_GL_SetSwapInterval(1);   // set vsync
    glMatrixMode(GL_PROJECTION); // set projection matrix
    glLoadIdentity();

    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
    {
        std::cout << "OpenGL failed with " << gluErrorString(error) << std::endl;
        SDL_Quit();
        abort();
    }

    glClearColor(0, 0, 0, 1.0f); // black
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

    glClear(GL_COLOR_BUFFER_BIT); // clear colours

    glBegin(GL_QUADS);        // begin drawing
    glVertex2f(-0.5f, -0.5f); // left top point
    glVertex2f(0.5f, -0.5f);  // right top point
    glVertex2f(0.5f, 0.5f);   // right bottom point
    glVertex2f(-0.5f, 0.5f);  // left bottom point
    glEnd();                  // stop drawin

    SDL_GL_SwapWindow(this->window); // swap buffers
}