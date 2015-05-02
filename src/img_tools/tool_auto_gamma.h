#ifndef TOOL_AUTO_GAMMA
#define TOOL_AUTO_GAMMA

#include "img_tools/tool.h"
#include "img_tools/image_tool.h"
#include "parameters/using_no_parameters.h"
#include <QDebug>

class tool_auto_gamma : public tool {

public:
    using tool::tool;

    void execute(Magick::Image& img) override;

};

#endif // TOOL_AUTO_GAMMA

