#ifndef SCENEDRAWERBASE_H
#define SCENEDRAWERBASE_H

#include <QPainter>
#include <QLabel>

#include "Scene.h"

class SceneDrawerBase
{
public:
    virtual void DrawScene(Scene& scene, QLabel& label) = 0;

};

#endif // SCENEDRAWERBASE_H
