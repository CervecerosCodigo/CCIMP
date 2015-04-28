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
    QImage& qimg_org;
    Magick::Image img_obj;
    Magick::Image* img_ptr;
    image_tool* current_tool;
    //callback_iface* callback;

    bool image_is_orig;

public:
    image_wrapper(QImage& img);
    ~image_wrapper();

    QImage* execute_tool();
    void undo_last_command(callback_iface* callback);
    void redo_last_command(callback_iface* callback);
    void update_history();  //keep history vectors up-to-date

    inline void set_current_tool(image_tool* t){current_tool = t;}

};

#endif // IMAGE_WRAPPER_H
