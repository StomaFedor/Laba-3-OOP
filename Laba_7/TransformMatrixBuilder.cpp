#include "TransformMatrixBuilder.h"

TransformMatrix TransformMatrixBuilder::CreateRotationMatrix(float x, float y, float z)
{
    float matr[4][4] = {
        {cos(y)*cos(z),                      cos(y)*sin(z),                      (-1)*sin(y),   0},
        {sin(x)*sin(y)*cos(z)-cos(x)*sin(z), sin(x)*sin(y)*sin(z)+cos(x)*cos(z), sin(x)*cos(y), 0},
        {cos(x)*sin(y)*cos(z)+sin(x)*sin(z), cos(x)*sin(y)*sin(z)-sin(x)*cos(z), cos(x)*cos(y), 0},
        {0,                                  0,                                  0,             1}
    };

    TransformMatrix M;
    M = matr;

    return M;
}

TransformMatrix TransformMatrixBuilder::CreateMoveMatrix(float x, float y, float z)
{
    float matr[4][4] = {
    {1, 0, 0, x},
    {0, 1, 0, y},
    {0, 0, 1, z},
    {0, 0, 0, 1}
    };

    TransformMatrix M;
    M = matr;
    return M;
}

TransformMatrix TransformMatrixBuilder::CreateScaleMatrix(float x, float y, float z)
{
    float matr[4][4] = {
    {x, 0, 0, 0},
    {0, y, 0, 0},
    {0, 0, z, 0},
    {0, 0, 0, 1}
    };

    TransformMatrix M;
    M = matr;
    return M;
}
