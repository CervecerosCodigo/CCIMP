#include "tool_color_balance.h"

void tool_color_balance::execute(Magick::Image &img)
{
    using_slider* param = (using_slider*) get_para();
        qDebug() << "Slider 1:" << param->get_slider_val(0)
                 << "Slider 2:" << param->get_slider_val(1)
                 << "Slider 3:" << param->get_slider_val(2);

    try{
        img.gamma(
                    param->get_slider_val(0)*0.1,
                    param->get_slider_val(1)*0.1,
                    param->get_slider_val(2)*0.1
                    );
    }catch(Magick::Warning){
        //Det er denne exception som normalt blir eksekvert hved feil i ImageMagick
        err_listener->on_exception_occured(TOOLIDENT::COL);
    }catch(Magick::Error &error){
        err_listener->on_exception_occured(TOOLIDENT::COL);
    }catch(std::exception &error){
        err_listener->on_exception_occured(TOOLIDENT::COL);
    }
}
