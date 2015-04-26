#ifndef CONTRAST_DIALOG_H
#define CONTRAST_DIALOG_H

#include <QDialog>
#include <QMainWindow>
#include "gui/ccimp_dialog.h"
#include "parameters/parameters.h"
#include "parameters/using_slider.h"

namespace Ui {
class contrast_dialog;
}

class contrast_dialog: public QDialog, public ccimp_dialog
{
    Q_OBJECT

public:
    explicit contrast_dialog(QWidget *parent = 0);
    ~contrast_dialog();

signals:
    void signalContrastChanged();

public slots:
    void slotEditFinished() {
        emit signalContrastChanged();
}

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::contrast_dialog *ui;
};

#endif // CONTRAST_DIALOG_H
