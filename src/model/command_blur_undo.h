#ifndef COMMAND_BLUR_UNDO
#define COMMAND_BLUR_UNDO


#include "command.h"
#include "image_tool_blur.h"


class command_blur_undo : public command
{
public:
    command_blur_undo(image_tool* t);
    ~command_blur_undo();
    void execute();

};




#endif // COMMAND_BLUR_UNDO

