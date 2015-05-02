#include "auto_level_dialog.h"
#include "ui_auto_level_dialog.h"

auto_level_dialog::auto_level_dialog(QWidget *parent) : QDialog(parent), ui(new Ui::auto_level_dialog)
{
    ui->setupUi(this);
}

auto_level_dialog::~auto_level_dialog()
{
    delete ui;
}

void auto_level_dialog::resetting_values()
{

}
