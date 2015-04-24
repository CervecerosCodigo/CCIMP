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
    model/tool.cpp \
    model/processing_interface.cpp \
    model/image_processing_unit.cpp \
    model/image_tool.cpp \
    model/tool_blur.cpp \
    model/image_wrapper.cpp \
    model/image_statistics.cpp \
    test/test_lab.cpp \
    model/parameter_using_colors.cpp \
    model/parameter_using_coordiantes.cpp \
    model/parameter_using_slider.cpp \
    model/instantiate_tools.cpp \
    test/guitest.cpp \
    test/controllertest.cpp \
    test/observertest.cpp \
    model/listen_for_image_change.cpp \
    gui/slider_dialog.cpp \
    test/crop_test.cpp \
    gui/crop_dialog.cpp

HEADERS  += gui/mainwindow.h \
    model/test_klasse.h \
    model/tool.h \
    model/processing_interface.h \
    model/image_processing_unit.h \
    model/image_tool.h \
    model/tool_blur.h \
    model/image_wrapper.h \
    model/image_statistics.h \
    model/ccimp_vector.h\
    model/data_key_value_container.h\
    model/parameters.h \
    model/parameter_using_colors.h \
    model/parameter_using_coordiantes.h \
    model/parameter_using_slider.h \
    model/instantiate_tools.h \
    test/guitest.h \
    test/controllertest.h \
    test/observertest.h \
    model/listen_for_image_change.h \
    lib.h \
    gui/slider_dialog.h \
    test/crop_test.h \
    gui/crop_dialog.h

FORMS    += gui/mainwindow.ui \
    gui/crop_dialog.ui

RESOURCES += \
    ../res/resources.qrc

ICON += \
    ../res/ico/appico/CCIMP.ico

CONFIG += c++11

#For ImageMagick

#########################################################################################################################
#
# ImageMagick
#
#
# Det som er kommentert vekk er kun eksempel kan spares dersom vi får problem seinere
#########################################################################################################################



#Kompilator flagger som sendes videre til g++
QMAKE_CXXFLAGS += `Magick++-config --cppflags --cxxflags --ldflags --libs`

#####################################################################
#Her er linkinking av delte .so biblioteker og .h filer for linux
#####################################################################
#VIKTIG!!! før kompilering kjør ./configure script med følgende flagger: --enable-shared --with-modules
#For å kompilere moduler kan det være nødvendig med ldtl bibliotek (jeg hadde den ikke) dersom den eller annen
#bibliotek mangler kommmer configure til å stoppe.
#Jeg installerte følgende pakker (fedora) for å få ldtl til å fungere: libtool-ltdl libtool-ltdl-devel og mingw64-libltdl
unix:!macx: LIBS += /usr/local/lib/libMagick++-6.Q16.so
unix:!macx: INCLUDEPATH += /usr/local/include/ImageMagick-6
unix:!macx: DEPENDPATH += /usr/local/lib/ImageMagick-6.9.1/
#####################################################################

macx: LIBS += /opt/local/lib/libMagick++-6.Q16.5.dylib
macx: INCLUDEPATH += /opt/local/include/ImageMagick-6
macx: DEPENDPATH += /opt/local/lib/ImageMagick-6.9.0

#LIBS += /opt/local/lib/libMagick++-6.Q16.5.dylib
#INCLUDEPATH += /opt/local/include/ImageMagick-6
#DEPENDPATH += /opt/local/lib/ImageMagick-6.9.0
