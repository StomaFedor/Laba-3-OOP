#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , facade(Facade(&FileReader, &SceneDrawer))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

string MainWindow::QstringToString(QString qstr)
{
    string str;
    str = qstr.toLocal8Bit().constData();
    return str;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_A) {
        facade.RotateScene(0, NormParameters.degree, 0);
        draw();
    }
    else if (e->key() == Qt::Key_D) {
        facade.RotateScene(0, -NormParameters.degree, 0);
        draw();
    }
    else if (e->key() == Qt::Key_W) {
        facade.RotateScene(NormParameters.degree, 0, 0);
        draw();
    }
    else if (e->key() == Qt::Key_S) {
        facade.RotateScene(-NormParameters.degree, 0, 0);
        draw();
    }
    else if (e->key() == Qt::Key_Equal) {
        facade.ScaleScene(1 + NormParameters.Scale, 1 + NormParameters.Scale, 1 + NormParameters.Scale);
        draw();
    }
    else if (e->key() == Qt::Key_Minus) {
        facade.ScaleScene(1 - NormParameters.Scale, 1 - NormParameters.Scale, 1 - NormParameters.Scale);
        draw();
    }
}

NormalizationParameters MainWindow::setNormalizationParametrs()
{
    NormParameters.degree = ui->trigSpinBox->value();
    NormParameters.DxStep = ui->stepXSpinBox->value();
    NormParameters.DyStep = ui->stepYSpinBox->value();
    NormParameters.Max = ui->maxNormalSpinBox->value();
    NormParameters.Min = ui->minNormalSpinBox->value();
    NormParameters.XShift = ui->shiftXSpinBox->value();
    NormParameters.YShift = ui->shiftYSpinBox->value();
    return NormParameters;
}

void MainWindow::on_fileDialog_clicked()
{
    QString pathFileName = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", "CSV File (*.csv)");
    NormParameters = setNormalizationParametrs();
    string filename = QstringToString(pathFileName);
    try {
        if (pathFileName.isEmpty())
            throw FacadeException("File not found");
        facade.LoadScene(filename, NormParameters);
        draw();
    }  catch (FacadeException &ex) {
        QMessageBox::warning(this, "Ошибка", ex.what());
    }
}

void MainWindow::draw()
{
    facade.DrawScene(*ui->paintLabel);
}


void MainWindow::on_stepXSpinBox_valueChanged(double newStep)
{
    facade.ScaleScene(newStep - NormParameters.DxStep + 1, 0, 0);
    NormParameters.DxStep = newStep;
    draw();
}


void MainWindow::on_stepYSpinBox_valueChanged(double newStep)
{
    facade.ScaleScene(0, 0, newStep - NormParameters.DyStep + 1);
    NormParameters.DyStep = newStep;
    draw();
}


void MainWindow::on_trigSpinBox_valueChanged(double newDegree)
{
    NormParameters.degree = newDegree;
}


void MainWindow::on_shiftXSpinBox_valueChanged(double newShift)
{
    facade.MoveScene(newShift - NormParameters.XShift, 0, 0);
    NormParameters.XShift = newShift;
    draw();
}


void MainWindow::on_minNormalSpinBox_valueChanged(double min)
{
    NormParameters.Min = min;
    facade.NormalizeScene(NormParameters);
    draw();
}


void MainWindow::on_maxNormalSpinBox_valueChanged(double max)
{
    NormParameters.Max = max;
    facade.NormalizeScene(NormParameters);
    draw();
}


void MainWindow::on_shiftYSpinBox_valueChanged(double newShift)
{
    facade.MoveScene(0, newShift - NormParameters.YShift, 0);
    NormParameters.YShift = newShift;
    draw();
}

