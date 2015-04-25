#ifndef IMAGE_TOOL_H
#define IMAGE_TOOL_H

//#include<Image>
#include "Magick++.h"
#include "parameters.h"

class image_tool
{
    parameters* param;
    TOOLIDENT tool_identifier;

public:
    image_tool(parameters* p, TOOLIDENT identifier);
    ~image_tool();

    virtual void execute(Magick::Image& img) = 0;

    inline parameters* get_param(){return param;}
    inline TOOLIDENT get_tool_identifier(){return tool_identifier;}
};

#endif // IMAGE_TOOL_H
