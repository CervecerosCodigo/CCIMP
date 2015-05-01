#include "tool_contrast.h"

void tool_contrast::execute(Magick::Image &img)
{

    using_slider* param = (using_slider*) get_para();

    try{
        img.brightnessContrast(0.0, param->get_slider_val()*1.0);
    }catch(Magick::Warning){
        //Det er denne exception som normalt blir eksekvert hved feil i ImageMagick
        err_listener->on_exception_occured(TOOLIDENT::CONTRAST, ERRORTYPE::WARNING);
    }catch(Magick::Error &error){
        err_listener->on_exception_occured(TOOLIDENT::CONTRAST, ERRORTYPE::MAGICK_EXCEPTION);
    }catch(std::exception &error){
        err_listener->on_exception_occured(TOOLIDENT::CONTRAST, ERRORTYPE::STDEXCEPTION);
    }
}
