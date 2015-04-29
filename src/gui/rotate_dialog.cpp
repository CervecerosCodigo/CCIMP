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
    using_coordinates* param = (using_coordinates*) tool->get_param();
    param->set_angle(ui->dial->value()*1.0);

    emit slotChanged();
}

void rotate_dialog::on_buttonBox_accepted()
{
    emit slotAcceptPressed();
    ui->dial->setValue(0.0);
    current_angle = 0.0;
}



void rotate_dialog::on_buttonBox_rejected()
{
    emit slotCancelPressed();
    ui->dial->setValue(0.0);
    current_angle = 0.0;
}
