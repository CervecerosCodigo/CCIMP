#ifndef IMAGE_TOOL_H
#define IMAGE_TOOL_H

#include<QImage>

class image_tool
{
public:
    image_tool();
    ~image_tool();

    virtual void execute(QImage& img) = 0;
};

#endif // IMAGE_TOOL_H
