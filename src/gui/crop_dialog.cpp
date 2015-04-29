#include "crop_dialog.h"
#include "ui_crop_dialog.h"

crop_dialog::crop_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::crop_dialog)
{
    ui->setupUi(this);
    reset_input_fields();
}

crop_dialog::~crop_dialog()
{
    delete ui;
}


void crop_dialog::on_buttonBox_accepted()
{

    using_coordinates* param = (using_coordinates*)tool->get_param();
    param->set_width(ui->lineEdit->text().toInt());
    param->set_height(ui->lineEdit_2->text().toInt());
    param->set_x_axis(ui->lineEdit_3->text().toInt());
    param->set_y_axis(ui->lineEdit_4->text().toInt());

    emit slotAcceptPressed();
    reset_input_fields();
}


void crop_dialog::reset_input_fields(){
    ui->lineEdit->setText("0");
    ui->lineEdit_2->setText("0");
    ui->lineEdit_3->setText("0");
    ui->lineEdit_4->setText("0");
}
