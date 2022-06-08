#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

class Edge
{
private:
    Vertex& _begin;

    Vertex& _end;

public:
    Vertex& GetBegin();

    Vertex& GetEnd();

    void setEdge(Vertex &Vb, Vertex &Ve);

    Edge(Vertex &Vb, Vertex &Ve):_begin(Vb),_end(Ve)
    {
    }

};

#endif // EDGE_H
