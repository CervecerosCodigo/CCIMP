#include "color_balance_dialog.h"
#include "ui_color_balance_dialog.h"

color_balance_dialog::color_balance_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::color_balance_dialog)
{
    ui->setupUi(this);

    ui->redSlider->setTracking(false);
    ui->greenSlider->setTracking(false);
    ui->blueSlider->setTracking(false);

    ui->redSlider->setMinimum(-100);
    ui->redSlider->setMaximum(100);
    ui->redSlider->setSliderPosition(0);
    ui->redSlider->setValue(0);

    ui->greenSlider->setMinimum(-100);
    ui->greenSlider->setMaximum(100);
    ui->greenSlider->setSliderPosition(0);
    ui->greenSlider->setValue(0);

    ui->blueSlider->setMinimum(-100);
    ui->blueSlider->setMaximum(100);
    ui->blueSlider->setSliderPosition(0);
    ui->blueSlider->setValue(0);

}

color_balance_dialog::~color_balance_dialog()
{
    delete ui;
}

void color_balance_dialog::on_redSlider_valueChanged(int value)
{
    using_slider* param = (using_slider*) tool->get_param();
    param->set_slider_val(0, ui->redSlider->value());

    emit slotEditFinished();
}

void color_balance_dialog::on_greenSlider_valueChanged(int value)
{
    using_slider* param = (using_slider*) tool->get_param();
    param->set_slider_val(1, ui->greenSlider->value());

    emit slotEditFinished();
}

void color_balance_dialog::on_blueSlider_valueChanged(int value)
{
    using_slider* param = (using_slider*) tool->get_param();
    param->set_slider_val(2, ui->blueSlider->value());

    emit slotEditFinished();
}
