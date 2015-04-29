#ifndef IMAGE_STATISTICS_H
#define IMAGE_STATISTICS_H

#include <QPixmap>
#include <QImage>
#include <QString>
#include <QDebug>

#include "controller/data_key_value_container.h"


class image_statistics
{
    data_key_value_container<QString, QString> stats_container;
    QImage img; //jeg får ikke ut noen data fra QImage. Bruker QPixmap til videre.


    /** Private function to be called from a other public
     * member funtion with return type.
     *
     * This function populates the stats_container.
     * @brief create_img_stats
     */
    void create_img_stats();

    int width;
    int height;
    int depth;
    int byte_count;

    qint64 cache_key;   //hvert bilde har en cacheKey, som endres når bildet endres.

public:
    image_statistics();
    ~image_statistics();
    QString get_img_stat(const QImage&);

};

#endif // IMAGE_STATISTICS_H
