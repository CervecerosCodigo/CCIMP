#-------------------------------------------------
#
# Project created by QtCreator 2015-04-08T11:40:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ccimp
TEMPLATE = app


SOURCES += main.cpp\
        gui/mainwindow.cpp \
    model/test_klasse.cpp \
    gui/ccimp_tree_view.cpp \
    model/tool.cpp \
    model/processing_interface.cpp \
    model/image_processing_unit.cpp \
    model/image_tool.cpp \
    model/tool_blur.cpp

HEADERS  += gui/mainwindow.h \
    model/test_klasse.h \
    gui/ccimp_tree_view.h \
    model/tool.h \
    model/processing_interface.h \
    model/image_processing_unit.h \
    model/image_tool.h \
    model/tool_blur.h

FORMS    += gui/mainwindow.ui \
    gui/ccimp_tree_view.ui

RESOURCES += \
    ../res/resources.qrc

CONFIG += c++11
