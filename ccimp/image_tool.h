#ifndef IMAGE_TOOL_H
#define IMAGE_TOOL_H

#include <QImage>

class image_tool
{
private:
    int w;
    int h;
    QImage& orig_image;
    QImage& result_image;

public:
    image_tool();
    virtual ~image_tool();

    void set_image(QImage& img);
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clear() = 0;

};

#endif // IMAGE_TOOL_H
