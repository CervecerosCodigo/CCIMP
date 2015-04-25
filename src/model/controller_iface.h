#ifndef CONTROLLER_IFACE_H
#define CONTROLLER_IFACE_H

#include "model/image_tool.h"

class controller_iface
{
public:
    controller_iface(){}
    ~controller_iface(){}
    virtual void register_tool(image_tool* t) = 0;
};

#endif // CONTROLLER_IFACE_H
