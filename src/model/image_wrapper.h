#ifndef IMAGE_WRAPPER_H
#define IMAGE_WRAPPER_H

#include <QImage>
#include <QDebug>
#include <vector>
#include "ccimp_vector.h"
#include <model/image_tool.h>
#include "Magick++.h"
#include "img_tools/img_obj_converter.h"
class image_wrapper
{
    ccimp_vector<Magick::Image*> undo_history;   //holds previous version
    ccimp_vector<Magick::Image*> redo_history;   //holds newer versions, in case of previous undo
    QImage* image;
    image_tool* current_tool;

    void update_history();  //keep history vectors up-to-date

public:
    image_wrapper(QImage& img);
    ~image_wrapper();

    void execute_tool();
    void undo_last_command();
    void redo_last_command();



    inline void set_current_tool(image_tool* t){current_tool = t;}
    inline QImage& get_image(){return *image;}
};

#endif // IMAGE_WRAPPER_H
