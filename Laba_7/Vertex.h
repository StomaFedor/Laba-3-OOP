#ifndef VERTEX_H
#define VERTEX_H

#include "Point3D.h"
#include "SceneObject.h"
#include "TransformMatrix.h"

class Vertex: public SceneObject
{
private:
    Point3D _position;

public:
    Point3D GetPosition();

    void Transform(TransformMatrix& matr) override;

    void Normalize(NormalizationParameters& par, float maxV, float minV) override;

    void SetPosition(float x, float y, float z);

};

#endif // VERTEX_H
