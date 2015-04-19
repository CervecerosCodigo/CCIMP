#include "model/test_klasse.h"



test_klasse::test_klasse()
{


//    processing_interface* p = new image_processing_unit();
//    tool* i_tool = new tool_blur(p);


    int width = image.width();      //bredden på bildet
    int height = image.height();    //høyden på bildet
    int row = 0;    //dummy
    int col = 0;    //dummy



    //QColor har mange mange metoder..
    QColor curr_color(image.pixel(row, col)); //henter farge i pixel(x,y)
    curr_color.red();       //henter rød-verdien i bilder
    curr_color.green();     //henter grønn-verdien
    curr_color.blue();      //henter blå-verdien



}

test_klasse::~test_klasse()
{

}

