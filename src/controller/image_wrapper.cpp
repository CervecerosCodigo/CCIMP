#include "image_wrapper.h"

image_wrapper::image_wrapper(QImage& img): q_img{img}
{
    magic_img = img_obj_converter::to_Image(q_img);    //convert image from qimage
}

image_wrapper::~image_wrapper()
{

}



//Kommuniserer via interface til rett "tool" og kjører verktøyet
void image_wrapper::execute_tool(callback_iface* cb){
    if(callback == nullptr)
        callback = cb;

    current_tool->execute(*magic_img);                  //run selected tool on image

    //git beskjed til MainWindow, via callback-inerfacet, at bildet er endret.
    callback->callback_image_edited( img_obj_converter::to_QImage(*magic_img) );


}


void image_wrapper::undo_last_command(){
    //Bare hvis callback != null og det finnes noe i undo-vector
    if(callback != nullptr && undo_history.size() > 0){

        qDebug() << "undo size før:" << undo_history.size();
        Magick::Image temp = undo_history.get_last_and_remove();    //henter sist endret fra undo
        //magic_img = &temp;
        callback->callback_image_edited(img_obj_converter::to_QImage(temp)); //sender bildet til gui

        qDebug() << "undo size etter: " << undo_history.size();

    }
}


void image_wrapper::redo_last_command(){
    qDebug() << "Kjører redo-command";
}

void image_wrapper::update_history(){

    //Ingen bilder fra før. Legg bildet i vector
    if(undo_history.is_empty()){
        undo_history+(Magick::Image(*magic_img));
        qDebug() << "La inn første bilde. Størrelsen på undo-history" << undo_history.size() ;

    //Det finnes noe i vector
    }else{
        //Sammenlign current med siste bilde i vector. Hvis like, gjør ingenting
        if(magic_img->compare(undo_history.look_at_last())){
            qDebug() << "Bildene er like" ;

        //"current" og "last" er ikke like
        }else{

            undo_history+(Magick::Image(*magic_img));
            qDebug() << "La inn nytt bilde. Størrelsen på undo-history" << undo_history.size() ;
        }
    }
}
