#ifndef IMAGE_WRAPPER_H
#define IMAGE_WRAPPER_H

#include <QImage>
#include <QDebug>
#include <vector>
#include "ccimp_vector.h"
#include <img_tools/image_tool.h>
#include "Magick++.h"
#include "img_tools/img_obj_converter.h"
#include "callback_iface.h"

class image_wrapper
{
    ccimp_vector<Magick::Image> undo_history;   //holds previous version
    ccimp_vector<Magick::Image> redo_history;   //holds newer versions, in case of previous undo

    QImage& qimg_org;       //orginalobjektet, unikt for hver wrapper
    Magick::Image img_helper_obj;   //brukes i undo/redo ifm vectorene
    Magick::Image* img_ptr_current; //peker til objektet som vises i GUI
    Magick::Image* img_ptr_edit;    //peker til objektet som er under endring

    image_tool* current_tool;

    bool image_is_orig;

public:
    image_wrapper(QImage& img);
    ~image_wrapper();

    QImage* image_update();
    void image_finished();
    void image_canceled(callback_iface* callback);

    void undo_last_command(callback_iface* callback);
    void redo_last_command(callback_iface* callback);
    void update_history();  //keep history vectors up-to-date

    inline void set_current_tool(image_tool* t){current_tool = t;}

};

#endif // IMAGE_WRAPPER_H
