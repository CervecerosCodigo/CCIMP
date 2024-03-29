#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "controller/controller_iface.h"
#include "controller/event_listener.h"
#include "callback_iface.h"
#include "image_wrapper.h"
#include <vector>
#include "ccimp_vector.h"
#include <iostream>
#include <QImage>
#include <QColor>
#include "lib.h"
#include "error_listener.h"
#include "gui/mainwindow.h"
#include "lib/err_strings.h"
#include <memory>

class controller : public controller_iface, public event_listener, public error_listener
{

    MainWindow& gui_mw;

    image_wrapper current_image;           //current image

    callback_iface* callback;

public:
    controller(MainWindow&);
    ~controller();


    void register_tool(image_tool* t) override; //from controller_iface

    //functions below are from the event_listener interface
    void on_new_image(QImage& img) override; //from event_listener
    void on_clicked_tool(image_tool* t) override;
    void updating_image() override;
    void finished() override;
    void canceled() override;
    void undo_last_command() override;
    void redo_last_command() override;

    //error_listener overrides
    void on_exception_occured(TOOLIDENT, ERRORTYPE) override;
};

#endif // CONTROLLER_H
