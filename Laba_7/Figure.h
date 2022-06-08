#ifndef FIGURE_H
#define FIGURE_H

#include <vector>

#include "SceneObject.h"
#include "Vertex.h"
#include "Edge.h"

using namespace std;

class Figure: public SceneObject
{
private:
    vector<Vertex> _vertices;

    vector<Edge> _edges;

public:
    vector<Vertex> GetVertices();

    vector<Edge> GetEdges();

    void Transform(TransformMatrix& matr) override;

    void Normalize(NormalizationParameters& par, float maxV, float minV) override;

    void AddVertex(Vertex& v);

    void AddEdge(Edge& e);

};

#endif // FIGURE_H
