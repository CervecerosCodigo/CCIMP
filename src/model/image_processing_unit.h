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
#include "lib.h"

#include "gui/mainwindow.h"

class image_processing_unit : public processing_interface, public listen_for_image_change
{

    MainWindow& gui_mw;
    ccimp_vector<image_tool*> tools;         //holds all the tools, set by register_tool(image_tool* t)
    //ccimp_vector<image_wrapper> open_images; //holds all images, wrapped in a container

    image_wrapper* current_image;           //current image
    image_tool* selected_tool;              //the selected tool from GUI

    NUMTOOLS num_tools;

public:
    image_processing_unit(MainWindow&);
    ~image_processing_unit();

    void register_tool(image_tool* t) override; //from processing_interface
    void on_image_change(QImage& img) override; //from listen_for_image_change
    void undo_last_command() override;
    void redo_last_command() override;


};

#endif // IMAGE_PROCESSING_UNIT_H
