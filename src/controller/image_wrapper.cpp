#include "image_wrapper.h"

image_wrapper::image_wrapper(QImage& img, callback_iface* c): qimg_org{img}, callback{c}
{
    img_ptr_current = img_obj_converter::to_Image(qimg_org);    //convert image from qimage
    image_is_orig = true;
    undo_history.empty_vector();
    redo_history.empty_vector();
}


image_wrapper::~image_wrapper()
{
    delete img_ptr_current;
    delete img_ptr_edit;
    delete current_tool;
    delete callback;

}

void image_wrapper::set_Qimage(QImage &img, callback_iface *c){
    qimg_org = img;
    callback = c;
    img_ptr_current = img_obj_converter::to_Image(qimg_org);    //convert image from qimage
    image_is_orig = true;
    undo_history.empty_vector();
    redo_history.empty_vector();
}

//Kjører oppdateringer på midlertidig bilde, med img_ptr_current som referanse for hver gang.
void image_wrapper::image_update(){
    img_ptr_edit = new Magick::Image(*img_ptr_current);
    current_tool->execute(*img_ptr_edit);                  //run selected tool on image
    callback->callback_image_edited(img_obj_converter::to_QImage(*img_ptr_edit));
}


//Trykket OK i tool dialog. setter begge pekerne likt og
void image_wrapper::image_finished(){
    img_ptr_current = new Magick::Image(*img_ptr_edit);
}


//Trykket Cancel i tool dialog.
void image_wrapper::image_canceled(){
    if(img_ptr_edit == nullptr)
        return;
    //Hvis edit er forskjellig fra current skal man bare "undo" forskjellen, ikke ta ut fra vektor
    if(!img_ptr_edit->compare(*img_ptr_current)){
        callback->callback_image_edited(img_obj_converter::to_QImage(*img_ptr_current)); //sender bildet til gui
        img_ptr_edit = new Magick::Image(*img_ptr_current);

    }
}


void image_wrapper::undo_last_command(){
    //Bare hvis callback != null og det finnes noe i undo-vector
    if(callback == nullptr)
        return;

    //undo-vector er ikke tom
    if(!undo_history.is_empty()){

        //Legg det som vises på skjermen i redo
        redo_history+=*img_ptr_current;

        img_helper_obj = undo_history.get_last_and_remove();    //henter sist endret fra undo
        callback->callback_image_edited(img_obj_converter::to_QImage(img_helper_obj)); //sender bildet til gui
        img_ptr_current = &img_helper_obj;

    //undo-vector er tom
    }else{

        //kan ikke være sikker på om rett image er satt. konvertere fra org Qimage og setter image på nytt i gui
        if(!image_is_orig){
            img_ptr_current = img_obj_converter::to_Image(qimg_org);    //convert image from qimage
            callback->callback_image_edited(img_obj_converter::to_QImage(*img_ptr_current)); //sender bildet til gui
            callback->callback_report_image_is_original();
            image_is_orig = true;
        }
    }
}


void image_wrapper::redo_last_command(){
    if(callback == nullptr)
        return;

    if(!redo_history.is_empty()){

        undo_history+=*img_ptr_current;

        img_helper_obj = redo_history.get_last_and_remove();    //henter sist endret fra redo
        callback->callback_image_edited(img_obj_converter::to_QImage(img_helper_obj)); //sender bildet til gui
        img_ptr_current = &img_helper_obj;
    }
}

void image_wrapper::update_history(){

    //Ingen bilder fra før. Legg bildet i vector
    if(undo_history.is_empty()){
        Magick::Image* t = new Magick::Image(*img_ptr_current);
        undo_history+=*t;

    //Det finnes noe i vector
    }else{
        //Sammenlign current med siste bilde i vector. Hvis like, gjør ingenting
        if(img_ptr_current->compare(undo_history.look_at_last())){

        //"current" og "last" er ikke like
        }else{

            Magick::Image* t = new Magick::Image(*img_ptr_current);
            undo_history+=*t;
            image_is_orig = false;
        }

    }
}


