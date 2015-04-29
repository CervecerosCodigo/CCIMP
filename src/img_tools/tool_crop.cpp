#include "tool_crop.h"

void tool_crop::execute(Magick::Image& img){

    using_coordinates* param = (using_coordinates*) get_para();

    try{
//        img.crop(Magick::Geometry(
//                     param->get_width(),
//                     param->get_height(),
//                     param->get_x_axis(),
//                     param->get_y_axis()));
            img.crop(Magick::Geometry(10000,10000,10000,10000));
    }catch(Magick::Warning){
        qDebug() << "Exception i crop Warning Magick::Warning";
        err_listener->on_exception_occured(TOOLIDENT::CROP);
    }catch(Magick::Error &error){
        qDebug() << "Exception i crop Magick::Error" << &error;
    }catch(std::exception &error){
        qDebug() << "Exception i crop std::exception" << &error;
    }
}

