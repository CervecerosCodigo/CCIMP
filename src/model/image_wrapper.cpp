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

    current_tool->execute(*image);
}


void image_wrapper::undo_last_command(){
    qDebug() << "Kjører undo-command";
}


void image_wrapper::redo_last_command(){
    qDebug() << "Kjører redo-command";
}
