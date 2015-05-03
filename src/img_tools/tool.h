#ifndef TOOL_H
#define TOOL_H

#include "lib.h"
#include "controller/controller_iface.h"
#include "img_tools/image_tool.h"
#include <QDebug>
#include <iostream>


class tool : public image_tool
{

    controller_iface* control;

public:

    tool(controller_iface* cont, parameters* para, TOOLIDENT tool_ident);
    virtual ~tool();

    inline parameters* get_para(){return get_param();}
    void execute(Magick::Image& img) override; //image_tool

    error_listener* err_listener;
    //bool is_error_listener_set = false;

    inline void set_error_listener(error_listener *e) override{
        //is_error_listener_set = true;
        err_listener = e;
    }

};

#endif // TOOL_H
