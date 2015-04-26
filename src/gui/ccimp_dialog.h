#ifndef CCIMP_DIALOG_H
#define CCIMP_DIALOG_H

#include <QDebug>
#include "img_tools/image_tool.h"


//! A base class for all dialogs
class ccimp_dialog {

protected:
    image_tool* tool;

public:
    ccimp_dialog(){}
    virtual ~ccimp_dialog(){}

    inline virtual void set_tool(image_tool *t)
    {
        qDebug() << Q_FUNC_INFO << "kjører set_tool";
        tool=t;
    }

    inline virtual image_tool* get_tool()
    {
        return tool;
    }
};

#endif // CCIMP_DIALOG_H

