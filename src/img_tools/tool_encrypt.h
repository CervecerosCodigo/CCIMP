#ifndef TOOL_ENCRYPT_H
#define TOOL_ENCRYPT_H

#include "img_tools/tool.h"
#include "img_tools/image_tool.h"
#include "parameters/using_coordinates.h"
#include <QDebug>

class tool_encrypt : public tool
{
public:
    using tool::tool;

    void execute(Magick::Image& img) override;

};

#endif // TOOL_ENCRYPT_H
