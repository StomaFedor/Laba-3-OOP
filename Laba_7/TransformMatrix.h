#ifndef TRANSFORMMATRIX_H
#define TRANSFORMMATRIX_H

#include "Point3D.h"

class TransformMatrix
{
private:
    float _matr[4][4];

public:
    Point3D TransformPoint(Point3D& point);

    void operator=(const float matr[4][4]);

};

#endif // TRANSFORMMATRIX_H
