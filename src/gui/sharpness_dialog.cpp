#include "sharpness_dialog.h"
#include "ui_sharpness_dialog.h"

sharpness_dialog::sharpness_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sharpness_dialog)
{
    ui->setupUi(this);
}

sharpness_dialog::~sharpness_dialog()
{
    delete ui;
}
