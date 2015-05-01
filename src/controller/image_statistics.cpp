#include "image_statistics.h"

image_statistics::image_statistics()
{

}

image_statistics::~image_statistics()
{

}

void image_statistics::create_img_stats()
{
    stats_container.push("Width", QString::number(img.width()));
    stats_container.push("Height", QString::number(img.height()));
    stats_container.push("Width mm", QString::number(img.widthMM()));
    stats_container.push("Height mm", QString::number(img.heightMM()));
    stats_container.push("Greyscale", QString(img.isGrayscale()?"Yes":"No"));
    stats_container.push("Aphachanel", QString(img.hasAlphaChannel()?"Yes":"No"));
    stats_container.push("Aphachanel", QString(img.hasAlphaChannel()?"Yes":"No"));
}


/*
 * @FIXME: Data blir skrevet ut i reverse order
 */
QString image_statistics::get_img_stat(const QImage &img)
{
    using namespace std;

    this->img = img;

    create_img_stats();
    QString img_stat;
    img_stat = "<html cellspacing='0'>"
               "<table style='border-spacing:0; border-collapse: collapse;'>"
               "<tr>"
               "<td style='padding:0px;'>"
               "<b><u>Metadata<br></b></u>"
               "</td><td></td></tr>";

    while(stats_container.size()>0){
//        pair<QString, QString> tmp_par = stats_container.last();
        pair<QString, QString> tmp_par = stats_container.first();
//        stats_container.pop();
        stats_container.pop_first();
        img_stat += "<tr><td><b>"+
                tmp_par.first +
                ": </b></td><td>" +
                tmp_par.second + "<br></td></tr>";
    }

    img_stat+="</table></html>";
    return img_stat;
}




