#ifndef TOOL_BLUR_H
#define TOOL_BLUR_H

#include "img_tools/tool.h"
#include "img_tools/image_tool.h"
#include "parameters/using_slider.h"
#include <QDebug>

class tool_blur : public tool
{
public:
    using tool::tool;

    void execute(Magick::Image& img) override;
};

#endif // TOOL_BLUR_H
