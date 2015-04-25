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
    TOOLIDENT t_type = t->get_tool_identifier();

    //Call correct GUI-function to set its parameters on the slider tools
    switch(t_type){
    case TOOLIDENT::BLUR:
        //code
        break;
    case TOOLIDENT::SHARPEN:
        //code
        break;
    case TOOLIDENT::CROP:
        //code
        break;
    case TOOLIDENT::RESIZE:
        //code
        break;
    case TOOLIDENT::COL:
        //code
        break;
    case TOOLIDENT::BRIGTHEN:
        //code
        break;
    }

}

//Lytter på "nytt bilde" i GUI oppretter en wrapper for det
void image_processing_unit::on_new_image(QImage& img){
    //qDebug() << "Skriver nå ut via gui sin set_image-metode";
    current_image = new image_wrapper(img);
    //TODO:: Må oppdatere undo/redo-vectorene her også
}

void image_processing_unit::on_clicked_tool(image_tool* t){
    selected_tool = t;

}

//Lytter på "undo-knappen" i GUI
void image_processing_unit::undo_last_command(){
    current_image->undo_last_command();
}

//Lytter på "redo_knappen" i GUI
void image_processing_unit::redo_last_command(){
    current_image->redo_last_command();
}
