#include "encipher_dialaog.h"
#include "ui_encipher_dialaog.h"

encipher_dialaog::encipher_dialaog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::encipher_dialaog)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());

    QButtonGroup *group = new QButtonGroup(this);
    group->addButton(ui->radioEncipher);
    group->addButton(ui->radioDecipher);


    p_gray = ui->decPass->palette();
    p_gray.setColor(QPalette::Base, Qt::gray);
    p_white = ui->encPass1->palette();
    p_white.setColor(QPalette::Base, Qt::white);

    //    ui->radioEncipher->toggle(); //må vente til alt har startet før denne settes, lager en setter.
    //    this->on_radioEncipher_toggled(true);

}

encipher_dialaog::~encipher_dialaog()
{
    delete ui;
}

void encipher_dialaog::set_encipher_toggle_on()
{
    ui->radioEncipher->toggle();
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
    //Henter tool value for å se dersom den skal krypteres eller dekrypteres
    param = (using_text*) tool->get_param();
    //setter krypteringsparameter
    param->set_is_encryption(true);
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
    //Henter tool value for å se dersom den skal krypteres eller dekrypteres
    param = (using_text*) tool->get_param();
    //setter dekrypteringsparameter
    param->set_is_encryption(false);
}

void encipher_dialaog::on_buttonBox_accepted()
{

    if(ui->radioEncipher->isChecked()){
        if(ui->encPass1->text().compare(ui->encPass2->text())){
            QMessageBox::warning(this, "Password error", "Passwords doesn't match");
        }else{
            qDebug() << "emit signalImageEncrypted()";

            emit slotEncryptionFinished();
        }

    }else if(ui->radioDecipher->isChecked()){
        qDebug() << "emit signalImageDecrypted()";

        emit slotDecryptionFinished();
    }
}

void encipher_dialaog::resetting_values(){

}
