#ifndef TOOL_CROP_H
#define TOOL_CROP_H

#include "model/tool.h"
#include "model/image_tool.h"
#include "parameters/using_coordinates.h"
#include <QDebug>

class tool_crop : public tool
{
public:
    tool_crop(controller_iface* cont, parameters* para, TOOLIDENT tool_ident);
    ~tool_crop();

    //parameters* get_param();
    void execute(Magick::Image& img) override;
};

#endif // TOOL_CROP_H
