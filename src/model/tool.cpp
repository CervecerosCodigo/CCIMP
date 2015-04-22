#include "tool.h"

tool::tool(processing_interface* pro, parameters* para, std::string tool_type) : image_tool(para), processing{pro}, type{tool_type}
{
    processing->register_tool(this);
}

tool::~tool()
{

}


void tool::execute(QImage& img){
    //std::cout << "Kjører execute" << std::endl;
}

