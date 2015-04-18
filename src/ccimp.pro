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
    gui/ccimp_img_view.cpp

HEADERS  += gui/mainwindow.h \
    model/test_klasse.h \
    gui/ccimp_tree_view.h \
    gui/ccimp_img_view.h

FORMS    += gui/mainwindow.ui \
    gui/ccimp_tree_view.ui \
    gui/ccimp_img_view.ui

RESOURCES += \
    ../res/resources.qrc

CONFIG += c++11
