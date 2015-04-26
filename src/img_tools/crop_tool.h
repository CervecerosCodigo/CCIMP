#ifndef CROP_TOOL_H
#define CROP_TOOL_H

#include <Magick++.h>
#include <vector>


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


    Magick::Image* crop_image(Magick::Image& img, const std::vector<int>& crop_parm);

};

#endif // CROP_TOOL_H
