#ifndef CALLBACK_IFACE
#define CALLBACK_IFACE

#include <QImage>
#include <QString>

class callback_iface{

public:
    callback_iface(){}
    virtual ~callback_iface(){}

    virtual void callback_image_edited(QImage* img) = 0;    //brukes for å sende oppdatert bilde til gui
    virtual void callback_report_image_is_original() = 0;   //rapporter til gui at bildet er tilbake til orginal format
    virtual callback_iface* get_callback_listener() = 0;    //returnerer en instans av MainWindow i form av callback-interfacet
};

#endif // CALLBACK_IFACE

