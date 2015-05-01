#include "tool_brightness.h"

void tool_brightness::execute(Magick::Image &img)
{

    using_slider* param = (using_slider*) get_para();
    qDebug() << "using brightness tool";
    try{
        img.brightnessContrast(param->get_slider_val()*1.0, 0.0);
    }catch(Magick::Warning){
        //Det er denne exception som normalt blir eksekvert hved feil i ImageMagick
        err_listener->on_exception_occured(TOOLIDENT::BRIGTHEN, ERRORTYPE::WARNING);
    }catch(Magick::Error &error){
        err_listener->on_exception_occured(TOOLIDENT::BRIGTHEN, ERRORTYPE::MAGICK_EXCEPTION);
    }catch(std::exception &error){
        err_listener->on_exception_occured(TOOLIDENT::BRIGTHEN, ERRORTYPE::STDEXCEPTION);
    }
}
