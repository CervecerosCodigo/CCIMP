#include "tool_blur.h"

tool_blur::tool_blur(controller_iface* cont, parameters* para, TOOLIDENT tool_ident) : tool(cont, para, tool_ident)
{

}

tool_blur::~tool_blur()
{

}



void tool_blur::execute(Magick::Image& img){
    std::cout << "Kjører execute" << std::endl;
}
