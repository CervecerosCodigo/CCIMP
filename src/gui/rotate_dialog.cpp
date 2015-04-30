#include "rotate_dialog.h"
#include "ui_rotate_dialog.h"

rotate_dialog::rotate_dialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::rotate_dialog)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->dial->setTracking(false);
    current_angle = 0.0;
}

rotate_dialog::~rotate_dialog()
{
    delete ui;
}

void rotate_dialog::rotate_left()
{
    using_coordinates* param = (using_coordinates*) tool->get_param();
    param->set_angle(current_angle-=90.0);

    emit slotChanged();

}

void rotate_dialog::rotate_right()
{
    using_coordinates* param = (using_coordinates*) tool->get_param();
    param->set_angle(current_angle+=90.0);

    emit slotChanged();

}

void rotate_dialog::on_dial_valueChanged(int value)
{
    if(!protecting_value_changed){
        using_coordinates* param = (using_coordinates*) tool->get_param();
        param->set_angle(ui->dial->value()*1.0);
        emit slotChanged();
    }
}

void rotate_dialog::on_buttonBox_accepted()
{
    emit slotAcceptPressed();
    protecting_value_changed = true;
    resetting_values();
    protecting_value_changed = false;
}



void rotate_dialog::on_buttonBox_rejected()
{

    emit slotCancelPressed();
    protecting_value_changed = true;
    resetting_values();
    protecting_value_changed = false;

}

void rotate_dialog::resetting_values(){
    ui->dial->setValue(0.0);
    current_angle = 0.0;
}
