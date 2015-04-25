#include "tool_crop.h"

tool_crop::tool_crop(controller_iface* cont, parameters* para, TOOLIDENT tool_ident) : tool(cont, para, tool_ident)
{

}

tool_crop::~tool_crop()
{

}

void tool_crop::execute(Magick::Image& img){
    std::cout << "Kjører execute i crop" << std::endl;

}
