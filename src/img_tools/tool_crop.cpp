#include "tool_crop.h"

tool_crop::tool_crop(controller_iface* cont, parameters* para, TOOLIDENT tool_ident) : tool(cont, para, tool_ident)
{

}

tool_crop::~tool_crop()
{

}

void tool_crop::execute(Magick::Image& img){
    qDebug() << "running execute in tool";
    using_coordinates* param = (using_coordinates*) get_para();

    img.crop(Magick::Geometry(
                 param->get_width(),
                 param->get_height(),
                 param->get_x_axis(),
                 param->get_y_axis()));

}
