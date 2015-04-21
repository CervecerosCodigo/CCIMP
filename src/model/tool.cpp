#include "tool.h"

tool::tool(processing_interface* pro, parameters* para) : image_tool(para), processing{pro}
{
    processing->register_tool(this);
}

tool::~tool()
{

}


void tool::execute(QImage& img){
//    std::cout << "Kjører execute" << std::endl;
}

