#ifndef TOOL_BLUR_H
#define TOOL_BLUR_H

#include "img_tools/tool.h"
#include "model/tool.h"
#include "model/image_tool.h"
#include "parameters/using_slider.h"
#include <QDebug>

class tool_blur : public tool
{
public:
    tool_blur(controller_iface* cont, parameters* para, TOOLIDENT tool_ident);
    ~tool_blur();

    void execute(Magick::Image& img) override;
};

#endif // TOOL_BLUR_H
