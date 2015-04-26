#include "tool_contrast.h"

void tool_contrast::execute(Magick::Image &img)
{

    using_slider* param = (using_slider*) get_para();

    img.brightnessContrast(0.0, param->get_slider_val()*1.0);
}
