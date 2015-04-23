#ifndef CROP_DIALOG_H
#define CROP_DIALOG_H

#include <QDialog>

namespace Ui {
class crop_dialog;
}

class crop_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit crop_dialog(QWidget *parent = 0);
    ~crop_dialog();

private:
    Ui::crop_dialog *ui;
};

#endif // CROP_DIALOG_H
