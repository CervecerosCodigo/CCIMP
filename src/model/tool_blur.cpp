#include "tool_blur.h"

tool_blur::tool_blur(processing_interface* pro, parameters* para, TOOLIDENT tool_ident) : tool(pro, para, tool_ident)
{

}

tool_blur::~tool_blur()
{

}



void tool_blur::execute(Magick::Image& img){
    std::cout << "Kjører execute" << std::endl;
}
