#-------------------------------------------------
#
# Project created by QtCreator 2017-12-09T19:28:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opengl_home
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += widget

SOURCES += main.cpp\
        mainwindow.cpp \
    widget/qmywidget.cpp \
    widget/qmytexture.cpp \
    widget/qmyopengl.cpp \
    shader/qmyshadersrc.cpp \
    shader/qmyshader_p2uv.cpp \
    shader/qmyshader_p2.cpp \
    shader/qmyprogramid.cpp \
    camera/camerabase.cpp \
    home/ground.cpp \
    home/qmynodematrix.cpp \
    box_vertex_uv.cpp

HEADERS  += mainwindow.h \
    widget/qmywidget.h \
    widget/qmytexture.h \
    widget/qmyopengl.h \
    tool/CELLMath.hpp \
    shader/qmyshadersrc.h \
    shader/qmyshader_p2uv.h \
    shader/qmyshader_p2.h \
    shader/qmyprogramid.h \
    camera/camerabase.h \
    home/ground.h \
    home/qmynodematrix.h \
    box_vertex_uv.h

FORMS    += mainwindow.ui
LIBS += -lEGL -lfreeimage
