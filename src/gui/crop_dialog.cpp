#include "crop_dialog.h"
#include "ui_crop_dialog.h"

crop_dialog::crop_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::crop_dialog)
{
    ui->setupUi(this);
}

crop_dialog::~crop_dialog()
{
    delete ui;
}
