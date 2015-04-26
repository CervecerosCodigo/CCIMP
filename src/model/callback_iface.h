#ifndef CALLBACK_IFACE
#define CALLBACK_IFACE

#include <QImage>

class callback_iface{

public:
    callback_iface(){}
    ~callback_iface(){}

    virtual void callback_image_edited(QImage* img) = 0;
};

#endif // CALLBACK_IFACE

