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



void controller::register_tool(image_tool* t){

    //setter en error listener på valgt vektøy
    t->set_error_listener(this);

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
    case TOOLIDENT::ENCRYPT:
        gui_mw.set_encipher_tool(t);
        break;
    case TOOLIDENT::DECRYPT:
        gui_mw.set_decipher_tool(t);
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
    current_image->update_history();    //Kaller wrapper sin "historieorganisator"
}

QImage* controller::updating_image(){
    //qDebug() << "Executing tool in Controller";
    return current_image->image_update();
}

void controller::finished(){
    current_image->image_finished();
}

void controller::canceled(callback_iface *callback){
    current_image->image_canceled(callback);
}


//Lytter på "undo-knappen" i GUI
void controller::undo_last_command(callback_iface* callback){
    current_image->undo_last_command(callback);
}

//Lytter på "redo_knappen" i GUI
void controller::redo_last_command(callback_iface* callback){
    current_image->redo_last_command(callback);
}

//Lytter på en exception fra gui
void controller::on_exception_occured(TOOLIDENT t_type)
{
//    qDebug() << "Exception er fanget opp i controller";
    switch(t_type){
    case TOOLIDENT::BLUR:
        gui_mw.exception_in_image_processing(err_strings::blur_title, err_strings::blur_msg);
        break;
    case TOOLIDENT::SHARPEN:
        //gui_mw.exception_in_image_processing(err_strings::crop_title, err_strings::crop_msg);
        break;
    case TOOLIDENT::CROP:
        gui_mw.exception_in_image_processing(err_strings::crop_title, err_strings::crop_msg);
        break;
    case TOOLIDENT::RESIZE:
//        gui_mw.exception_in_image_processing(err_strings::resize_title, err_strings::crop_msg);
        break;
    case TOOLIDENT::COL:
        gui_mw.exception_in_image_processing(err_strings::col_title, err_strings::col_msg);
        break;
    case TOOLIDENT::BRIGTHEN:
        gui_mw.exception_in_image_processing(err_strings::bright_title, err_strings::bright_msg);
        break;
    case TOOLIDENT::CONTRAST:
        gui_mw.exception_in_image_processing(err_strings::contr_title, err_strings::contr_msg);
        break;
    case TOOLIDENT::ROTATE:
        gui_mw.exception_in_image_processing(err_strings::rotate_title, err_strings::rotate_msg);
        break;
    case TOOLIDENT::ENCRYPT:
        gui_mw.exception_in_image_processing(err_strings::encrypt_title, err_strings::encrypt_msg);
        break;
    case TOOLIDENT::DECRYPT:
        gui_mw.exception_in_image_processing(err_strings::encrypt_title, err_strings::encrypt_msg);
        break;
    }
}
