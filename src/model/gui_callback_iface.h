#ifndef GUI_CALLBACK_IFACE
#define GUI_CALLBACK_IFACE

#include <QImage>

class gui_callback_iface{

public:
    gui_callback_iface(){}
    ~gui_callback_iface(){}

    virtual void callback_image_edited(QImage* img) = 0;
};

#endif // GUI_CALLBACK_IFACE

