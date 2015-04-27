#include "tool_blur.h"


void tool_blur::execute(Magick::Image& img){
    using_slider* param = (using_slider*) get_para();
    qDebug() << "Slider 1:" << param->get_slider_val(0)
             << "Slider 2:" << param->get_slider_val(1);
    img.blur(
                param->get_slider_val(0)*0.1,
                param->get_slider_val(1)*0.1);
}
