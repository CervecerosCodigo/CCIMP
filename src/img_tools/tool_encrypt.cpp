#include "tool_encrypt.h"

void tool_encrypt::execute(Magick::Image &img)
{

    using_coordinates* param = (using_coordinates*) get_para();

    try{
        img.encipher(param->get_passphrase());
        qDebug() << "Bilde er kryptert";
    }catch(Magick::Warning){
        //Det er denne exception som normalt blir eksekvert hved feil i ImageMagick
        err_listener->on_exception_occured(TOOLIDENT::DECRYPT);
    }catch(Magick::Error &error){
        err_listener->on_exception_occured(TOOLIDENT::DECRYPT);
    }catch(std::exception &error){
        err_listener->on_exception_occured(TOOLIDENT::DECRYPT);
    }
}
