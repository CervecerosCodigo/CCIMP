#ifndef CROP_DIALOG_H
#define CROP_DIALOG_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include "gui/ccimp_dialog.h"
#include "img_tools/image_tool.h"
#include "parameters/parameters.h"
#include "parameters/using_coordinates.h"

namespace Ui {
class crop_dialog;
}

class crop_dialog : public QDialog, public ccimp_dialog
{
    Q_OBJECT

    int width, height, x_offset, y_offset;

public:
    explicit crop_dialog(QWidget *parent = 0);
    ~crop_dialog();


signals:
  void signalAccepted();

public slots:

  void slotAcceptPressed(){
      signalAccepted();               //Pressed OK
  }


private slots:
  void on_buttonBox_accepted();


private:
    Ui::crop_dialog *ui;
    void reset_input_fields();
};

#endif // CROP_DIALOG_H
