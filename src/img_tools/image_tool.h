#ifndef IMAGE_TOOL_H
#define IMAGE_TOOL_H

//#include<Image>
#include "Magick++.h"
#include "parameters/parameters.h"
#include "controller/error_listener.h"

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

public:
    //Trot ikke at disse behøvs, de er definiert i subklassen også.
//    error_listener* err_listener;
//    bool is_error_listener_set = false;

    virtual void set_error_listener(error_listener *e)=0;
};

#endif // IMAGE_TOOL_H
