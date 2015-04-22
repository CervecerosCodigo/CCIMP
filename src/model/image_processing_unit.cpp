#include "image_processing_unit.h"


image_processing_unit::image_processing_unit(MainWindow& mw):gui_mw{mw}
{
    set_image_listener_on_gui();

}

image_processing_unit::~image_processing_unit()
{

}


void image_processing_unit::register_tool(image_tool* t){
//    QImage img;
//    t->execute(img);

    tools.insert_back(t);


}


//void image_processing_unit::open_new_image(QImage img){
//    //open_images.push_back(image_wrapper(img));
//}

void image_processing_unit::on_image_change(QImage& img){
    qDebug() << "Skriver nå ut via gui sin set_image-metode";
}


void image_processing_unit::set_image_listener_on_gui(){
    gui_mw.set_image_listener(this);
}
