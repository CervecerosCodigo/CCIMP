#include "tool_encrypt.h"

void tool_encrypt::execute(Magick::Image &img)
{

    using_coordinates* param = (using_coordinates*) get_para();

    img.encipher(param->get_passphrase());
    qDebug() << "Bilde er kryptert";
}
