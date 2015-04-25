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
    //using_coordinates* param = (using_coordinates*) get_param();

    img.crop(Magick::Geometry(
                 param->get_width(),
                 param->get_height(),
                 param->get_x_axis(),
                 param->get_y_axis()));

//    image.crop(Magick::Geometry(crop_parm[0],crop_parm[1],
//            crop_parm[2],crop_parm[3]));

}
