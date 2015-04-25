#include "image_wrapper.h"

image_wrapper::image_wrapper(QImage& img): image{&img}
{

}

image_wrapper::~image_wrapper()
{

}

void image_wrapper::update_history(){

}

//Kommuniserer via interface til rett "tool" og kjører verktøyet
void image_wrapper::execute_tool(){
    qDebug() << "Executing tool in Wrapper";
    Magick::Image* img = img_obj_converter::to_Image(image);
    current_tool->execute(*img);

}


void image_wrapper::undo_last_command(){
    qDebug() << "Kjører undo-command";
}


void image_wrapper::redo_last_command(){
    qDebug() << "Kjører redo-command";
}
