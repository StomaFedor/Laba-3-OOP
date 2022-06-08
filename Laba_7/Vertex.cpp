#include "Vertex.h"

void Vertex::SetPosition(float x, float y, float z)
{
    _position.X = x;
    _position.Y = y;
    _position.Z = z;
}

Point3D Vertex::GetPosition()
{
    return _position;
}

void Vertex::Transform(TransformMatrix& matr)
{
    _position = matr.TransformPoint(_position);
}

void Vertex::Normalize(NormalizationParameters& par, float maxV, float minV)
{
    _position.Y = par.Min + (_position.Y - minV) * (par.Max - par.Min) / (maxV - minV);
}
