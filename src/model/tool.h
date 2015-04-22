#ifndef TOOL_H
#define TOOL_H

#include "model/image_processing_unit.h"
#include "model/processing_interface.h"
#include "model/image_tool.h"

#include <iostream>



class tool : image_tool
{
    std::string type;
    processing_interface* processing;

public:

    tool(processing_interface* pro, parameters* para, std::string tool_type);
    virtual ~tool();


    void execute(QImage& img) override; //image_tool

};

#endif // TOOL_H
