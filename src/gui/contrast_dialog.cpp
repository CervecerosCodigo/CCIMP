#include "contrast_dialog.h"
#include "ui_contrast_dialog.h"

contrast_dialog::contrast_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contrast_dialog)
{
    ui->setupUi(this);
    ui->horizontalSlider->setMinimum(-100);
    ui->horizontalSlider->setMaximum(100);
    ui->horizontalSlider->setSingleStep(5);
    ui->horizontalSlider->setTickInterval(10);
    ui->horizontalSlider->setSliderPosition(0);
    ui->horizontalSlider->setTracking(false);
}

contrast_dialog::~contrast_dialog()
{
    delete ui;
}


void contrast_dialog::on_horizontalSlider_valueChanged(int value)
{
    using_slider* param = (using_slider*) tool->get_param();
    param->set_slider_val(ui->horizontalSlider->value());

    emit slotEditFinished();
}
