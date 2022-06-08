#ifndef TRANSFORMMATRIXBUILDER_H
#define TRANSFORMMATRIXBUILDER_H

#include <math.h>

#include "TransformMatrix.h"

class TransformMatrixBuilder
{
public:
    static TransformMatrix CreateRotationMatrix(float x, float y, float z);

    static TransformMatrix CreateMoveMatrix(float x, float y, float z);

    static TransformMatrix CreateScaleMatrix(float x, float y, float z);

};

#endif // TRANSFORMMATRIXBUILDER_H
