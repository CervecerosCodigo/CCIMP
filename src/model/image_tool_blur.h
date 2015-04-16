#ifndef IMAGE_TOOL_BLUR_H
#define IMAGE_TOOL_BLUR_H

#include "image_tool.h"

class image_tool_blur : public image_tool
{
public:
    image_tool_blur();
    ~image_tool_blur();

    void draw();
    void undo();
    void update();
    void clear();
};

#endif // IMAGE_TOOL_BLUR_H
