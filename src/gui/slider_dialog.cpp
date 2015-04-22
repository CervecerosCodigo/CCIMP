#include "slider_dialog.h"

slider_dialog::slider_dialog(int antall) {
    layout = new QVBoxLayout;
    this->setModal(true);

    if(antall == 3) {
        slider1 = new QSlider(Qt::Horizontal, this);
        slider2 = new QSlider(Qt::Horizontal, this);
        slider3 = new QSlider(Qt::Horizontal, this);

        label1 = new QLabel(this);
        label2 = new QLabel(this);
        label3 = new QLabel(this);

        label1->setText("R");
        label2->setText("G");
        label3->setText("B");

        layout->addWidget(label1);
        layout->addWidget(slider1);
        layout->addWidget(label2);
        layout->addWidget(slider2);
        layout->addWidget(label3);
        layout->addWidget(slider3);
    }

    else {
        slider1 = new QSlider(Qt::Horizontal, this);

        label1 = new QLabel(this);

        label1->setText("Brightness");

        layout->addWidget(label1);
        layout->addWidget(slider1);
    }

    this->setLayout(layout);
}

slider_dialog::~slider_dialog() {
    delete slider1;
    delete slider2;
    delete slider3;

    delete label1;
    delete label2;
    delete label3;

    delete layout;
}
