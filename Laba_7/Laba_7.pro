QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Edge.cpp \
    Facade.cpp \
    Figure.cpp \
    FileReader.cpp \
    QtSceneDrawer.cpp \
    Scene.cpp \
    StringHelper.cpp \
    TransformMatrix.cpp \
    TransformMatrixBuilder.cpp \
    ValueFinder.cpp \
    Vertex.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    BaseFileReader.h \
    Edge.h \
    Facade.h \
    FacadeException.h \
    Figure.h \
    FileReader.h \
    NormalizationParameters.h \
    Point3D.h \
    QtSceneDrawer.h \
    Scene.h \
    SceneDrawerBase.h \
    SceneObject.h \
    StringHelper.h \
    TransformMatrix.h \
    TransformMatrixBuilder.h \
    ValueFinder.h \
    Vertex.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
