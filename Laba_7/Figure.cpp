#include "Figure.h"

void Figure::AddVertex(Vertex &v)
{
    _vertices.push_back(v);
}

void Figure::AddEdge(Edge &e)
{
    _edges.push_back(e);
}

vector<Vertex> Figure::GetVertices()
{
    return _vertices;
}

vector<Edge> Figure::GetEdges()
{
    return _edges;
}

void Figure::Transform(TransformMatrix &matr)
{
    for (size_t i = 0; i < _vertices.size(); i++)
        _vertices[i].Transform(matr);
}

void Figure::Normalize(NormalizationParameters &par, float maxV, float minV)
{
    for (size_t i = 0; i < _vertices.size(); i++)
        _vertices[i].Normalize(par, maxV, minV);
}
