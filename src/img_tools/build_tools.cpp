#include "img_tools/build_tools.h"

build_tools::build_tools(controller_iface* p): control{p}
{
    create_tools_to_be_used();
}

build_tools::~build_tools()
{
    delete blur;
    delete crop;
    delete brightness;
    delete contrast;
    delete rotate;
    delete color_balance;
    delete secure_tool;
    delete sharpen_tool;
    delete control;

}


void build_tools::create_tools_to_be_used(){

    brightness = new tool_brightness(control, new using_slider(), TOOLIDENT::BRIGTHEN);
    contrast = new tool_contrast(control, new using_slider(), TOOLIDENT::CONTRAST);
    blur = new tool_blur(control, new using_slider(2), TOOLIDENT::BLUR);
    crop = new tool_crop(control, new using_coordinates(), TOOLIDENT::CROP);
    rotate = new tool_rotate(control, new using_coordinates(), TOOLIDENT::ROTATE);
    color_balance = new tool_color_balance(control, new using_slider(3), TOOLIDENT::COL);
    secure_tool = new tool_secure(control, new using_text(), TOOLIDENT::SECURE);
    sharpen_tool = new tool_sharpness(control, new using_slider(2), TOOLIDENT::SHARPEN);
}
