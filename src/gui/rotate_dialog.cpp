#include "rotate_dialog.h"
#include "ui_rotate_dialog.h"

rotate_dialog::rotate_dialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::rotate_dialog)
{
    ui->setupUi(this);
    ui->dial->setTracking(false);
}

rotate_dialog::~rotate_dialog()
{
    delete ui;
}

void rotate_dialog::rotate_left()
{
    using_coordinates* param = (using_coordinates*) tool->get_param();
    param->set_angle(-90.0);

    emit slotEditFinished();
}

void rotate_dialog::rotate_right()
{
    using_coordinates* param = (using_coordinates*) tool->get_param();
    param->set_angle(90.0);

    emit slotEditFinished();
}

void rotate_dialog::on_dial_valueChanged(int value)
{
    using_coordinates* param = (using_coordinates*) tool->get_param();
    param->set_angle(ui->dial->value()*1.0);

    emit slotEditFinished();
}
