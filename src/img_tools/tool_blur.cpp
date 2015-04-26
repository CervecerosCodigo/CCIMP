#include "tool_blur.h"


void tool_blur::execute(Magick::Image& img){
    using_slider* param = (using_slider*) get_para();
    img.blur(param->get_slider_val()*5.0);
}
