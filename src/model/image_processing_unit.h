#ifndef IMAGE_PROCESSING_UNIT_H
#define IMAGE_PROCESSING_UNIT_H

#include "processing_interface.h"
#include "image_wrapper.h"
#include <vector>
#include <iostream>
#include <QImage>


class image_processing_unit : public processing_interface
{

    std::vector<image_tool*> tools;         //holds all the tools, set by register_tool(image_tool* t)
    std::vector<image_wrapper> open_images; //holds all images, wrapped in a container

    image_tool* selected_tool;              //the selected tool from GUI

public:
    image_processing_unit();
    ~image_processing_unit();

    void register_tool(image_tool* t) override; //from processing_interface
    void open_new_image(QImage img);        //when opening image from GUI
};

#endif // IMAGE_PROCESSING_UNIT_H
