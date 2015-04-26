#include "tool_brightness.h"

void tool_brightness::execute(Magick::Image &img)
{

    using_slider* param = (using_slider*) get_para();

    img.brightnessContrast(param->get_slider_val()*1.0, 0.0);
}
