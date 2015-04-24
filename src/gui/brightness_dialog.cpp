#include "brightness_dialog.h"
#include "ui_brightness_dialog.h"

brightness_dialog::brightness_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::brightness_dialog)
{
    ui->setupUi(this);
    ui->horizontalSlider->setSliderPosition(50);
}

brightness_dialog::~brightness_dialog()
{
    delete ui;
}


void brightness_dialog::on_horizontalSlider_valueChanged(int value)
{
    this->value = value;
    emit signalBrightnessChanged(this->value);
}
