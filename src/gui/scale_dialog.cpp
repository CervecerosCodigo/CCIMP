#include "scale_dialog.h"
#include "ui_scale_dialog.h"

scale_dialog::scale_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scale_dialog)
{
    ui->setupUi(this);

    ui->horizontalSlider->setTracking(false);

    /*
     * Det er noe som gjør at disse får vi ikke endret under boot.
     * Det blir en nullpointer av ukjente årsaker. Har derfor lagd en
     * setter for de verdiene som settes fra main window
     */

    this->setFixedSize(this->size());

    resetting_values();
}

scale_dialog::~scale_dialog()
{
    delete ui;
}

void scale_dialog::set_normal_slider_position()
{
    ui->horizontalSlider->setSliderPosition(100);
    ui->horizontalSlider->setValue(100);
}

void scale_dialog::on_horizontalSlider_valueChanged(int value)
{
    if(!protecting_value_changed){
        using_slider* param = (using_slider*) tool->get_param();
        param->set_slider_val(ui->horizontalSlider->value());
        emit slotChanged();
    }
}

void scale_dialog::on_buttonBox_accepted()
{
    prepare_and_run_reset_on_values();
    emit slotAcceptPressed();
}

void scale_dialog::on_buttonBox_rejected()
{
    emit slotCancelPressed();
    prepare_and_run_reset_on_values();
}

void scale_dialog::resetting_values(){
    ui->horizontalSlider->setValue(0);
}

