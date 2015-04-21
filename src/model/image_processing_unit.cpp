#include "image_processing_unit.h"


image_processing_unit::image_processing_unit(MainWindow& mw):gui_mw{mw}
{


}

image_processing_unit::~image_processing_unit()
{

}


void image_processing_unit::register_tool(image_tool* t){
//    t->execute();
    tools.push_back(t);


}


void image_processing_unit::open_new_image(QImage img){
    open_images.push_back(image_wrapper(img));
}
