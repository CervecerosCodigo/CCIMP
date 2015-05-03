#include "tool_scale.h"


void tool_scale::execute(Magick::Image &img)
{
    using_slider* param = (using_slider*) get_para();

    width_initial = img.columns();
    height_initial = img.rows();

    width_new = (param->get_slider_val()*0.01)*width_initial;
    //qDebug() << "width_initial" << width_initial;
    //qDebug() << "width_new" << width_new;

    try{

        img.adaptiveResize(Magick::Geometry(width_new,0, 0, 0));

    }catch(Magick::Warning){
        //Det er denne exception som normalt blir eksekvert hved feil i ImageMagick
        err_listener->on_exception_occured(TOOLIDENT::RESIZE, ERRORTYPE::WARNING);
    }catch(Magick::Error &error){
        err_listener->on_exception_occured(TOOLIDENT::RESIZE, ERRORTYPE::MAGICK_EXCEPTION);
    }catch(std::exception &error){
        err_listener->on_exception_occured(TOOLIDENT::RESIZE, ERRORTYPE::STDEXCEPTION);
    }
}
