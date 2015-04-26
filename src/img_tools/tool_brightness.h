#ifndef TOOL_BRIGHTNESS_H
#define TOOL_BRIGHTNESS_H

#include "img_tools/tool.h" //base klasse
#include "img_tools/image_tool.h" //interface til baseklasse
#include "parameters/using_slider.h"
#include "parameters/using_coordinates.h"

class tool_brightness : public tool
{
public:
    using tool::tool;

    void execute(Magick::Image &img) override;
};

#endif // TOOL_BRIGHTNESS_H
