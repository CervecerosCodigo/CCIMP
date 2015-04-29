#include "tool_decrypt.h"

void tool_decrypt::execute(Magick::Image &img)
{
    using_coordinates* param = (using_coordinates*) get_para();

    try{
        img.decipher(param->get_passphrase());
        //Beholder utskriften foreløpig
        qDebug() << "Bilde er dekryptert";
    }catch(Magick::Warning){
        //Det er denne exception som normalt blir eksekvert hved feil i ImageMagick
        err_listener->on_exception_occured(TOOLIDENT::ENCRYPT);
    }catch(Magick::Error &error){
        err_listener->on_exception_occured(TOOLIDENT::ENCRYPT);
    }catch(std::exception &error){
        err_listener->on_exception_occured(TOOLIDENT::ENCRYPT);
    }
}
