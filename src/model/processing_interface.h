#ifndef PROCESSING_INTERFACE_H
#define PROCESSING_INTERFACE_H

#include "model/image_tool.h"

class processing_interface
{
public:
    processing_interface();
    ~processing_interface();
    virtual void register_tool(image_tool* t) = 0;
};

#endif // PROCESSING_INTERFACE_H
