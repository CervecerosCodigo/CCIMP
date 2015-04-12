#ifndef TOOL_BLUR_H
#define TOOL_BLUR_H

#include "model/image_tool.h"

class tool_blur : public image_tool
{
public:

    tool_blur();
    ~tool_blur();

    void set_image(QImage& img);
    void draw();
    void update();
    void clear();
};

#endif // TOOL_BLUR_H
