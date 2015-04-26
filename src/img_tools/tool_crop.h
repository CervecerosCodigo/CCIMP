#ifndef TOOL_CROP_H
#define TOOL_CROP_H

#include "img_tools/tool.h"
#include "img_tools/image_tool.h"
#include "parameters/using_coordinates.h"
#include <QDebug>

class tool_crop : public tool
{
public:
    using tool::tool;

    void execute(Magick::Image& img) override;
};

#endif // TOOL_CROP_H
