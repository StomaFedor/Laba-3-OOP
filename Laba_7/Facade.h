#ifndef FACADE_H
#define FACADE_H

#include <string>
#include <QPainter>
#include <QLabel>

#include "FacadeOperationResult.h"
#include "BaseFileReader.h"
#include "NormalizationParameters.h"
#include "Scene.h"
#include "SceneDrawerBase.h"
#include "FileReader.h"
#include "QtSceneDrawer.h"
#include "TransformMatrixBuilder.h"

#define PI 3.1415926535

using namespace std;

class Facade
{
public:
    void DrawScene(QLabel& label);

    void LoadScene(string filename, NormalizationParameters& par);

    void MoveScene(float x, float y, float z);

    void RotateScene(float x, float y, float z);

    void ScaleScene(float ScaleX, float ScaleY, float ScaleZ);

    void NormalizeScene(NormalizationParameters& par);

    Facade(FileReader* fileReader, SceneDrawerBase* sceneDrawer):_fileReader(fileReader),_sceneDrawer(sceneDrawer){};

private:
    BaseFileReader *_fileReader;

    SceneDrawerBase *_sceneDrawer;

    Scene _scene;

};

#endif // FACADE_H
