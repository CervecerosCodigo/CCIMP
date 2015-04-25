#ifndef GUI_LISTENER_H
#define GUI_LISTENER_H

#include <QImage>
#include "image_tool.h"


class gui_listener
{
public:
    gui_listener(){}
    ~gui_listener(){}

    virtual void on_clicked_tool(image_tool* t) = 0; //When clicked to open a tool from GUI
    virtual void execute_tool_on_image() = 0;
    virtual void on_new_image(QImage& img) = 0;     //When new image is opened
    virtual void undo_last_command() = 0;           //When undo-button was pressed
    virtual void redo_last_command() = 0;           //When redo-button was pressed
};

#endif // GUI_LISTENER_H
