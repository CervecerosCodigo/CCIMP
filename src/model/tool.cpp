#include "tool.h"

tool::tool(processing_interface* p) : processing{p}
{
    processing->register_tool(this);
}

tool::~tool()
{

}


void tool::execute(){
//    std::cout << "Kjører execute" << std::endl;
}

