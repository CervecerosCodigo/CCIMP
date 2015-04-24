#include "crop_tool.h"

//crop_tool::crop_tool()
//{

//}

//crop_tool::~crop_tool()
//{

//}



Image& crop_tool::crop_image(const Image& img, std::vector<int> crop_parm)
{
    this->image = img;

    image.crop(Geometry(crop_parm[0],crop_parm[1],
            crop_parm[2],crop_parm[3]));
    return image;
}



