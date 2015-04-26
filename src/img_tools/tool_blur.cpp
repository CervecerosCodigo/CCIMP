#include "tool_blur.h"

tool_blur::tool_blur(controller_iface* cont, parameters* para, TOOLIDENT tool_ident) : tool(cont, para, tool_ident)
{

}

tool_blur::~tool_blur()
{

}



void tool_blur::execute(Magick::Image& img){
    qDebug() << "Blur tool sin execute ran";
    using_slider* param = (using_slider*) get_para();
    img.blur(param->get_slider_val());
}
