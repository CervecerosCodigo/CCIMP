#include "crop_tool.h"


Magick::Image *crop_tool::crop_image(Magick::Image &img, const std::vector<int> &crop_parm)
{
    this->image = img;

    image.crop(Magick::Geometry(crop_parm[0],crop_parm[1],
            crop_parm[2],crop_parm[3]));
    return &image;
}
