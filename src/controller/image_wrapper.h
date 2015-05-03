#ifndef IMAGE_WRAPPER_H
#define IMAGE_WRAPPER_H

#include <QImage>
#include <QDebug>
#include <vector>
#include "ccimp_vector.h"
#include <img_tools/image_tool.h>
#include "Magick++.h"
#include <QColor>
#include "callback_iface.h"
#include "parameters/using_slider.h"
class image_wrapper
{
    ccimp_vector<Magick::Image> undo_history;   //holds previous version
    ccimp_vector<Magick::Image> redo_history;   //holds newer versions, in case of previous undo
    QImage* qimg_ptr_helper;    //hjelpe-peker.
    QImage* qimg_ptr_org;       //orginalobjektet, unikt for hver wrapper
    Magick::Image img_helper_obj;   //brukes i undo/redo ifm vectorene
    Magick::Image* img_ptr_current = NULL; //peker til objektet som vises i GUI
    Magick::Image* img_ptr_edit = NULL;    //peker til objektet som er under endring

    image_tool* current_tool;

    bool image_is_orig;
    callback_iface* callback;

    QImage* to_QImage(Magick::Image& img);  //konverterer til QImage
    void to_Image(QImage& qimage);          //konverterer til Image

public:
    image_wrapper();
    ~image_wrapper();
    void set_Qimage(QImage& img, callback_iface* c);

    void image_update();
    void image_finished();
    void image_canceled();

    void undo_last_command();
    void redo_last_command();
    void update_history();  //keep history vectors up-to-date

    inline void set_current_tool(image_tool* t){current_tool = t;}


};

#endif // IMAGE_WRAPPER_H
