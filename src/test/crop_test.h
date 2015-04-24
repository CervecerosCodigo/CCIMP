#ifndef CROP_TEST_H
#define CROP_TEST_H

#include <Magick++.h>
#include <iostream>
#include <QDebug>

using namespace Magick;

class crop_test
{

//    Image image;

public:
    crop_test();
    ~crop_test();

    static void crop_image_test(const char*, int width, int height, int x_offset, int y_offset);
};

#endif // CROP_TEST_H
