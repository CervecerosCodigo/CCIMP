#ifndef IMAGE_STATISTICS_H
#define IMAGE_STATISTICS_H

#include <QPixmap>
#include <QString>

class image_statistics
{
    QImage img;

    int width;
    int height;
    int depth;
    int byte_count;

    qint64 cache_key;   //hvert bilde har en cacheKey, som endres når bildet endres.

public:
    image_statistics();
    ~image_statistics();
    static QString get_img_stat(const QPixmap&);
    static const char* get_img_stat2();
    static const char* get_img_stat3();
    /*
     * Her må vi huske at dette er bare på test.
     * Det hadde vært fint å lage versjon der vi sender inn
     * en referanse til en QImage til en template og mottar tilbake
     * en vector<key<char&, char&>> og deretter oprette en QString
     * som kan returneres til GUI
     */
};

#endif // IMAGE_STATISTICS_H
