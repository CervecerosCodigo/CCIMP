#include "tool_blur.h"

tool_blur::tool_blur(processing_interface* pro, parameters* para) : tool(pro, para)
{

}

tool_blur::~tool_blur()
{

}



void tool_blur::execute(QImage& img){
    std::cout << "Kjører execute" << std::endl;
}
