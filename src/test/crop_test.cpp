#include <Magick++.h>
#include <iostream>
#include <QDebug>

using namespace std;
//using namespace Magick;

class crop_test{



public:
    crop_test();
    ~crop_test();
    void crop_image();
    Magick::Image image;

};

//void crop_test::crop_image(){
//    try{
//        image.read("girl.gif");
//        image.crop( Geometry(100,100, 100, 100) );
//        image.write( "x.gif" );
//    } catch( Exception &error_ )
//    {
//        qDebug() << "ImageMagick++: klarer ikke å lese bilde i crop_test";
//        cout << "Caught exception: " << error_.what() << endl;

//    }
//}


