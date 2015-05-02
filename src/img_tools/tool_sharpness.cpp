#include "tool_sharpness.h"


void tool_sharpness::execute(Magick::Image &img)
{
    using_slider* param = (using_slider*) get_para();

    try{
        img.sharpen(
                    param->get_slider_val(0)*0.1,
                    param->get_slider_val(1)*0.1
                    );
    }catch(Magick::Warning){
        //Det er denne exception som normalt blir eksekvert hved feil i ImageMagick
        err_listener->on_exception_occured(TOOLIDENT::SHARPEN, ERRORTYPE::WARNING);
    }catch(Magick::Error &error){
        err_listener->on_exception_occured(TOOLIDENT::SHARPEN, ERRORTYPE::MAGICK_EXCEPTION);
    }catch(std::exception &error){
        err_listener->on_exception_occured(TOOLIDENT::SHARPEN, ERRORTYPE::STDEXCEPTION);
    }

}
