#include "brightness_dialog.h"
#include "ui_brightness_dialog.h"


brightness_dialog::brightness_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::brightness_dialog)
{
    ui->setupUi(this);
    ui->horizontalSlider->setMinimum(-100);
    ui->horizontalSlider->setMaximum(100);
    ui->horizontalSlider->setSingleStep(5);
    ui->horizontalSlider->setTickInterval(10);
    ui->horizontalSlider->setSliderPosition(0);
    ui->horizontalSlider->setValue(0);
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

//    emit signalBrightnessChanged();
    using_slider* param = (using_slider*) tool->get_param();
    param->set_slider_val(ui->horizontalSlider->value());
    //qDebug() << Q_FUNC_INFO << param->get_slider_val();

    emit slotEditFinished();
}
