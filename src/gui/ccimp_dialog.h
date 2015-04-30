#ifndef CCIMP_DIALOG_H
#define CCIMP_DIALOG_H

#include <QDebug>
#include "img_tools/image_tool.h"


//! A base class for all dialogs
class ccimp_dialog {

protected:
    image_tool* tool;
    bool protecting_value_changed = false;

public:
    ccimp_dialog(){}
    virtual ~ccimp_dialog(){}

    inline virtual void set_tool(image_tool *t)
    {
        tool=t;
    }

    inline virtual image_tool* get_tool()
    {
        return tool;
    }

    inline virtual void prepare_and_run_reset_on_values(){
        protecting_value_changed = true;
        resetting_values();
        protecting_value_changed = false;
    }

    virtual void resetting_values() = 0;

};

#endif // CCIMP_DIALOG_H

