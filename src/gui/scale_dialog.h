#ifndef SCALE_DIALOG_H
#define SCALE_DIALOG_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include "gui/ccimp_dialog.h"
#include "img_tools/image_tool.h"
#include "parameters/using_slider.h"

namespace Ui {
class scale_dialog;
}

class scale_dialog : public QDialog, public ccimp_dialog
{
    Q_OBJECT

public:
    explicit scale_dialog(QWidget *parent = 0);
    ~scale_dialog();
    void set_normal_slider_position();

signals:
    void signalValueChanged();
    void signalAccepted();
    void signalCanceled();

public slots:
    void slotChanged() {
        emit signalValueChanged(); //Slider value changed
    }

    void slotAcceptPressed(){
        signalAccepted();               //Pressed OK
    }

    void slotCancelPressed(){
        signalCanceled();               //Pressed Cancel
    }

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::scale_dialog *ui;
    void resetting_values() override;
};

#endif // SCALE_DIALOG_H
