#include "tool_auto_gamma.h"

void tool_auto_gamma::execute(Magick::Image &img) {
    img.autoGamma();
    qDebug() << "Autogamma har kjørt";
}
