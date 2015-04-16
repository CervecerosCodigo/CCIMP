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
    model/image_tool.cpp \
    model/test_klasse.cpp \
    gui/ccimp_tree_view.cpp \
    model/command_blur_apply.cpp \
    model/image_tool_blur.cpp \
    model/command.cpp \
    model/command_blur_undo.cpp

HEADERS  += gui/mainwindow.h \
    model/image_tool.h \
    model/test_klasse.h \
    gui/ccimp_tree_view.h \
    model/command.h \
    model/command_blur_apply.h \
    model/command_blur_undo.h \
    model/image_tool_blur.h

FORMS    += gui/mainwindow.ui \
    gui/ccimp_tree_view.ui

RESOURCES += \
    ../res/resources.qrc

CONFIG += c++11
