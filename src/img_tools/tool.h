#ifndef TOOL_H
#define TOOL_H

#include "lib.h"
#include "model/controller_iface.h"
#include "model/image_tool.h"
#include <QDebug>
#include <iostream>



class tool : image_tool
{
    //TOOLIDENT tool_identifier;
    controller_iface* control;

public:

    tool(controller_iface* cont, parameters* para, TOOLIDENT tool_ident);
    virtual ~tool();

    inline parameters* get_para(){return get_param();}
    void execute(Magick::Image& img) override; //image_tool

};

#endif // TOOL_H
