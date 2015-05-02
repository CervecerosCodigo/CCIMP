#ifndef SCALE_DIALOG_H
#define SCALE_DIALOG_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include "gui/ccimp_dialog.h"
#include "img_tools/image_tool.h"
#include "parameters/parameters.h"
#include "parameters/using_coordinates.h"

namespace Ui {
class scale_dialog;
}

class scale_dialog : public QDialog, public ccimp_dialog
{
    Q_OBJECT

    int width, height, x_offset, y_offset;

public:
    explicit scale_dialog(QWidget *parent = 0);
    ~scale_dialog();

signals:
    void signalAccepted();

public slots:

    void slotAcceptPressed(){
        signalAccepted();               //Pressed OK
    }


private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::scale_dialog *ui;
    void resetting_values() override;
};

#endif // SCALE_DIALOG_H
