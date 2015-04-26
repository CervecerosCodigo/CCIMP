#include "blur_dialog.h"
#include "ui_blur_dialog.h"


blur_dialog::blur_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::blur_dialog)
{
    ui->setupUi(this);
    ui->horizontalSlider->setTracking(false);
}

blur_dialog::~blur_dialog()
{
    delete ui;
}


void blur_dialog::on_horizontalSlider_valueChanged(int value)
{
    using_slider* param = (using_slider*)tool->get_param();
    //qDebug() << "blur sin verdi endret";
    param->set_slider_val(ui->horizontalSlider->value());
    emit slotEditFinished();
}
