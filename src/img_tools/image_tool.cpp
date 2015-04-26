#include "image_tool.h"

image_tool::image_tool(parameters* p, TOOLIDENT identifier): param{p}, tool_identifier{identifier}
{

}

image_tool::~image_tool()
{
    delete param;
}

