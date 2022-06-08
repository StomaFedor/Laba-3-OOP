#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "Figure.h"
#include "NormalizationParameters.h"
#include "ValueFinder.h"

using namespace std;

class Scene
{
private:
    vector<Figure> _figures;

public:
    vector<Figure> GetFigures();

    void AddFigure(Figure& f);

    void TransformFigures(TransformMatrix& matr);

    void NormalizeFigures(NormalizationParameters& par);

};

#endif // SCENE_H
