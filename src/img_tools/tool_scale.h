#ifndef TOOL_SCALE_H
#define TOOL_SCALE_H

#include "img_tools/tool.h"
#include "img_tools/image_tool.h"
#include "parameters/using_slider.h"
#include <QDebug>
#include <QString>

class tool_scale : public tool
{
    int width_initial, height_initial;
    double ratio;
    int width_new, height_new;

public:
    using tool::tool;

    void execute(Magick::Image& img) override;

};

#endif // TOOL_SCALE_H
