#include "tool_decrypt.h"

void tool_decrypt::execute(Magick::Image &img)
{
    using_coordinates* param = (using_coordinates*) get_para();

    img.decipher(param->get_passphrase());
    qDebug() << "Bilde er dekryptert";
}
