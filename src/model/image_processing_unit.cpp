#include "image_processing_unit.h"
#include<QColor>

image_processing_unit::image_processing_unit()
{
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

image_processing_unit::~image_processing_unit()
{

}


void image_processing_unit::register_tool(image_tool* t){
//    t->execute();
    tools.push_back(t);


}
