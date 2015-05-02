#ifndef SHARPNESS_DIALOG_H
#define SHARPNESS_DIALOG_H

#include <QDialog>

namespace Ui {
class sharpness_dialog;
}

class sharpness_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit sharpness_dialog(QWidget *parent = 0);
    ~sharpness_dialog();

private:
    Ui::sharpness_dialog *ui;
};

#endif // SHARPNESS_DIALOG_H
