#include "image_processing_unit.h"


image_processing_unit::image_processing_unit(MainWindow& mw):gui_mw{mw}
{
    gui_mw.set_image_listener(this); //setting listener on gui/mainwindow

}

image_processing_unit::~image_processing_unit()
{

}


void image_processing_unit::register_tool(image_tool* t){

    tools.insert_back(t);
    num_tools++;
}

//Lytter på "nytt bilde" i GUI oppretter en wrapper for det
void image_processing_unit::on_image_change(QImage& img){
    //qDebug() << "Skriver nå ut via gui sin set_image-metode";
    current_image = new image_wrapper(img);
}


//Lytter på "undo-knappen" i GUI
void image_processing_unit::undo_last_command(){
    current_image->undo_last_command();
}

//Lytter på "redo_knappen" i GUI
void image_processing_unit::redo_last_command(){
    current_image->redo_last_command();
}
