#include "tool_brightness.h"

void tool_brightness::execute(Magick::Image &img)
{
    qDebug() << "running execute in tool_crop.cpp";
    using_slider* param = (using_slider*) get_para();

    img.brightnessContrast(param->get_slider_val(), 0.0);
}
