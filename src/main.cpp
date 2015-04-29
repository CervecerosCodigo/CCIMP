#include "gui/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <Magick++.h>
#include "controller/controller_iface.h"
#include "test/test_lab.cpp"
#include "img_tools/build_tools.h"
#include "controller/controller.h"
#include <QString>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow;

    controller p(*w); //controller
    controller_iface* control = &p;
    build_tools* build = new build_tools{control};
    w->show();

    return a.exec();


    delete control;
    delete w;
    delete build;

}
