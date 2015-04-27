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
    void signalColorBalanceChanged();

public slots:
    void slotEditFinished() {
        emit signalColorBalanceChanged();
}

private slots:
    void on_redSlider_valueChanged(int value);

    void on_greenSlider_valueChanged(int value);

    void on_blueSlider_valueChanged(int value);

private:
    Ui::color_balance_dialog *ui;
};

#endif // COLOR_BALANCE_DIALOG_H
