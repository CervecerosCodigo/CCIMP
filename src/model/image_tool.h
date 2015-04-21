#ifndef IMAGE_TOOL_H
#define IMAGE_TOOL_H

#include<QImage>
#include "parameters.h"

class image_tool
{
    parameters* param;

public:
    image_tool(parameters* p);
    ~image_tool();

    virtual void execute(QImage& img) = 0;
    //inline void set_param(parameters* p){param = p;}
    inline parameters* get_param(){return param;}

};

#endif // IMAGE_TOOL_H
