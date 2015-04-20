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
}


/*
 * @FIXME: Data blir skrevet ut i reverse order
 */
QString image_statistics::get_img_stat(const QPixmap &img)
{
    this->img = img;

    create_img_stats();
    QString img_stat;
    img_stat = "<html>";

    while(stats_container.size()>0){
        pair<QString, QString> tmp_par = stats_container.top();
        stats_container.pop();
        img_stat += tmp_par.first + ": " + tmp_par.second + "<br>";
    }

    img_stat+="</html>";
    return img_stat;
}




