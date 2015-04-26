#ifndef CCIMP_DIALOG_H
#define CCIMP_DIALOG_H

#include<model/image_tool.h>

//! A base class for all dialogs
class ccimp_dialog {

protected:
    image_tool* tool;

public:
    ccimp_dialog(){}
    virtual ~ccimp_dialog(){}

    virtual void set_tool(image_tool *t)
    {
        tool=t;
    }

    virtual image_tool* get_tool()
    {
        return tool;
    }
};

#endif // CCIMP_DIALOG_H

