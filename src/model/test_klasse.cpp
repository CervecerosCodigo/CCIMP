#include "model/test_klasse.h"



test_klasse::test_klasse()
{


    processing_interface* p = new image_processing_unit();
    tool* i_tool = new tool_blur(p);


}

test_klasse::~test_klasse()
{

}

