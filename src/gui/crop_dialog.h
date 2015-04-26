#ifndef CROP_DIALOG_H
#define CROP_DIALOG_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <vector>
#include "gui/ccimp_dialog.h"
#include "img_tools/image_tool.h"
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
    std::vector<int> crop_values;

public:
    explicit crop_dialog(QWidget *parent = 0);
    ~crop_dialog();

    const std::vector<int>& get_crop_values();

signals:
  void signalNewString1(QString val);

public slots:
  void slotEditFinished()
  {
    // connect this in the ctor as described
    emit signalNewString1(QString("Text from crop dialog"));
  }



private slots:
  void on_buttonBox_accepted();
  void on_buttonBox_exec();

private:
    Ui::crop_dialog *ui;
};

#endif // CROP_DIALOG_H
