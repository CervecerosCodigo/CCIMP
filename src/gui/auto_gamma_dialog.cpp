#include "auto_gamma_dialog.h"
#include "ui_auto_gamma_dialog.h"

auto_gamma_dialog::auto_gamma_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::auto_gamma_dialog)
{
    ui->setupUi(this);

}

auto_gamma_dialog::~auto_gamma_dialog()
{
    delete ui;
}

void auto_gamma_dialog::resetting_values()
{

}
