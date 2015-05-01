#include "tool_crop.h"

void tool_crop::execute(Magick::Image& img){

    using_coordinates* param = (using_coordinates*) get_para();
    try{
        img.crop(Magick::Geometry(
                     param->get_width(),
                     param->get_height(),
                     param->get_x_axis(),
                     param->get_y_axis()));
        //Denne raden kan brukes for testing hvis man ønsker å tvinge frem en exception
        //img.crop(Magick::Geometry(10000,10000,10000,10000));
    }catch(Magick::Warning){
        //Det er denne exception som normalt blir eksekvert hved feil i ImageMagick
        err_listener->on_exception_occured(TOOLIDENT::CROP, ERRORTYPE::WARNING);
    }catch(Magick::Error &error){
        err_listener->on_exception_occured(TOOLIDENT::CROP, ERRORTYPE::MAGICK_EXCEPTION);
    }catch(std::exception &error){
        err_listener->on_exception_occured(TOOLIDENT::CROP, ERRORTYPE::STDEXCEPTION);
    }
}

