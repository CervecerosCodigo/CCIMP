#include "gui/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <Magick++.h>
#include "controller/controller_iface.h"
#include "test/test_lab.cpp"
#include "img_tools/build_tools.h"
#include "controller/controller.h"
#include <QString>
#include <QStyle>
#include <QStyleFactory>
#include <QPalette>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow;

    controller p(*w); //controller
    controller_iface* control = &p;
    build_tools* build = new build_tools{control};
    w->show();

    QApplication::setStyle(QStyleFactory::create("plastique"));
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(153, 147, 142));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(137, 129, 122));
    darkPalette.setColor(QPalette::AlternateBase, QColor(137, 129, 122));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(137, 129, 122));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(175, 160, 147));

    darkPalette.setColor(QPalette::Highlight, QColor(189, 169, 152));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    qApp->setPalette(darkPalette);

    //qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");



    return a.exec();


    delete control;
    delete w;
    delete build;

}
