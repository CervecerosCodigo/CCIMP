#include "tool_secure.h"

void tool_secure::execute(Magick::Image &img)
{

    using_text* param = (using_text*) get_para();

    try{
        if(param->get_is_encryption()){
            img.encipher(param->get_text());
            //        img.encipher("qwe");
            qDebug() << Q_FUNC_INFO << "encryption finished";
        }else{
            img.decipher(param->get_text());
            //        img.decipher("qwe");
            qDebug() << Q_FUNC_INFO << "decryption finished";
        }
    }catch(Magick::Warning){
        //Det er denne exception som normalt blir eksekvert hved feil i ImageMagick
        err_listener->on_exception_occured(TOOLIDENT::SECURE);
    }catch(Magick::Error){
        err_listener->on_exception_occured(TOOLIDENT::SECURE);
    }catch(std::exception){
        err_listener->on_exception_occured(TOOLIDENT::SECURE);
    }
}

