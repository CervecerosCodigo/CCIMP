#include "img_tools/build_tools.h"

build_tools::build_tools(controller_iface* p): control{p}
{
    create_tools_to_be_used();
}

build_tools::~build_tools()
{
    //delete brightness, contrast, blur, crop;
}


void build_tools::create_tools_to_be_used(){

    brightness = new tool_brightness(control, new using_slider(), TOOLIDENT::BRIGTHEN);
    contrast = new tool_contrast(control, new using_slider(), TOOLIDENT::CONTRAST);
    blur = new tool_blur(control, new using_slider(), TOOLIDENT::BLUR);
    crop = new tool_crop(control, new using_coordinates(), TOOLIDENT::CROP);
}
