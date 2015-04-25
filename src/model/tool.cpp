#include "tool.h"

tool::tool(controller_iface* cont, parameters* para, TOOLIDENT tool_ident) : image_tool(para, tool_ident), control{cont}
{
    control->register_tool(this);
}

tool::~tool()
{

}


void tool::execute(Magick::Image& img){
    //std::cout << "Kjører execute" << std::endl;
}

