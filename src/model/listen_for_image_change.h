#ifndef LISTEN_FOR_IMAGE_CHANGE_H
#define LISTEN_FOR_IMAGE_CHANGE_H

#include <QImage>

class listen_for_image_change
{
public:
    listen_for_image_change();
    ~listen_for_image_change();

    virtual void on_image_change(QImage& img) = 0;
};

#endif // LISTEN_FOR_IMAGE_CHANGE_H
