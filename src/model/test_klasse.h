#ifndef TEST_KLASSE_H
#define TEST_KLASSE_H


#include "model/image_processing_unit.h"
#include "tool_blur.h"
#include "model/image_tool.h"
#include "parameters.h"
#include "parameter_using_slider.h"
#include <QImage>
#include <QColor>

class test_klasse
{
    QImage image;
public:
    test_klasse();
    ~test_klasse();
};

#endif // TEST_KLASSE_H
