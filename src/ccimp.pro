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
    img_tools/tool.cpp \
    img_tools/image_tool.cpp \
    img_tools/tool_blur.cpp \
    controller/image_wrapper.cpp \
    controller/image_statistics.cpp \
    test/test_lab.cpp \
    parameters/using_slider.cpp \
    test/crop_test.cpp \
    gui/crop_dialog.cpp \
    gui/brightness_dialog.cpp \
    img_tools/img_obj_converter.cpp \
    img_tools/tool_crop.cpp \
    controller/controller.cpp \
    img_tools/build_tools.cpp \
    parameters/using_colors.cpp \
    parameters/using_coordinates.cpp \
    gui/blur_dialog.cpp \
    img_tools/tool_brightness.cpp \
    gui/contrast_dialog.cpp \
    img_tools/tool_contrast.cpp \
    img_tools/tool_rotate.cpp \
    gui/rotate_dialog.cpp \
    gui/color_balance_dialog.cpp \
    img_tools/tool_color_balance.cpp \
    gui/about_dialog.cpp \
    gui/encipher_dialaog.cpp \
    lib/err_strings.cpp \
    parameters/using_text.cpp \
    img_tools/tool_secure.cpp \
    lib/set_look_and_feel.cpp \
    gui/sharpness_dialog.cpp \
    parameters/using_no_parameters.cpp \
    img_tools/tool_auto_gamma.cpp \
    gui/auto_gamma_dialog.cpp \
    img_tools/tool_sharpness.cpp \
    gui/auto_level_dialog.cpp \
    img_tools/tool_auto_level.cpp


HEADERS  += gui/mainwindow.h \
    img_tools/tool.h \
    img_tools/image_tool.h \
    img_tools/tool_blur.h \
    controller/image_wrapper.h \
    controller/image_statistics.h \
    controller/ccimp_vector.h\
    controller/data_key_value_container.h\
    parameters/parameters.h \
    lib.h \
    test/crop_test.h \
    gui/crop_dialog.h \
    gui/brightness_dialog.h \
    img_tools/img_obj_converter.h \
    img_tools/tool_crop.h \
    controller/controller.h \
    controller/controller_iface.h \
    img_tools/build_tools.h \
    parameters/using_slider.h \
    parameters/using_colors.h \
    parameters/using_coordinates.h \
    controller/event_listener.h \
    controller/callback_iface.h \
    gui/blur_dialog.h \
    gui/ccimp_dialog.h \
    img_tools/tool_brightness.h \
    gui/contrast_dialog.h \
    img_tools/tool_contrast.h \
    img_tools/tool_rotate.h \
    gui/rotate_dialog.h \
    gui/color_balance_dialog.h \
    img_tools/tool_color_balance.h \
    gui/about_dialog.h \
    gui/encipher_dialaog.h \
    controller/error_listener.h \
    controller/callback_error_iface.h \
    lib/err_strings.h \
    parameters/using_text.h \
    img_tools/tool_secure.h \
    lib/set_look_and_feel.h \
    gui/sharpness_dialog.h \
    parameters/using_no_parameters.h \
    img_tools/tool_auto_gamma.h \
    gui/auto_gamma_dialog.h \
    img_tools/tool_sharpness.h \
    gui/auto_level_dialog.h \
    img_tools/tool_auto_level.h


FORMS    += gui/mainwindow.ui \
    gui/crop_dialog.ui \
    gui/brightness_dialog.ui \
    gui/blur_dialog.ui \
    gui/contrast_dialog.ui \
    gui/rotate_dialog.ui \
    gui/color_balance_dialog.ui \
    gui/about_dialog.ui \
    gui/encipher_dialaog.ui \
    gui/sharpness_dialog.ui \
    gui/auto_gamma_dialog.ui \
    gui/auto_level_dialog.ui


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
