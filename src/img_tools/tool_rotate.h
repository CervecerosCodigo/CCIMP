#ifndef TOOL_ROTATE_H
#define TOOL_ROTATE_H

#include "img_tools/tool.h"
#include "img_tools/image_tool.h"
#include "parameters/using_coordinates.h"

class tool_rotate : public tool
{
public:
    using tool::tool;

    void execute(Magick::Image& img) override;
};

#endif // TOOL_ROTATE_H
