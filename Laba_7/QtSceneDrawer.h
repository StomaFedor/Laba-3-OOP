#ifndef QTSCENEDRAWER_H
#define QTSCENEDRAWER_H

#include <QMainWindow>
#include <QPainter>
#include <iostream>

#include "SceneDrawerBase.h"
#include "Scene.h"

#define mapSize 600

class QtSceneDrawer: public SceneDrawerBase
{
public:
    void DrawScene(Scene& scene, QLabel& label) override;

private:
    void drawLines(QPainter* paint, Scene& scene);

};

#endif // QTSCENEDRAWER_H
