#include "img_tools/build_tools.h"

build_tools::build_tools(controller_iface* p): control{p}
{
    create_tools_to_be_used();
}

build_tools::~build_tools()
{


}


void build_tools::create_tools_to_be_used(){

    new tool_brightness(control, new using_slider(), TOOLIDENT::BRIGTHEN);
    new tool_contrast(control, new using_slider(), TOOLIDENT::CONTRAST);
    new tool_blur(control, new using_slider(2), TOOLIDENT::BLUR);
    new tool_crop(control, new using_coordinates(), TOOLIDENT::CROP);
    new tool_rotate(control, new using_coordinates(), TOOLIDENT::ROTATE);
    new tool_color_balance(control, new using_slider(3), TOOLIDENT::COL);
    new tool_secure(control, new using_text(), TOOLIDENT::SECURE);
    new tool_auto_gamma(control, new using_no_parameters(), TOOLIDENT::AUTOGAMMA);
    new tool_sharpness(control, new using_slider(2), TOOLIDENT::SHARPEN);
    new tool_auto_level(control, new using_no_parameters(), TOOLIDENT::AUTOLEVEL);
    new tool_scale(control, new using_slider(), TOOLIDENT::RESIZE);

}
