#include "controller.h"


controller::controller(MainWindow& mw):gui_mw{mw}
{
    gui_mw.set_event_listener(this); //setting listener on gui/mainwindow

}

controller::~controller()
{
//    delete selected_tool;
//    delete current_image;
}

//void controller::set_updated_image(QImage *updated_image){
//    gui_mw.set_updated_image(updated_image);
//}

void controller::register_tool(image_tool* t){

    //tools.insert_back(t);
    TOOLIDENT t_type = t->get_tool_identifier();

    //Call correct GUI-function to set its parameters on the slider tools
    switch(t_type){
    case TOOLIDENT::BLUR:
        gui_mw.set_blur_tool(t);
        break;
    case TOOLIDENT::SHARPEN:
        //code
        break;
    case TOOLIDENT::CROP:
        gui_mw.set_crop_tool(t);
        break;
    case TOOLIDENT::RESIZE:
        //code
        break;
    case TOOLIDENT::COL:
        gui_mw.set_color_balance_tool(t);
        break;
    case TOOLIDENT::BRIGTHEN:
        gui_mw.set_brightness_tool(t);
        break;
    case TOOLIDENT::CONTRAST:
        gui_mw.set_contrast_tool(t);
        break;
    case TOOLIDENT::ROTATE:
        gui_mw.set_rotate_tool(t);
        break;
    }

}

//Lytter på "nytt bilde" i GUI oppretter en wrapper for det
void controller::on_new_image(QImage& img){
    qDebug() << "oppretter new image_wrapper";
    current_image = new image_wrapper(img);
    //TODO:: Må oppdatere undo/redo-vectorene her også
}

//Registers the tool that was click in GUI
void controller::on_clicked_tool(image_tool* t){
    selected_tool = t;
    current_image->set_current_tool(t);
}

void controller::execute_tool_on_image(callback_iface* callback){
    qDebug() << "Executing tool in Controller";
    current_image->execute_tool(callback);
}

//Lytter på "undo-knappen" i GUI
void controller::undo_last_command(){
    current_image->undo_last_command();
}

//Lytter på "redo_knappen" i GUI
void controller::redo_last_command(){
    current_image->redo_last_command();
}
