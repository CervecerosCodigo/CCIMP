#ifndef TOOL_SCALE_H
#define TOOL_SCALE_H

#include "img_tools/tool.h"
#include "img_tools/image_tool.h"
#include "parameters/using_coordinates.h"
#include <QDebug>
#include <QString>

class tool_scale : public tool
{
public:
    using tool::tool;

    void execute(Magick::Image& img) override;

};

#endif // TOOL_SCALE_H
