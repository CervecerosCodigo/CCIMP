#include "image_processing_unit.h"

image_processing_unit::image_processing_unit()
{

}

image_processing_unit::~image_processing_unit()
{

}


void image_processing_unit::register_tool(image_tool* t){
    t->execute();
    tools.push_back(t);

}
