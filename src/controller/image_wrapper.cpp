#include "image_wrapper.h"

image_wrapper::image_wrapper()
{
}


image_wrapper::~image_wrapper()
{
    if(img_ptr_current != nullptr)
        delete img_ptr_current;
//    if(img_ptr_edit != nullptr)
//        delete img_ptr_edit;

}

void image_wrapper::set_Qimage(QImage &img, callback_iface *c){
    qimg_ptr_org = &img;
    callback = c;
    to_Image(*qimg_ptr_org);    //convert image from qimage
    image_is_orig = true;
    undo_history.empty_vector();
    redo_history.empty_vector();
}

//Kjører oppdateringer på midlertidig bilde, med img_ptr_current som referanse for hver gang.
void image_wrapper::image_update(){
    img_ptr_edit = new Magick::Image(*img_ptr_current);
    current_tool->execute(*img_ptr_edit);                  //run selected tool on image
    qimg_ptr_helper = to_QImage(*img_ptr_edit);
    callback->callback_image_edited(qimg_ptr_helper);
}


//Trykket OK i tool dialog. setter begge pekerne likt og
void image_wrapper::image_finished(){
    if(img_ptr_edit == nullptr)
        return;
    img_ptr_current = new Magick::Image(*img_ptr_edit);
}


//Trykket Cancel i tool dialog.
void image_wrapper::image_canceled(){
    if(img_ptr_edit == nullptr)
        return;
    //Hvis edit er forskjellig fra current skal man bare "undo" forskjellen, ikke ta ut fra vektor
    if(!img_ptr_edit->compare(*img_ptr_current)){
        callback->callback_image_edited(to_QImage(*img_ptr_current)); //sender bildet til gui
        img_ptr_edit = new Magick::Image(*img_ptr_current);
        callback->callback_report_image_is_original();

    }
}


void image_wrapper::undo_last_command(){

    //undo-vector er ikke tom
    if(!undo_history.is_empty()){

        //Legg det som vises på skjermen i redo
        redo_history+=*img_ptr_current;

        img_helper_obj = undo_history.get_last_and_remove();    //henter sist endret fra undo
        callback->callback_image_edited(to_QImage(img_helper_obj)); //sender bildet til gui
        img_ptr_current = &img_helper_obj;

    //undo-vector er tom
    }else{

        //kan ikke være sikker på om rett image er satt. konvertere fra org Qimage og setter image på nytt i gui
        if(!image_is_orig){
            to_Image(*qimg_ptr_org);    //convert image from qimage
            callback->callback_image_edited(to_QImage(*img_ptr_current)); //sender bildet til gui
            callback->callback_report_image_is_original();
            image_is_orig = true;
        }
    }
}


void image_wrapper::redo_last_command(){

    if(!redo_history.is_empty()){

        undo_history+=*img_ptr_current;

        img_helper_obj = redo_history.get_last_and_remove();    //henter sist endret fra redo
        callback->callback_image_edited(to_QImage(img_helper_obj)); //sender bildet til gui
        img_ptr_current = &img_helper_obj;
    }
}

void image_wrapper::update_history(){

    //Ingen bilder fra før. Legg bildet i vector
    if(undo_history.is_empty()){
        Magick::Image* t = new Magick::Image(*img_ptr_current);
        undo_history+=*t;
        delete t;
    //Det finnes noe i vector
    }else{
        //Sammenlign current med siste bilde i vector. Hvis like, gjør ingenting
        if(img_ptr_current->compare(undo_history.look_at_last())){

        //"current" og "last" er ikke like
        }else{

            Magick::Image* t = new Magick::Image(*img_ptr_current);
            undo_history+=*t;
            delete t;
            image_is_orig = false;
        }
    }
}


//Konverterer et QImage til Magick::Image
void image_wrapper::to_Image(QImage& qimage)
{

    img_ptr_current = new Magick::Image(Magick::Geometry(qimage.width(), qimage.height()), Magick::ColorRGB(0.5, 0.2, 0.3));

    double scale = 1 / 256.0;
    img_ptr_current->modifyImage();
    Magick::PixelPacket *pixels;
    Magick::ColorRGB mgc;
    for (int y = 0; y < qimage.height(); y++) {
        pixels = img_ptr_current->setPixels(0, y, img_ptr_current->columns(), 1);
        for (int x = 0; x < qimage.width(); x++) {
            QColor pix = qimage.pixel(x, y);

            mgc.red(scale *pix.red());
            mgc.green(scale *pix.green());
            mgc.blue(scale *pix.blue());
            *pixels++ = mgc;
        }
        img_ptr_current->syncPixels();
    }
}

//Konverterer Magick::Image til QImage
QImage* image_wrapper::to_QImage(Magick::Image& image)
{
    qimg_ptr_helper = new QImage(image.columns(), image.rows(), QImage::Format_RGB32);
    const Magick::PixelPacket *pixels;
    Magick::ColorRGB rgb;
    for (int y = 0; y < qimg_ptr_helper->height(); y++) {
        pixels = image.getConstPixels(0, y, qimg_ptr_helper->width(), 1);
        for (int x = 0; x < qimg_ptr_helper->width(); x++) {
            rgb = (*(pixels + x));
            qimg_ptr_helper->setPixel(x, y, QColor((int) (255 * rgb.red())
                                             , (int) (255 * rgb.green())
                                             , (int) (255 * rgb.blue())).rgb());
        }
    }
    return qimg_ptr_helper;
}

