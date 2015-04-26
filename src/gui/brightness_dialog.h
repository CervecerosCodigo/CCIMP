#ifndef BRIGHTNESS_DIALOG_H
#define BRIGHTNESS_DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMainWindow>
#include "gui/ccimp_dialog.h"
#include "parameters/parameters.h"
#include "parameters/using_slider.h"

namespace Ui {
class brightness_dialog;
}

class brightness_dialog : public QDialog, public ccimp_dialog
{
    Q_OBJECT

public:
    explicit brightness_dialog(QWidget *parent = 0);
    ~brightness_dialog();
    const int& get_slider_value();

signals:
    void signalBrightnessChanged();

public slots:
    void slotEditFinished() {
        emit signalBrightnessChanged();
}

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::brightness_dialog *ui;
    int value, new_value;
};

#endif // BRIGHTNESS_DIALOG_H
