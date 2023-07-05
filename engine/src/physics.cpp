#include <oola.h>

using namespace Oola::Physics;

Entity2D::Entity2D() : x(0), y(0), collider(0, 0, 1, 1) {}
Entity2D::Entity2D(double x, double y, double width, double height) : x(x), y(y), width(width), height(height), collider(x, y, width, height) {}

ColliderBox2D::ColliderBox2D(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {}

void BounceEntities(Entity2D a, Entity2D b) // bounce entities if collision is detected
{
    // if (a.bottom <= b.top)
    // {
    //     a.velocityY = -a.velocityY;
    //     b.velocityY = -b.velocityY;
    // }

    // if (a.top >= b.bottom)
    // {
    //     a.velocityY = -a.velocityY;
    //     b.velocityY = -b.velocityY;
    // }

    // if (a.right <= b.left)
    // {
    //     a.velocityX = -a.velocityX;
    //     b.velocityX = -b.velocityX;
    // }

    // if (a.left >= b.right)
    // {
    //     a.velocityX = -a.velocityX;
    //     b.velocityX = -b.velocityX;
    // }
}