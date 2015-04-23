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
    test/crop_test.cpp \
    gui/slider_dialog.cpp

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
    gui/slider_dialog.h

FORMS    += gui/mainwindow.ui

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
#LIBS += -L/usr/lib64/ -lMagick++-6 -lMagickWand-6 -lMagickCore-6


#Dersom den over ikke fungrer og det kommer meldinger i stil med ad finner ikke Magick++ osv da bruk disse under
#LIBS +=     /usr/lib64/libMagick++-6.Q16.so \
#            /usr/lib64/libMagickCore-6.Q16.so \
#            /usr/lib64/libMagickWand-6.Q16.so

#INCLUDEPATH +=  /usr/include/ImageMagick-6/
#DEPENDPATH +=   /usr/lib64/ImageMagick-6.8.8/


#Her er for Linux x86_64 versjonen
#unix:!macx: LIBS += -L$$PWD/../build-ccimp-Desktop-Debug/lib/ImageMagick/linux_x86_64/lib64/ -lMagick++-6 -lMagickWand-6 -lMagickCore-6

#unix:!macx: LIBS += -L$$PWD/../../build-ccimp-Desktop-Debug/lib/ImageMagick/linux_x86_64/lib64/libMagick++-6.Q16.so \
#                    -L$$PWD/../../build-ccimp-Desktop-Debug/lib/ImageMagick/linux_x86_64/lib64/libMagickCore-6.Q16.so \
#                    -L$$PWD/../../build-ccimp-Desktop-Debug/lib/ImageMagick/linux_x86_64/lib64/libMagickWand-6.Q16.so
unix:!macx: LIBS += ../build-ccimp-Desktop-Debug/lib/ImageMagick/linux_x86_64/lib64/libMagick++-6.Q16.so \
                    ../build-ccimp-Desktop-Debug/lib/ImageMagick/linux_x86_64/lib64/libMagickCore-6.Q16.so \
                    ../build-ccimp-Desktop-Debug/lib/ImageMagick/linux_x86_64/lib64/libMagickWand-6.Q16.so



#Her kommer versjon for mac, ennå ikke testet
#macx: LIBS += -L$$PWD/../build-ccimp-Desktop-Debug/lib/ImageMagick/mac_os_x_darwin14_x86_64/lib/libMagick++-6.Q16.dylib \
#                    -L$$PWD/../build-ccimp-Desktop-Debug/lib/ImageMagick/mac_os_x_darwin14_x86_64/lib/libMagickCore-6.Q16.dylib \
#                    -L$$PWD/../build-ccimp-Desktop-Debug/lib/ImageMagick/mac_os_x_darwin14_x86_64/lib/libMagickWand-6.Q16.dylib


#Denne viser til h filer for bibliotekt, borde være samme systemuavhengig
#INCLUDEPATH += $$PWD/../../build-ccimp-Desktop-Debug/lib/ImageMagick/linux_x86_64/includepath/ImageMagick-6/
#Her ligge so filer. Finner ikke samme i mac releasen. Hvis vi ikke får det til å fungere må vi kompielre disse på mac.
#DEPENDPATH += $$PWD/../../build-ccimp-Desktop-Debug/lib/ImageMagick/linux_x86_64/lib64/ImageMagick-6.8.8/
INCLUDEPATH += ../build-ccimp-Desktop-Debug/lib/ImageMagick/linux_x86_64/includepath/ImageMagick-6
#Her ligge so filer. Finner ikke samme i mac releasen. Hvis vi ikke får det til å fungere må vi kompielre disse på mac.
DEPENDPATH += ../build-ccimp-Desktop-Debug/lib/ImageMagick/linux_x86_64/lib64/ImageMagick-6.8.8


#Kompilator flagger som sendes videre til g++
QMAKE_CXXFLAGS += `Magick++-config --cxxflags --cppflags` -O2 `Magick++-config --ldflags --libs`


