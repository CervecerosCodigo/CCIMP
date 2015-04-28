#include "encipher_dialaog.h"
#include "ui_encipher_dialaog.h"

encipher_dialaog::encipher_dialaog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::encipher_dialaog)
{
    ui->setupUi(this);



    p_gray = ui->decPass->palette();
    p_gray.setColor(QPalette::Base, Qt::gray);
    p_white = ui->encPass1->palette();
    p_white.setColor(QPalette::Base, Qt::white);

    ui->radioEncipher->toggle();
    //    this->on_radioEncipher_toggled(true);
}

encipher_dialaog::~encipher_dialaog()
{
    delete ui;
}


void encipher_dialaog::on_radioEncipher_toggled(bool checked)
{
    ui->encPass1->setEnabled(true);
    ui->encPass2->setEnabled(true);
    ui->decPass->setEnabled(false);
    ui->decPass->setPalette(p_gray);
    ui->encPass1->setPalette(p_white);
    ui->encPass2->setPalette(p_white);
    ui->decPass->setText("");
}

void encipher_dialaog::on_radioDecipher_toggled(bool checked)
{
    ui->encPass1->setEnabled(false);
    ui->encPass2->setEnabled(false);
    ui->decPass->setEnabled(true);
    ui->encPass1->setPalette(p_gray);
    ui->encPass2->setPalette(p_gray);
    ui->decPass->setPalette(p_white);
    ui->encPass1->setText("");
    ui->encPass2->setText("");
}

void encipher_dialaog::on_buttonBox_accepted()
{

    if(ui->radioEncipher->isChecked()){
        if(ui->encPass1->text().compare(ui->encPass2->text())){
            QMessageBox::warning(this, "Password error", "Passwords doesn't match");
        }
        qDebug() << "emit signalImageDecrypted()";
        emit slotEncryptionFinished();
    }else if(ui->radioDecipher->isChecked()){
        qDebug() << "emit signalImageDecrypted()";
        emit signalImageDecrypted();
    }
}
