#include "TransformMatrix.h"

Point3D TransformMatrix::TransformPoint(Point3D &point)
{
    Point3D newPoint;
    newPoint.X = point.X * _matr[0][0] + point.Y * _matr[0][1] + point.Z * _matr[0][2] + _matr[0][3];;
    newPoint.Y = point.X * _matr[1][0] + point.Y * _matr[1][1] + point.Z * _matr[1][2] + _matr[1][3];
    newPoint.Z = point.X * _matr[2][0] + point.Y * _matr[2][1] + point.Z * _matr[2][2] + _matr[2][3];
    point.X = newPoint.X;
    point.Y = newPoint.Y;
    point.Z = newPoint.Z;

    return point;
}

void TransformMatrix::operator =(const float matr[4][4])
{
    for (int i = 0 ; i < 4; i++)
        for (int j = 0 ; j < 4; j++)
            this->_matr[i][j] = matr[i][j];
}
