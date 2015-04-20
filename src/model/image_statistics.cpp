#include "image_statistics.h"

image_statistics::image_statistics()
{

}

image_statistics::~image_statistics()
{

}

QString image_statistics::get_img_stat(const QPixmap &img)
{
    QString img_stat;
    img_stat = "<html>Height: " + QString::number(img.height())
                          + "<br> Width: "
                          + QString::number(img.width())
                          + "</html>";
    return img_stat;
}

/**
 * Bare et eksempel dersom vi ikke skal bruke QString
 * @brief image_statistics::get_img_stat2
 * @return
 */
const char *image_statistics::get_img_stat2()
{
    char *str = "Char referanse";
    return str; //Kan brukes med qDebug også som blir prioritert ved eksekvering
}


