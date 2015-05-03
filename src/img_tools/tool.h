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

    error_listener* err_listener;

    void execute(Magick::Image& img) override; //image_tool


    inline parameters* get_para(){return get_param();}

    inline void set_error_listener(error_listener *e) override{
        err_listener = e;
    }

};

#endif // TOOL_H
