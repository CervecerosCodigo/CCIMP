#include "instantiate_tools.h"

instantiate_tools::instantiate_tools(processing_interface* p): process{p}
{
    create_tools_to_be_used();
}

instantiate_tools::~instantiate_tools()
{

    delete blur;

}


void instantiate_tools::create_tools_to_be_used(){

    blur = new tool_blur(process, new parameter_using_slider(), TOOLIDENT::BLUR);
}
