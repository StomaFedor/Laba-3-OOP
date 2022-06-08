#include "Facade.h"

void Facade::LoadScene(string filename, NormalizationParameters &par)
{
    _scene = _fileReader->ReadScene(filename, par);
}

void Facade::DrawScene(QLabel& label)
{
    _sceneDrawer->DrawScene(_scene, label);
}

void Facade::ScaleScene(float ScaleX, float ScaleY, float ScaleZ)
{
    TransformMatrix Matr;

    if (ScaleX != 0)
    {
        Matr = TransformMatrixBuilder::CreateScaleMatrix(ScaleX, 1, 1);
        _scene.TransformFigures(Matr);
    }
    if (ScaleY != 0)
    {
        Matr = TransformMatrixBuilder::CreateScaleMatrix(1, ScaleY, 1);
        _scene.TransformFigures(Matr);
    }
    if (ScaleZ != 0)
    {
        Matr = TransformMatrixBuilder::CreateScaleMatrix(1, 1, ScaleZ);
        _scene.TransformFigures(Matr);
    }
}

void Facade::NormalizeScene(NormalizationParameters &par)
{
    _scene.NormalizeFigures(par);
}

void Facade::RotateScene(float RotateX, float RotateY, float RotateZ)
{
    TransformMatrix Matr;

    if (RotateX != 0)
    {
        Matr = TransformMatrixBuilder::CreateRotationMatrix(RotateX * PI / 180.0, RotateY * PI / 180.0, RotateZ * PI / 180.0);
        _scene.TransformFigures(Matr);
    }
    if (RotateY != 0)
    {
        Matr = TransformMatrixBuilder::CreateRotationMatrix(RotateX * PI / 180.0, RotateY * PI / 180.0, RotateZ * PI / 180.0);
        _scene.TransformFigures(Matr);
    }
    if (RotateZ != 0)
    {
        Matr = TransformMatrixBuilder::CreateRotationMatrix(RotateX * PI / 180.0, RotateY * PI / 180.0, RotateZ * PI / 180.0);
        _scene.TransformFigures(Matr);
    }
}

void Facade::MoveScene(float MoveX, float MoveY, float MoveZ)
{
    TransformMatrix Matr;

    if (MoveX != 0)
    {
        Matr = TransformMatrixBuilder::CreateMoveMatrix(MoveX, 0, 0);
        _scene.TransformFigures(Matr);
    }
    if (MoveY != 0)
    {
        Matr = TransformMatrixBuilder::CreateMoveMatrix(0, MoveY, 0);
        _scene.TransformFigures(Matr);
    }
    if (MoveZ != 0)
    {
        Matr = TransformMatrixBuilder::CreateMoveMatrix(0, 0, MoveZ);
        _scene.TransformFigures(Matr);
    }
}
