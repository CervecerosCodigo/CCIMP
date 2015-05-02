#ifndef SHARPNESS_DIALOG_H
#define SHARPNESS_DIALOG_H

#include <QDialog>
#include "ccimp_dialog.h"
#include "parameters/using_slider.h"
#include "img_tools/image_tool.h"

namespace Ui {
class sharpness_dialog;
}

class sharpness_dialog : public QDialog, public ccimp_dialog
{
    Q_OBJECT

public:
    explicit sharpness_dialog(QWidget *parent = 0);
    ~sharpness_dialog();

signals:
  void signalValueChanged();
  void signalAccepted();
  void signalCanceled();

public slots:
  void slotChanged() {
    emit signalValueChanged();
  }
  void slotAcceptPressed(){
      signalAccepted();               //Pressed OK
  }
  void slotCancelPressed(){
      signalCanceled();               //Pressed Cancel
  }

private slots:
  void on_radiusSlider_valueChanged(int value);
  void on_intensitySlider_valueChanged(int value);
  void on_buttonBox_accepted();
  void on_buttonBox_rejected();

private:
    Ui::sharpness_dialog *ui;
    void resetting_values() override;
};

#endif // SHARPNESS_DIALOG_H
