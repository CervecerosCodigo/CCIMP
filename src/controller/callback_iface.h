#ifndef CALLBACK_IFACE
#define CALLBACK_IFACE

#include <QImage>
#include <QString>

class callback_iface{

public:
    callback_iface(){}
    virtual ~callback_iface(){}

    virtual void callback_image_edited(QImage* img) = 0;
    virtual callback_iface* get_callback_listener() = 0;
};

#endif // CALLBACK_IFACE

