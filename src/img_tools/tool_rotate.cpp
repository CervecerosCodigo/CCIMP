#include "tool_rotate.h"

void tool_rotate::execute(Magick::Image &img)
{
    using_coordinates* param = (using_coordinates*) get_para();
    img.rotate(param->get_angle());
}
