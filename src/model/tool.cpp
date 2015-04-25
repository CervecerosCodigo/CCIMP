#include "tool.h"

tool::tool(processing_interface* pro, parameters* para, TOOLIDENT tool_ident) : image_tool(para, tool_ident), processing{pro}
{
    processing->register_tool(this);
}

tool::~tool()
{

}


void tool::execute(Magick::Image& img){
    //std::cout << "Kjører execute" << std::endl;
}

