#include "model/test_klasse.h"

test_klasse::test_klasse()
{

    image_tool* blur = new image_tool_blur();
    command* blur_cmd = new command_blur_apply(blur);

}

test_klasse::~test_klasse()
{

}

