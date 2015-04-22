#ifndef IMAGE_PROCESSING_UNIT_H
#define IMAGE_PROCESSING_UNIT_H

#include "model/processing_interface.h"
#include "model/listen_for_image_change.h"
#include "image_wrapper.h"
#include <vector>
#include "ccimp_vector.h"
#include <iostream>
#include <QImage>
#include <QColor>

#include "gui/mainwindow.h"

class image_processing_unit : public processing_interface, public listen_for_image_change
{

    MainWindow& gui_mw;
    ccimp_vector<image_tool*> tools;         //holds all the tools, set by register_tool(image_tool* t)
    //ccimp_vector<image_wrapper> open_images; //holds all images, wrapped in a container


    image_tool* selected_tool;              //the selected tool from GUI

public:
    image_processing_unit(MainWindow&);
    ~image_processing_unit();

    void register_tool(image_tool* t) override; //from processing_interface
    void on_image_change(QImage& img) override; //from listen_for_image_change
    //void open_new_image(QImage img);        //when opening image from GUI

    void set_image_listener_on_gui();
};

#endif // IMAGE_PROCESSING_UNIT_H
