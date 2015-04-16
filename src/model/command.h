#ifndef COMMAND_H
#define COMMAND_H

#include "image_tool.h"


class command
{

    image_tool* tool;

public:
    command(image_tool* t);
    virtual ~command();

    virtual void execute() = 0;
    void set_image(QImage img);
};




#endif // COMMAND_H
