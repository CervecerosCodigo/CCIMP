#ifndef CROP_DIALOG_H
#define CROP_DIALOG_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <vector>
#include "model/image_tool.h"
#include "model/parameters.h"
#include "model/parameter_using_coordiantes.h"

namespace Ui {
class crop_dialog;
}

class crop_dialog : public QDialog
{
    Q_OBJECT

    int width, height, x_offset, y_offset;
    std::vector<int> crop_values;
    image_tool* tool;

public:
    explicit crop_dialog(QWidget *parent = 0);
    ~crop_dialog();

    const std::vector<int>& get_crop_values();
    void set_tool(image_tool* t);
    image_tool* get_tool();

signals:
  void signalNewString1(QString val);

public slots:
  void slotEditFinished()
  {
    // connect this in the ctor as described
    emit signalNewString1(QString("Text from crop dialog"));
  }



private slots:
  void on_pushButton_clicked();
  void on_buttonBox_accepted();
  void on_buttonBox_exec();

private:
    Ui::crop_dialog *ui;
};

#endif // CROP_DIALOG_H
