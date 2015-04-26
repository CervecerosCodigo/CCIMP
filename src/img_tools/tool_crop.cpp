#include "tool_crop.h"

void tool_crop::execute(Magick::Image& img){

    using_coordinates* param = (using_coordinates*) get_para();

    img.crop(Magick::Geometry(
                 param->get_width(),
                 param->get_height(),
                 param->get_x_axis(),
                 param->get_y_axis()));

}
