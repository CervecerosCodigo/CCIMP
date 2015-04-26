#ifndef IMG_OBJ_CONVERTER_H
#define IMG_OBJ_CONVERTER_H

#include <QImage>
#include <QColor>
#include <Magick++.h>
#include <QDebug>

/** Dette er en klasse med to static metoder som vi
 * kan benytte oss for å konvertere frem og tilbake mellom QImage og Image
 * @brief The img_obj_converter class
 */
class img_obj_converter
{
    //Q_OBJECT

public:
    img_obj_converter();
    ~img_obj_converter();

    static Magick::Image* to_Image(QImage&);
    static QImage* to_QImage(Magick::Image&);

};

#endif // IMG_OBJ_CONVERTER_H
