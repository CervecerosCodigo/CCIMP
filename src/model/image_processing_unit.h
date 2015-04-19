#ifndef IMAGE_PROCESSING_UNIT_H
#define IMAGE_PROCESSING_UNIT_H

#include "processing_interface.h"
#include <vector>
#include <iostream>
#include <QImage>

class image_processing_unit : public processing_interface
{

    std::vector<image_tool*> tools;
    QImage image;

public:
    image_processing_unit();
    ~image_processing_unit();

    void register_tool(image_tool* t);
};

#endif // IMAGE_PROCESSING_UNIT_H
