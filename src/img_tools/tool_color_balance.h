#ifndef TOOL_COLOR_BALANCE_H
#define TOOL_COLOR_BALANCE_H

#include "img_tools/tool.h"
#include "img_tools/image_tool.h"
#include "parameters/using_slider.h"

class tool_color_balance : public tool
{
public:
    using tool::tool;

    void execute(Magick::Image& img) override;
};

#endif // TOOL_COLOR_BALANCE_H
