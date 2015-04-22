#ifndef SLIDER_DIALOG_H
#define SLIDER_DIALOG_H

#endif // SLIDER_DIALOG_H

#include <QSlider>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>

class slider_dialog : public QDialog {

private:
    QVBoxLayout *layout;

    QLabel *label1;
    QLabel *label2;
    QLabel *label3;

    QSlider *slider1;
    QSlider *slider2;
    QSlider *slider3;

public:
    slider_dialog(int antall);
    ~slider_dialog();

};
