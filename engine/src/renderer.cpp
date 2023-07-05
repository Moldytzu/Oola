#include <oola.h>

using namespace Oola;

Render::Vertex2D::Vertex2D(double x, double y) : Core::Point2D(x,y) {}

Render::Renderer::Renderer() : isActive(true) {}
void Render::Renderer::Start() {}
void Render::Renderer::Prepare() {}
void Render::Renderer::Render() {}