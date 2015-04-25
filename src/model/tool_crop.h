#ifndef TOOL_CROP_H
#define TOOL_CROP_H

#include "model/tool.h"

class tool_crop : public tool
{
public:
    tool_crop(processing_interface* pro, parameters* para, TOOLIDENT tool_ident);
    ~tool_crop();

    void execute(Magick::Image& img) override;
};

#endif // TOOL_CROP_H
