#ifndef IMAGE_TOOL_H
#define IMAGE_TOOL_H

#include <QImage>

class image_tool
{
private:
    const QImage* orig_image;
    const QImage* result_image;

public:
    image_tool(){}
    ~image_tool(){}

    void set_image(QImage* img);
    const QImage* return_result();

    virtual void draw() = 0;
    virtual void undo() = 0;
    virtual void update() = 0;
    virtual void clear() = 0;

};

#endif // IMAGE_TOOL_H
