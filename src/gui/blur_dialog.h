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

    image_tool* tool;

public:
    explicit blur_dialog(QWidget *parent = 0);
    ~blur_dialog();

signals:
  void signalBlurChanged();

public slots:
  void slotEditFinished() {
    emit signalBlurChanged();
  }

private slots:
  void on_buttonBox_accepted();
  void on_buttonBox_exec();

private:
    Ui::blur_dialog *ui;
};

#endif // BLUR_DIALOG_H
