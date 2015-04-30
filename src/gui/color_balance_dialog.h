#ifndef COLOR_BALANCE_DIALOG_H
#define COLOR_BALANCE_DIALOG_H

#include <QDialog>
#include "gui/ccimp_dialog.h"
#include "parameters/parameters.h"
#include "parameters/using_slider.h"

namespace Ui {
class color_balance_dialog;
}

class color_balance_dialog : public QDialog, public ccimp_dialog
{
    Q_OBJECT

public:
    explicit color_balance_dialog(QWidget *parent = 0);
    ~color_balance_dialog();


signals:
    void signalValueChanged();
    void signalAccepted();
    void signalCanceled();

public slots:
    void slotChanged() {
        emit signalValueChanged();
}
void slotAcceptPressed(){
    emit signalAccepted();               //Pressed OK
}
void slotCancelPressed(){
    emit signalCanceled();               //Pressed Cancel
}

private slots:
    void on_redSlider_valueChanged(int value);
    void on_greenSlider_valueChanged(int value);
    void on_blueSlider_valueChanged(int value);
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::color_balance_dialog *ui;
    void resetting_values() override;
};

#endif // COLOR_BALANCE_DIALOG_H
