#ifndef TOOL_CONTRAST_H
#define TOOL_CONTRAST_H

#include "img_tools/tool.h" //base klasse
#include "img_tools/image_tool.h" //interface til baseklasse
#include "parameters/using_slider.h"
#include "parameters/using_coordinates.h"

class tool_contrast : public tool
{
public:
    using tool::tool;

    void execute(Magick::Image &img) override;
};

#endif // TOOL_CONTRAST_H
