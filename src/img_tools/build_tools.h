#ifndef BUILD_TOOLS_H
#define BUILD_TOOLS_H

#include "controller/controller_iface.h"
#include "parameters/parameters.h"
#include "parameters/using_colors.h"
#include "parameters/using_coordinates.h"
#include "parameters/using_slider.h"

#include "img_tools/tool.h"
#include "tool_blur.h"
#include "tool_crop.h"
#include "tool_brightness.h"

class build_tools
{
    controller_iface* control;

    tool* blur;
    tool* crop;
    tool* brightness;

    void create_tools_to_be_used();

public:
    build_tools(controller_iface* p);
    ~build_tools();

};

#endif // BUILD_TOOLS_H