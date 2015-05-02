#ifndef TOOL_SHARPNESS_H
#define TOOL_SHARPNESS_H

#include "img_tools/tool.h"
#include "img_tools/image_tool.h"
#include "parameters/using_slider.h"

class tool_sharpness : public tool
{
public:
    using tool::tool;

    void execute(Magick::Image& img) override;
};

#endif // TOOL_SHARPNESS_H
