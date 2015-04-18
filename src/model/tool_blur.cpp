#include "tool_blur.h"

tool_blur::tool_blur(processing_interface* p) : tool(p)
{

}

tool_blur::~tool_blur()
{

}



void tool_blur::execute(){
    std::cout << "Kjører execute" << std::endl;
}
