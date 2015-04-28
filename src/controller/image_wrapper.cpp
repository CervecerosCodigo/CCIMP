#include "image_wrapper.h"

image_wrapper::image_wrapper(QImage& img): qimg_org{img}
{
    img_ptr = img_obj_converter::to_Image(qimg_org);    //convert image from qimage
    image_is_orig = true;
}

image_wrapper::~image_wrapper()
{

}



//Kommuniserer via interface til rett "tool" og kjører verktøyet
QImage* image_wrapper::execute_tool(){
//    if(callback == nullptr)
//        callback = cb;
    if(img_ptr == nullptr)
        qDebug() << "magick_img is null";


    current_tool->execute(*img_ptr);                  //run selected tool on image

    //git beskjed til MainWindow, via callback-inerfacet, at bildet er endret.
    return img_obj_converter::to_QImage(*img_ptr);
    qDebug() << "Execute av filter i image_wrapper 3";
//    callback->callback_image_edited( temp );
    qDebug() << "Execute av filter i image_wrapper 4";
    //return temp;

}


void image_wrapper::undo_last_command(callback_iface* callback){
    //Bare hvis callback != null og det finnes noe i undo-vector
    if(callback == nullptr)
        return;

    //undo-vector er ikke tom
    if(!undo_history.is_empty()){

        //Legg det som vises på skjermen i redo
        redo_history+=*img_ptr;

        img_obj = undo_history.get_last_and_remove();    //henter sist endret fra undo
        callback->callback_image_edited(img_obj_converter::to_QImage(img_obj)); //sender bildet til gui
        img_ptr = &img_obj;

    //undo-vector er tom
    }else{

        //kan ikke være sikker på om rett image er satt. konvertere fra org Qimage og setter image på nytt i gui
        if(!image_is_orig){
            img_ptr = img_obj_converter::to_Image(qimg_org);    //convert image from qimage
            callback->callback_image_edited(img_obj_converter::to_QImage(*img_ptr)); //sender bildet til gui
            image_is_orig = true;
        }
    }
}


void image_wrapper::redo_last_command(callback_iface* callback){
    if(callback == nullptr)
        return;

    if(!redo_history.is_empty()){

        undo_history+=*img_ptr;

        img_obj = redo_history.get_last_and_remove();    //henter sist endret fra redo
        callback->callback_image_edited(img_obj_converter::to_QImage(img_obj)); //sender bildet til gui
        img_ptr = &img_obj;
    }
}

void image_wrapper::update_history(){

    //Ingen bilder fra før. Legg bildet i vector
    if(undo_history.is_empty()){
        Magick::Image* t = new Magick::Image(*img_ptr);
        undo_history+=*t;
        qDebug() << "La inn første bilde. Størrelsen på undo-history" << undo_history.size() ;

    //Det finnes noe i vector
    }else{
        //Sammenlign current med siste bilde i vector. Hvis like, gjør ingenting
        if(img_ptr->compare(undo_history.look_at_last())){
            qDebug() << "Bildene er like" ;

        //"current" og "last" er ikke like
        }else{

            Magick::Image* t = new Magick::Image(*img_ptr);
            undo_history+=*t;
            qDebug() << "La inn nytt bilde. Størrelsen på undo-history" << undo_history.size() ;
            image_is_orig = false;
        }

    }
}
