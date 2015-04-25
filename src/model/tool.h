#ifndef TOOL_H
#define TOOL_H

#include "lib.h"
#include "model/image_processing_unit.h"
#include "model/processing_interface.h"
#include "model/image_tool.h"

#include <iostream>



class tool : image_tool
{
    //TOOLIDENT tool_identifier;
    processing_interface* processing;

public:

    tool(processing_interface* pro, parameters* para, TOOLIDENT tool_ident);
    virtual ~tool();


    void execute(QImage& img) override; //image_tool

};

#endif // TOOL_H
