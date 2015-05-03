#include "brightness_dialog.h"
#include "ui_brightness_dialog.h"


brightness_dialog::brightness_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::brightness_dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Brightness");
    ui->horizontalSlider->setMinimum(-100);
    ui->horizontalSlider->setMaximum(100);
    ui->horizontalSlider->setSingleStep(5);
    ui->horizontalSlider->setTickInterval(10);
    ui->horizontalSlider->setSliderPosition(0);
    ui->horizontalSlider->setValue(0);
    ui->horizontalSlider->setTracking(false);
    this->setFixedSize(this->size());
}

brightness_dialog::~brightness_dialog()
{
    delete ui;
}


void brightness_dialog::on_horizontalSlider_valueChanged(int value)
{
    if(!protecting_value_changed){
        using_slider* param = (using_slider*) tool->get_param();
        param->set_slider_val(ui->horizontalSlider->value());
        emit slotChanged();
    }
}

void brightness_dialog::on_buttonBox_accepted()
{
    prepare_and_run_reset_on_values();
    emit slotAcceptPressed();
}

void brightness_dialog::on_buttonBox_rejected()
{
    emit slotCancelPressed();
    prepare_and_run_reset_on_values();
}

void brightness_dialog::resetting_values(){
    ui->horizontalSlider->setValue(0);
}
