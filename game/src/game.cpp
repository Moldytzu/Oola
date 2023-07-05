#include <oola.h>
#include <iostream>

Oola::Render::Mesh2D mesh;

void Oola::Core::EarlyStart()
{
    std::cout << "Early start\n";
}

void Oola::Core::Start()
{
    mesh.vertices.push_back(Render::Vertex2D(0,0));
    mesh.vertices.push_back(Render::Vertex2D(-0.5f,-0.5f));
    mesh.vertices.push_back(Render::Vertex2D(0.5f,-0.5f));
    std::cout << "Start\n";
}

void Oola::Core::Tick()
{
    Render::GlobalRender->drawPipeline.push_back(mesh);
}