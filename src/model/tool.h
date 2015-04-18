#ifndef TOOL_H
#define TOOL_H

#include "model/image_processing_unit.h"
#include "model/processing_interface.h"
#include "model/image_tool.h"

#include <iostream>

class tool : image_tool
{

    processing_interface* processing;

public:

    tool(processing_interface* p);
    virtual ~tool();

    void execute() override; //image_tool
};

#endif // TOOL_H
