#include <Magick++.h>
#include <iostream>
#include <QDebug>

using namespace std;
using namespace Magick;

class crop_test{

    Image image;

public:
    crop_test(){
        crop_image_test();
    }
    ~crop_test();

    void crop_image_test()
    {
        try{
            image.read("girl.gif");
            image.crop( Geometry(100,100, 100, 100) );
            image.write( "x.gif" );
        } catch( Exception &error_ )
        {
            qDebug() << "ImageMagick++: klarer ikke å lese bilde i crop_test";
            cout << "Caught exception: " << error_.what() << endl;

        }
    }


};

//void crop_test::crop_image_test(){
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


