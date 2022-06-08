#include "QtSceneDrawer.h"

#include <iostream>

void QtSceneDrawer::DrawScene(Scene& scene, QLabel &label)
{
    QPixmap *pix = new QPixmap(mapSize, mapSize);
    QPainter paint(pix);
    paint.fillRect(0, 0, mapSize, mapSize, QBrush(QColor(Qt::GlobalColor::white)));
    paint.setPen(QColor(Qt::GlobalColor::black));
    drawLines(&paint, scene);
    label.setPixmap(*pix);
}

void QtSceneDrawer::drawLines(QPainter* paint, Scene &scene)
{
    vector<Figure> figures = scene.GetFigures();
    for (size_t i = 0; i < figures.size(); i++) {
        vector<Edge> edges = figures[i].GetEdges();
        for (size_t j = 0; j < edges.size(); j++){

            Vertex vEnd = edges[j].GetEnd();
            Vertex vBegin = edges[j].GetBegin();

            Point3D pE = vEnd.GetPosition();
            Point3D pB = vBegin.GetPosition();

            paint->drawLine(mapSize / 2 + 100 * pB.X / (pB.Z + 15), mapSize / 2 - 100 *pB.Y / (pB.Z + 15), mapSize / 2 + 100 *pE.X / (pE.Z + 15), mapSize / 2 - 100 *pE.Y / (pE.Z + 15));
        }

    }
}
