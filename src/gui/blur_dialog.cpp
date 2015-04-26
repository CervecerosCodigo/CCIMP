#include "blur_dialog.h"
#include "ui_blur_dialog.h"


blur_dialog::blur_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::blur_dialog)
{
    ui->setupUi(this);
}

blur_dialog::~blur_dialog()
{
    delete ui;
}

void blur_dialog::on_buttonBox_accepted() {

    using_slider* param = (using_slider*)tool->get_param();

    param->set_slider_val(ui->blurSlider->value());
    emit slotEditFinished();

}

void blur_dialog::on_buttonBox_exec() {

}
