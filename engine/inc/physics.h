#pragma once
#include "SDL2/SDL.h"

const int BLOCK_SIZE = 35;

namespace physics
{
    class Entity
    {
    public:
        int x, y; // The x and  yaxis and the entity`s width and height
        const int EntityW, EntityH;
        double VelocityX, VelocityY; // Entities velocity
        int left = x;
        int right = x + EntityW;
        int top = y;
        int bottom = y + EntityH;

        Entity(int x, int y, int W, int H, SDL_Rect entity);
    };
    void checkForColision(Entity a, Entity b) //checks for colision between the entities
    {
        if (a.bottom <= b.top)
        {
            a.VelocityY == -a.VelocityY;
            b.VelocityY == -b.VelocityY;
        }

        if (a.top >= b.bottom)
        {
            a.VelocityY == -a.VelocityY;
            b.VelocityY == -b.VelocityY;
        }

        if (a.right <= b.left)
        {
            a.VelocityX == -a.VelocityX;
            b.VelocityX == -b.VelocityX;
        }

        if (a.left >= b.right)
        {
            a.VelocityX == -a.VelocityX;
            b.VelocityX == -b.VelocityX;
        }
    }
}
