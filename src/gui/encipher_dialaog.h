#ifndef ENCIPHER_DIALAOG_H
#define ENCIPHER_DIALAOG_H

#include <QDialog>
#include <QPalette>
#include <QLineEdit>
#include <QMessageBox>
#include "gui/ccimp_dialog.h"
#include "img_tools/image_tool.h"
#include "parameters/parameters.h"
#include "parameters/using_coordinates.h"

namespace Ui {
class encipher_dialaog;
}

class encipher_dialaog : public QDialog, public ccimp_dialog
{
    Q_OBJECT
    QPalette p_white, p_gray;

public:
    explicit encipher_dialaog(QWidget *parent = 0);
    ~encipher_dialaog();

private slots:

    void on_radioEncipher_toggled(bool checked);

    void on_radioDecipher_toggled(bool checked);

    void on_buttonBox_accepted();

signals:
    void signalImageEncrypted();
    void signalImageDecrypted();

public slots:
    void slotEncryptionFinished() {
        emit signalImageEncrypted();
}
    void slotDecryptionFinished() {
        emit signalImageDecrypted();
    }

private:
    Ui::encipher_dialaog *ui;
};

#endif // ENCIPHER_DIALAOG_H
