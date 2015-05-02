#ifndef AUTO_GAMMA_DIALOG_H
#define AUTO_GAMMA_DIALOG_H

#include <QDialog>
#include "ccimp_dialog.h"

namespace Ui {
class auto_gamma_dialog;
}

class auto_gamma_dialog : public QDialog, public ccimp_dialog
{
    Q_OBJECT

public:
    explicit auto_gamma_dialog(QWidget *parent = 0);
    ~auto_gamma_dialog();

private:
    Ui::auto_gamma_dialog *ui;
};

#endif // AUTO_GAMMA_DIALOG_H
