#ifndef ROTATE_DIALOG_H
#define ROTATE_DIALOG_H

#include <QDialog>
#include "gui/ccimp_dialog.h"
#include "img_tools/image_tool.h"
#include "parameters/parameters.h"
#include "parameters/using_coordinates.h"

namespace Ui {
class rotate_dialog;
}

class rotate_dialog : public QDialog, public ccimp_dialog
{
    Q_OBJECT

public:
    explicit rotate_dialog(QWidget *parent = 0);
    ~rotate_dialog();

    //Hardkodet rotasjon som brukes fra main panel i main window
    void rotate_left();
    void rotate_right();

signals:
    void signalRotationChanged();

public slots:
    void slotEditFinished() {
        emit signalRotationChanged();
}

private slots:
    void on_dial_valueChanged(int value);

private:
    Ui::rotate_dialog *ui;
};

#endif // ROTATE_DIALOG_H
