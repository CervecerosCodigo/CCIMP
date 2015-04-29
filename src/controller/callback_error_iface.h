#ifndef CALLBACK_ERROR_IFACE_H
#define CALLBACK_ERROR_IFACE_H

#include <QString>

class callback_error_iface{
public:
    callback_error_iface(){}
    ~callback_error_iface(){}

    virtual void exception_in_image_processing(QString err_title, QString err_msg)=0;
};


#endif // CALLBACK_ERROR_IFACE_H

