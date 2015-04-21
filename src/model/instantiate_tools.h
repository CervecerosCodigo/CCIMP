#ifndef INSTANTIATE_TOOLS_H
#define INSTANTIATE_TOOLS_H

#include "model/processing_interface.h"
#include "model/parameters.h"
#include "model/parameter_using_colors.h"
#include "model/parameter_using_coordiantes.h"
#include "model/parameter_using_slider.h"

#include "model/tool.h"
#include "tool_blur.h"

class instantiate_tools
{
    processing_interface* process;

    tool* blur;

    void create_tools_to_be_used();

public:
    instantiate_tools(processing_interface* p);
    ~instantiate_tools();

};

#endif // INSTANTIATE_TOOLS_H
