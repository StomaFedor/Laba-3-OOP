#include "Edge.h"

Vertex& Edge::GetBegin()
{
    return _begin;
}

Vertex& Edge::GetEnd()
{
    return _end;
}

void Edge::setEdge(Vertex &Vb, Vertex &Ve)
{
    _begin = Vb;
    _end = Ve;
}
