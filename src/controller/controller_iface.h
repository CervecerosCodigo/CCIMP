#ifndef CONTROLLER_IFACE_H
#define CONTROLLER_IFACE_H

#include "img_tools/image_tool.h"

class controller_iface
{
public:
    controller_iface(){}
    virtual ~controller_iface(){}
    virtual void register_tool(image_tool* t) = 0;
};

#endif // CONTROLLER_IFACE_H
