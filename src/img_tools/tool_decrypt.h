#ifndef TOOL_DECRYPT_H
#define TOOL_DECRYPT_H

#include "img_tools/tool.h"
#include "img_tools/image_tool.h"
#include "parameters/using_coordinates.h"
#include <QDebug>

class tool_decrypt : public tool
{
public:
   using tool::tool;

   void execute(Magick::Image& img) override;

};

#endif // TOOL_DECRYPT_H
