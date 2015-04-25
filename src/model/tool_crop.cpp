#include "tool_crop.h"

tool_crop::tool_crop(processing_interface* pro, parameters* para, TOOLIDENT tool_ident) : tool(pro, para, tool_ident)
{

}

tool_crop::~tool_crop()
{

}

void tool_crop::execute(Magick::Image& img){
    std::cout << "Kjører execute i crop" << std::endl;

}
