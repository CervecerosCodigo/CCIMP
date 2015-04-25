#include "brightness_dialog.h"
#include "ui_brightness_dialog.h"

brightness_dialog::brightness_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::brightness_dialog)
{
    ui->setupUi(this);
    ui->horizontalSlider->setSliderPosition(50);
    ui->horizontalSlider->setTracking(false);
}

brightness_dialog::~brightness_dialog()
{
    delete ui;
}

const int &brightness_dialog::get_slider_value()
{
    return ui->horizontalSlider->value();
}


void brightness_dialog::on_horizontalSlider_valueChanged(int value)
{
 qDebug() << "brigtness_slider_actionChanged" << ui->horizontalSlider->value();
    emit signalBrightnessChanged();
}
