#include "brightness_tool.h"


void brightness_tool::change_brightness(Magick::Image &img, int brght_value)
{
    img.brightnessContrast(brght_value*1.0, 0.0);
}
