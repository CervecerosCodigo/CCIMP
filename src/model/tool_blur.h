#ifndef TOOL_BLUR_H
#define TOOL_BLUR_H

#include "model/tool.h"

#include <iostream>

class tool_blur : public tool
{
public:
    tool_blur(processing_interface* pro, parameters* para, TOOLIDENT tool_ident);
    ~tool_blur();

    void execute(QImage& img) override;
};

#endif // TOOL_BLUR_H
