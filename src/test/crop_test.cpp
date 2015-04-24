#include "crop_test.h"

//crop_test::crop_test()
//{
//    crop_image_test("hei.gif", 100, 100, 100, 100);
//}

//crop_test::~crop_test()
//{

//}

void crop_test::crop_image_test(const char* path, int width, int height, int x_offset, int y_offset)
{
    try{
        Image image;
        image.read(path);
        qDebug() << "Crop test: har LEST inn bilde fra " + QString(path);
        image.crop( Geometry(width,height, x_offset, y_offset) );
        image.write(path);
        qDebug() << "Crop test: har LAGRET bilde til " + QString(path);
    } catch( Exception &error_ )
    {
        std::cout << "Caught exception, klarer ikke å lese bilde i crop test: " << error_.what() << std::endl;

    }
}

