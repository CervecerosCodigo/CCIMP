#ifndef TOOL_CROP_H
#define TOOL_CROP_H

#include "model/tool.h"

class tool_crop : public tool
{
public:
    tool_crop(controller_iface* cont, parameters* para, TOOLIDENT tool_ident);
    ~tool_crop();

    void execute(Magick::Image& img) override;
};

#endif // TOOL_CROP_H
