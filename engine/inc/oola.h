#pragma once
#include <SDL2/SDL.h>
#include <vector>

#define OOLA_VERSION "dev"

namespace Oola
{
    namespace Core
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

        class Point2D
        {
        public:
            double x, y;

            Point2D(double x, double y);
        };
    };

    namespace Log
    {
        void Info(const char *fmt, ...);
        void Warn(const char *fmt, ...);
        void Error(const char *fmt, ...);
        void Fatal(const char *fmt, ...);
    };

    namespace Time
    {   
        constexpr double NanosecondsToSeconds = 1000000000.0f;

        inline double Uptime;    // time since the game was started
        inline double DeltaTime; // time between frames
        inline double FPS;       // frames per second
    };

    namespace Render
    {
        class Vertex2D : public Core::Point2D // a vertex is a 2D point on the screen
        {
        public:
            Vertex2D(double x, double y);
        };

        class Mesh2D
        {
        public:
            std::vector<Vertex2D> vertices; // collection of vertices
        };

        class Renderer
        {
        public:
            bool isActive;
            std::vector<Mesh2D> drawPipeline; // meshes to be drawn

            Renderer();

            virtual void Start();   // called at initialisation
            virtual void Prepare(); // prepare a new frame
            virtual void Render();  // render a frame
        };

        class OpenGLRenderer : public Renderer
        {
        public:
            SDL_Window *window;
            SDL_Renderer *renderer;

            void Start();   // called at initialisation
            void Prepare(); // prepare a new frame
            void Render();  // render a frame
        };

        inline Renderer *GlobalRender;
    };

    namespace Physics
    {
        class ColliderBox2D : public Core::Rectangle2D
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