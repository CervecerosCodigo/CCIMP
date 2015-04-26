#ifndef BLUR_DIALOG_H
#define BLUR_DIALOG_H

#include <QDialog>

namespace Ui {
class blur_dialog;
}

class blur_dialog : public QDialog
{
    Q_OBJECT

    image_tool* tool;

public:
    explicit blur_dialog(QWidget *parent = 0);
    ~blur_dialog();

    void set_tool(image_tool* t);
    image_tool* get_tool();

private:
    Ui::blur_dialog *ui;
};

#endif // BLUR_DIALOG_H
