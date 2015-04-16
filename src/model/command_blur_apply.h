#ifndef COMMAND_BLUR_APPLY_H
#define COMMAND_BLUR_APPLY_H

#include "command.h"

#include "image_tool.h"

class command_blur_apply : public command
{
public:
    command_blur_apply(image_tool* t);
    virtual ~command_blur_apply();
    void execute();

};




#endif // COMMAND_BLUR_APPLY_H
