#ifndef LISTEN_FOR_IMAGE_CHANGE_H
#define LISTEN_FOR_IMAGE_CHANGE_H

#include <QImage>
#include "image_tool.h"


class listen_for_image_change
{
public:
    listen_for_image_change();
    ~listen_for_image_change();

    virtual void on_clicked_tool(image_tool* t) = 0; //When clicked to open a tool from GUI
    virtual void on_new_image(QImage& img) = 0;     //When new image is opened
    virtual void undo_last_command() = 0;           //When undo-button was pressed
    virtual void redo_last_command() = 0;           //When redo-button was pressed
};

#endif // LISTEN_FOR_IMAGE_CHANGE_H
