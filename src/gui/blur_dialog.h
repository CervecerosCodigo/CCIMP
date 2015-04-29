#ifndef BLUR_DIALOG_H
#define BLUR_DIALOG_H

#include <QDialog>
#include <QDebug>
#include "ccimp_dialog.h"
#include "parameters/using_slider.h"
#include "img_tools/image_tool.h"

namespace Ui {
class blur_dialog;
}

class blur_dialog : public QDialog, public ccimp_dialog
{
    Q_OBJECT

public:
    explicit blur_dialog(QWidget *parent = 0);
    ~blur_dialog();

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
    Ui::blur_dialog *ui;
    void reset_slider_positions();
};

#endif // BLUR_DIALOG_H
