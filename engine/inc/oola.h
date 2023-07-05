#pragma once
#include <SDL2/SDL.h>

#define OOLA_VERSION "dev"

namespace Oola
{
    extern void EarlyStart();
    extern void Start();
    extern void Tick();

    class Rectangle2D
    {
    public:
        double x, y, width, height;

        Rectangle2D(double x, double y, double width, double height);
    };

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
        class ColliderBox2D : public Rectangle2D
        {
        public:
            // NOTE: members inherited are actually offsets from the center of the entity
            ColliderBox2D(double x, double y, double width, double height);
        };

        class Entity2D
        {
        public:
            double x, y;                 // coordinates
            double width, height;        // size
            double velocityX, velocityY; // velocities

            ColliderBox2D collider;

            Entity2D();
            Entity2D(double x, double y, double w, double h);
        };

        void BounceEntities(Entity2D a, Entity2D b);
    };

};