#include "tool_rotate.h"

void tool_rotate::execute(Magick::Image &img)
{
    using_coordinates* param = (using_coordinates*) get_para();
    try{
        img.rotate(param->get_angle());
    }catch(Magick::Warning){
        //Det er denne exception som normalt blir eksekvert hved feil i ImageMagick
        err_listener->on_exception_occured(TOOLIDENT::ROTATE);
    }catch(Magick::Error &error){
        err_listener->on_exception_occured(TOOLIDENT::ROTATE);
    }catch(std::exception &error){
        err_listener->on_exception_occured(TOOLIDENT::ROTATE);
    }
}
