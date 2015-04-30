#ifndef TOOL_SECURE_H
#define TOOL_SECURE_H

#include "img_tools/tool.h"
#include "img_tools/image_tool.h"
#include "parameters/using_text.h"
#include <QDebug>

class tool_secure : public tool
{
public:
    using tool::tool;

    void execute(Magick::Image& img) override;
};

#endif // TOOL_SECURE_H
