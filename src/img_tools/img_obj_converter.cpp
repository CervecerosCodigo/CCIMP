#include "img_obj_converter.h"


Magick::Image *img_obj_converter::to_Image(QImage *qimage)
{
    qDebug() << "toImage:" << qimage->width() << qimage->height();

    Magick::Image *newImage = new Magick::Image(Magick::Geometry(qimage->width(), qimage->height()), Magick::ColorRGB(0.5, 0.2, 0.3));

    double scale = 1 / 256.0;
    newImage->modifyImage();
    Magick::PixelPacket *pixels;
    Magick::ColorRGB mgc;
    for (int y = 0; y < qimage->height(); y++) {
        pixels = newImage->setPixels(0, y, newImage->columns(), 1);
        for (int x = 0; x < qimage->width(); x++) {
            QColor pix = qimage->pixel(x, y);
            //      *pixels++ = Magick::ColorRGB(256 * pix.red(), 256 * pix.green(), 256 * pix.blue());
            mgc.red(scale *pix.red());
            mgc.green(scale *pix.green());
            mgc.blue(scale *pix.blue());
            //      *pixels++ = Magick::ColorRGB(scale *pix.red(), scale * pix.green(), scale * pix.blue());
            *pixels++ = mgc;
        }
        newImage->syncPixels();
    }

    return newImage;
}

QImage *img_obj_converter::to_QImage(Magick::Image *image)
{
    qDebug() << "toQImage:" << image->columns() << image->rows();

    QImage *newQImage = new QImage(image->columns(), image->rows(), QImage::Format_RGB32);
    const Magick::PixelPacket *pixels;
    Magick::ColorRGB rgb;
    for (int y = 0; y < newQImage->height(); y++) {
        pixels = image->getConstPixels(0, y, newQImage->width(), 1);
        for (int x = 0; x < newQImage->width(); x++) {
            rgb = (*(pixels + x));
            newQImage->setPixel(x, y, QColor((int) (255 * rgb.red())
                                             , (int) (255 * rgb.green())
                                             , (int) (255 * rgb.blue())).rgb());
        }
    }
    return newQImage;
}

