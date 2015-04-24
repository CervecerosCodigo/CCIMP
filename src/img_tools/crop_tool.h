#ifndef CROP_TOOL_H
#define CROP_TOOL_H

#include <Magick++.h>
#include <vector>

using namespace Magick;

class crop_tool
{
    static crop_tool* instance;
    Magick::Image image;

    crop_tool(){}
    crop_tool(crop_tool const&) = delete;
    void operator=(crop_tool const&) = delete;

public:


    static crop_tool& getInstance(){
        static crop_tool instance;
        return instance;
    }


    Image& crop_image(const Image& image, std::vector<int> crop_parm);

};

#endif // CROP_TOOL_H
