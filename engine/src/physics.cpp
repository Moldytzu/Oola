#include <oola.h>

using namespace Oola::Physics;

Entity::Entity() : x(0), y(0), width(1), height(1), top(0), left(0), right(1), bottom(1)  {}
Entity::Entity(int x, int y, int width, int height) : x(x), y(y), width(width), height(height), top(y), left(x), right(x+width), bottom(y+height) {}

void BounceEntities(Entity a, Entity b) // bounce entities if collision is detected
{
    if (a.bottom <= b.top)
    {
        a.velocityY = -a.velocityY;
        b.velocityY = -b.velocityY;
    }

    if (a.top >= b.bottom)
    {
        a.velocityY = -a.velocityY;
        b.velocityY = -b.velocityY;
    }

    if (a.right <= b.left)
    {
        a.velocityX = -a.velocityX;
        b.velocityX = -b.velocityX;
    }

    if (a.left >= b.right)
    {
        a.velocityX = -a.velocityX;
        b.velocityX = -b.velocityX;
    }
}