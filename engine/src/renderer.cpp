#include <oola.h>

using namespace Oola;

void Render::Mesh2D::PushVertex(double x, double y)
{
    PushVertex(Vertex2D(x, y));
}

void Render::Mesh2D::PushVertex(const Vertex2D &vertex)
{
    vertices.push_back(vertex);
}

Render::Vertex2D::Vertex2D(double x, double y) : Core::Point2D(x, y) {}

Render::Renderer::Renderer() : isActive(true) {}
void Render::Renderer::Start() {}
void Render::Renderer::Prepare() {}
void Render::Renderer::Render() {}