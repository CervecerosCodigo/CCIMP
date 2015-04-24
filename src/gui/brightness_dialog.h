#ifndef BRIGHTNESS_DIALOG_H
#define BRIGHTNESS_DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMainWindow>

namespace Ui {
class brightness_dialog;
}

class brightness_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit brightness_dialog(QWidget *parent = 0);
    ~brightness_dialog();

signals:
    void signalBrightnessChanged(int i);

public slots:
    void slotEditFinished() {
        emit signalBrightnessChanged(this->value);
}

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::brightness_dialog *ui;
    int value;
};

#endif // BRIGHTNESS_DIALOG_H
