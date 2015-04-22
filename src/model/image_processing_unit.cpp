#include "image_processing_unit.h"


image_processing_unit::image_processing_unit(MainWindow& mw):gui_mw{mw}
{
    set_image_listener_on_gui();

}

image_processing_unit::~image_processing_unit()
{

}


void image_processing_unit::register_tool(image_tool* t){

    tools.insert_back(t);


}

void image_processing_unit::on_image_change(QImage& img){
    //qDebug() << "Skriver nå ut via gui sin set_image-metode";
    current_image = new image_wrapper(img);
}


void image_processing_unit::set_image_listener_on_gui(){
    gui_mw.set_image_listener(this);
}
