#include "blur_dialog.h"
#include "ui_blur_dialog.h"

blur_dialog::blur_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::blur_dialog)
{
    ui->setupUi(this);
}

blur_dialog::~blur_dialog()
{
    delete ui;
}
