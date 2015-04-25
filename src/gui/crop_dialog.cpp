#include "crop_dialog.h"
#include "ui_crop_dialog.h"

crop_dialog::crop_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::crop_dialog)
{
    ui->setupUi(this);
    ui->lineEdit->setText("100");
    ui->lineEdit_2->setText("100");
    ui->lineEdit_3->setText("100");
    ui->lineEdit_4->setText("100");


}

crop_dialog::~crop_dialog()
{
    delete ui;
}

const std::vector<int> &crop_dialog::get_crop_values()
{
    return crop_values;
}




void crop_dialog::on_buttonBox_accepted()
{

    parameter_using_coordiantes* param = (parameter_using_coordiantes*)tool->get_param();
    param->set_width(ui->lineEdit->text().toInt());
    param->set_height(ui->lineEdit_2->text().toInt());
    param->set_x_axis(ui->lineEdit_3->text().toInt());
    param->set_y_axis(ui->lineEdit_4->text().toInt());

//    width = ui->lineEdit->text().toInt();
//    height = ui->lineEdit_2->text().toInt();
//    x_offset = ui->lineEdit_3->text().toInt();
//    y_offset = ui->lineEdit_4->text().toInt();

//    crop_values.push_back(width);
//    crop_values.push_back(height);
//    crop_values.push_back(x_offset);
//    crop_values.push_back(y_offset);


    emit slotEditFinished();
}

void crop_dialog::on_buttonBox_exec()
{
    qDebug () << "Apply button";
}

void crop_dialog::on_pushButton_clicked()
{

}

void crop_dialog::set_tool(image_tool *t){
    tool = t;
}

image_tool* crop_dialog::get_tool(){
    return tool;
}
