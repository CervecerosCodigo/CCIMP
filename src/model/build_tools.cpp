#include "model/build_tools.h"

build_tools::build_tools(controller_iface* p): control{p}
{
    create_tools_to_be_used();
}

build_tools::~build_tools()
{

    delete blur;

}


void build_tools::create_tools_to_be_used(){

    blur = new tool_blur(control, new using_slider(), TOOLIDENT::BLUR);
    crop = new tool_crop(control, new using_coordinates(), TOOLIDENT::CROP);
}
