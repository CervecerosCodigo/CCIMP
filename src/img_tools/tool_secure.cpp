#include "tool_secure.h"

void tool_secure::execute(Magick::Image &img)
{

    using_text* param = (using_text*) get_para();


    //@TODO: husk å legge inn exception her
    if(param->get_is_encryption()){
        img.encipher(param->get_text());
//        img.encipher("qwe");
        qDebug() << Q_FUNC_INFO << "encryption finished";
    }else{
        img.decipher(param->get_text());
//        img.decipher("qwe");
        qDebug() << Q_FUNC_INFO << "decryption finished";
    }
}
