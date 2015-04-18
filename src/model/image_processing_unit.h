#ifndef IMAGE_PROCESSING_UNIT_H
#define IMAGE_PROCESSING_UNIT_H

#include "processing_interface.h"

class image_processing_unit : public processing_interface
{
public:
    image_processing_unit();
    ~image_processing_unit();

    void register_tool();
};

#endif // IMAGE_PROCESSING_UNIT_H
