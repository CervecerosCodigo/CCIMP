#ifndef CROP_DIALOG_H
#define CROP_DIALOG_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <vector>

namespace Ui {
class crop_dialog;
}

class crop_dialog : public QDialog
{
    Q_OBJECT

    int width, height, x_offset, y_offset;
    std::vector<int> crop_values;

public:
    explicit crop_dialog(QWidget *parent = 0);
    ~crop_dialog();
    QString getStringValue();
    void on_buttonBox_accepted();

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

private:
    Ui::crop_dialog *ui;
};

#endif // CROP_DIALOG_H
