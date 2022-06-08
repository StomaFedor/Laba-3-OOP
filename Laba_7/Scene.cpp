#include "Scene.h"

void Scene::AddFigure(Figure& f)
{
    _figures.push_back(f);
}

void Scene::TransformFigures(TransformMatrix& matr)
{
    for (size_t i = 0; i < _figures.size(); i++)
        _figures[i].Transform(matr);
}

void Scene::NormalizeFigures(NormalizationParameters &par)
{
    for (size_t i = 0; i < _figures.size(); i++) {
        float maxV = ValueFinder::FindMaxZ(_figures[i].GetVertices());
        float minV = ValueFinder::FindMinZ(_figures[i].GetVertices());
        _figures[i].Normalize(par, maxV, minV);
    }
}

vector<Figure> Scene::GetFigures()
{
    return _figures;
}
