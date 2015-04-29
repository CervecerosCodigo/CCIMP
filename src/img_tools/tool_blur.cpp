#include "tool_blur.h"


void tool_blur::execute(Magick::Image& img){
    using_slider* param = (using_slider*) get_para();
//    qDebug() << "Slider 1:" << param->get_slider_val(0)
//             << "Slider 2:" << param->get_slider_val(1);
    try{
    img.blur(
                param->get_slider_val(0)*0.1,
                param->get_slider_val(1)*0.1);
    }catch(Magick::Warning &warning){
        qDebug() << "Exception i blur " << &warning;
    }catch(Magick::Error &error){
        qDebug() << "Exception i blur " << &error;
    }catch(std::exception &error){
        qDebug() << "Exception i blur " << &error;
    }
}
