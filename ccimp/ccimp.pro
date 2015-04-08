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
        mainwindow.cpp \
    image_tool.cpp \
    tool_blur.cpp

HEADERS  += mainwindow.h \
    image_tool.h \
    tool_blur.h

FORMS    += mainwindow.ui
