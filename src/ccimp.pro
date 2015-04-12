#-------------------------------------------------
#
# Project created by QtCreator 2015-04-08T11:40:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = src
TEMPLATE = app


SOURCES += main.cpp\
        gui/mainwindow.cpp \
    model/image_tool.cpp \
    model/tool_blur.cpp \
    model/test_klasse.cpp

HEADERS  += gui/mainwindow.h \
    model/image_tool.h \
    model/tool_blur.h \
    model/test_klasse.h

FORMS    += gui/mainwindow.ui

RESOURCES += \
    ../res/resources.qrc
