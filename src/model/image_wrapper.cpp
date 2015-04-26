#include "image_wrapper.h"

image_wrapper::image_wrapper(QImage& img): q_img{img}
{

}

image_wrapper::~image_wrapper()
{

}

void image_wrapper::update_history(){

}

//Kommuniserer via interface til rett "tool" og kjører verktøyet
void image_wrapper::execute_tool(callback_iface* callback){

    /**
     * TODO: må ta vare på historikk før man utfører tool.
     *      Må kunne sende
     */
    magic_img = img_obj_converter::to_Image(&q_img);    //convert image from qimage

    current_tool->execute(*magic_img);  //run selected tool on image

    //git beskjed til MainWindow, via callback-inerfacet, at bildet er endret.
    callback->callback_image_edited( img_obj_converter::to_QImage(magic_img) );


}


void image_wrapper::undo_last_command(){
    qDebug() << "Kjører undo-command";
}


void image_wrapper::redo_last_command(){
    qDebug() << "Kjører redo-command";
}
