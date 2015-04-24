#include "image_tool.h"

image_tool::image_tool(parameters* p): param{p}
{

}

image_tool::~image_tool()
{
    delete param;
}

