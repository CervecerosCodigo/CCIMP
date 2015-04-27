#include "blur_dialog.h"
#include "ui_blur_dialog.h"


blur_dialog::blur_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::blur_dialog)
{
    ui->setupUi(this);
    ui->radiusSlider->setTracking(false);
    ui->intensitySlider->setTracking(false);

    ui->radiusSlider->setMinimum(0);
    ui->radiusSlider->setMaximum(100);

    ui->intensitySlider->setMinimum(0);
    ui->intensitySlider->setMaximum(100);
}

blur_dialog::~blur_dialog()
{
    delete ui;
}

void blur_dialog::on_radiusSlider_valueChanged(int value)
{
    using_slider* param = (using_slider*)tool->get_param();
    param->set_slider_val(0, ui->radiusSlider->value());

    emit slotEditFinished();
}

void blur_dialog::on_intensitySlider_valueChanged(int value)
{
    using_slider* param = (using_slider*)tool->get_param();
    param->set_slider_val(1, ui->intensitySlider->value());

    emit slotEditFinished();
}
