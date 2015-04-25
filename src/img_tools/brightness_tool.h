#ifndef BRIGHTNESS_TOOL_H
#define BRIGHTNESS_TOOL_H

#include <Magick++.h>
#include <vector>


class brightness_tool
{

    static brightness_tool* instance;
    Magick::Image image;

    brightness_tool(){}
    brightness_tool(brightness_tool const&) = delete;
    void operator=(brightness_tool const&) = delete;

public:
    static brightness_tool& getInstance(){
        static brightness_tool instance;
        return instance;
    }

    void change_brightness(Magick::Image& img, int brght_value);

};

#endif // BRIGHTNESS_TOOL_H
