#ifndef IMAGE_STATISTICS_H
#define IMAGE_STATISTICS_H

#include <QImage>

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
};

#endif // IMAGE_STATISTICS_H
