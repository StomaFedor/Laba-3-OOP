#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "TransformMatrix.h"
#include "NormalizationParameters.h"

class SceneObject
{
public:
    virtual void Transform(TransformMatrix&) = 0;

    virtual void Normalize(NormalizationParameters& par, float maxV, float minV) = 0;

};

#endif // SCENEOBJECT_H
