#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QtAlgorithms>
#include <QVector>
#include <QDebug>
#include <QPainter>
#include <QKeyEvent>
#include <iostream>
#include <string>

#include "Facade.h"
#include "NormalizationParameters.h"
#include "FacadeException.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_fileDialog_clicked();

    void on_stepXSpinBox_valueChanged(double arg1);

    void on_stepYSpinBox_valueChanged(double arg1);

    void on_trigSpinBox_valueChanged(double arg1);

    void on_shiftXSpinBox_valueChanged(double arg1);

    void on_minNormalSpinBox_valueChanged(double arg1);

    void on_maxNormalSpinBox_valueChanged(double arg1);

    void on_shiftYSpinBox_valueChanged(double arg1);

protected:
    void keyPressEvent(QKeyEvent *e) override;

private:
    Ui::MainWindow *ui;

    Facade facade;

    NormalizationParameters NormParameters;

    FileReader FileReader;

    QtSceneDrawer SceneDrawer;

    NormalizationParameters setNormalizationParametrs();

    string QstringToString(QString qstr);

    void draw();

};
#endif // MAINWINDOW_H
