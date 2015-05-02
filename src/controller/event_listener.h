#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

#include <QImage>
#include "img_tools/image_tool.h"
#include "callback_iface.h"

class event_listener
{
public:
    event_listener(){}
    virtual ~event_listener(){}

    virtual void on_clicked_tool(image_tool* t) = 0; //When clicked to open a tool from GUI
    virtual void updating_image() = 0;   //one of three functions called when editing.
    virtual void finished() = 0;    //one of three functions called when editing.
    virtual void canceled() = 0;    //one of three functions called when editing.
    virtual void on_new_image(QImage& img) = 0;     //When new image is opened
    virtual void undo_last_command() = 0;           //When undo-button was pressed
    virtual void redo_last_command() = 0;           //When redo-button was pressed

};

#endif // EVENT_LISTENER_H
