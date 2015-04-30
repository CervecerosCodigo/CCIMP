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
    void signalValueChanged();
    void signalAccepted();
    void signalCanceled();

public slots:

    void slotChanged() {
            emit signalValueChanged();
    }
    void slotAcceptPressed(){
        signalAccepted();               //Pressed OK
    }
    void slotCancelPressed(){
        signalCanceled();               //Pressed Cancel
    }

private slots:
    void on_dial_valueChanged(int value);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::rotate_dialog *ui;
    double current_angle;
    void resetting_values() override;
};

#endif // ROTATE_DIALOG_H
