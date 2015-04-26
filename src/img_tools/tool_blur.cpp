#include "tool_blur.h"


void tool_blur::execute(Magick::Image& img){
    qDebug() << "Blur tool sin execute ran";
    using_slider* param = (using_slider*) get_para();
    img.blur(param->get_slider_val()*10.0);
}
