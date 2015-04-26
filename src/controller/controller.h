#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/controller_iface.h"
#include "model/event_listener.h"
#include "callback_iface.h"
#include "image_wrapper.h"
#include <vector>
#include "ccimp_vector.h"
#include <iostream>
#include <QImage>
#include <QColor>
#include "lib.h"

#include "gui/mainwindow.h"

class controller : public controller_iface, public event_listener
{

    MainWindow& gui_mw;
    //ccimp_vector<image_tool*> tools;         //holds all the tools, set by register_tool(image_tool* t)
    //ccimp_vector<image_wrapper> open_images; //holds all images, wrapped in a container

    image_wrapper* current_image;           //current image
    image_tool* selected_tool;              //the selected tool from GUI


public:
    controller(MainWindow&);
    ~controller();

    void set_updated_image(QImage* updated_image);

    void register_tool(image_tool* t) override; //from controller_iface

    void on_new_image(QImage& img) override; //from event_listener
    void on_clicked_tool(image_tool* t) override;
    void execute_tool_on_image(callback_iface* callback) override;
    void undo_last_command() override;
    void redo_last_command() override;

};

#endif // CONTROLLER_H
