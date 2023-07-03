#pragma once
#include <SDL2/SDL.h>

#define OOLA_VERSION "dev"

namespace Oola
{
    extern void EarlyStart();
    extern void Start();
    extern void Tick();

    namespace Render
    {
        class Renderer
        {
        public:
            bool isActive;

            Renderer();

            virtual void Start();
            virtual void Tick();
        };

        class OpenGLRenderer : public Renderer
        {
        public:
            SDL_Window *window;
            SDL_Renderer *renderer;

            void Start();
            void Tick();
        };

        extern Renderer *GlobalRender;
    };

    namespace Physics
    {
        class Entity
        {
        public:
            int x, y;                    // coordinates
            int width, height;           // size
            double velocityX, velocityY; // velocities

            // collider box points
            int left;
            int right;
            int top;
            int bottom;

            Entity();
            Entity(int x, int y, int w, int h);
        };

        void BounceEntities(Entity a, Entity b);
    };

};