#include "controller.h"


controller::controller(MainWindow& mw):gui_mw{mw}
{
    gui_mw.set_event_listener(this); //setting listener on gui/mainwindow
    callback = gui_mw.get_callback_listener();  //callback to update image later on using this interface
}

controller::~controller()
{
    //if(current_image != nullptr)
        //delete current_image;
    //delete callback;
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
        gui_mw.set_sharpen_tool(t);
        break;
    case TOOLIDENT::CROP:
        gui_mw.set_crop_tool(t);
        break;
    case TOOLIDENT::RESIZE:
        gui_mw.set_scale_tool(t);
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
    case TOOLIDENT::SECURE:
        gui_mw.set_secure_tool(t);
        break;
    case TOOLIDENT::AUTOGAMMA:
        gui_mw.set_auto_gamma_tool(t);
        break;
    case TOOLIDENT::AUTOLEVEL:
        gui_mw.set_auto_level_tool(t);
        break;
    }

}

//Lytter på "nytt bilde" i GUI oppretter en wrapper for det
void controller::on_new_image(QImage& img){


       // current_image = new image_wrapper(img, callback);

        current_image.set_Qimage(img, callback);

}

//Registers the tool that was click in GUI
void controller::on_clicked_tool(image_tool* t){

    current_image.set_current_tool(t);
    current_image.update_history();    //Kaller wrapper sin "historieorganisator"
}

void controller::updating_image(){
    current_image.image_update();
}

void controller::finished(){
    current_image.image_finished();
}

void controller::canceled(){
    current_image.image_canceled();
}


//Lytter på "undo-knappen" i GUI
void controller::undo_last_command(){
    current_image.undo_last_command();
}

//Lytter på "redo_knappen" i GUI
void controller::redo_last_command(){
    current_image.redo_last_command();
}

//Lytter på en exception fra gui
void controller::on_exception_occured(TOOLIDENT t_type, ERRORTYPE err_type)
{

    qDebug() << "Exception er fanget opp i controller";
    switch(t_type){
    case TOOLIDENT::BLUR:
        gui_mw.exception_in_image_processing(err_strings::blur_title, err_strings::blur_msg);
        break;
    case TOOLIDENT::SHARPEN:
        gui_mw.exception_in_image_processing(err_strings::crop_title, err_strings::crop_msg);
        break;
    case TOOLIDENT::CROP:
        gui_mw.exception_in_image_processing(err_strings::crop_title, err_strings::crop_msg);
        break;
    case TOOLIDENT::RESIZE:
        gui_mw.exception_in_image_processing(err_strings::scale_title, err_strings::scale_msg);
        break;
    case TOOLIDENT::COL:
        if(err_type == ERRORTYPE::IDENTICAL_IMAGES){
            canceled();
            return;
        }else{
            gui_mw.exception_in_image_processing(err_strings::col_title, err_strings::col_msg);
        }
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
    case TOOLIDENT::SECURE:
        gui_mw.exception_in_image_processing(err_strings::encrypt_msg, err_strings::encrypt_msg);
        break;
    case TOOLIDENT::AUTOGAMMA:
        gui_mw.exception_in_image_processing(err_strings::encrypt_msg, err_strings::encrypt_msg);
        break;
    case TOOLIDENT::AUTOLEVEL:
        gui_mw.exception_in_image_processing(err_strings::encrypt_msg, err_strings::encrypt_msg);
        break;
    }

    canceled(); //Exception message displayed, so we cancel last try to edit
}
