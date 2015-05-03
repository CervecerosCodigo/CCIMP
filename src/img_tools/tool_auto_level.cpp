#include "tool_auto_level.h"

void tool_auto_level::execute(Magick::Image &img) {
    img.autoLevel();
}

