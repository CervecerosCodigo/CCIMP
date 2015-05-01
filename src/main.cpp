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

    //Skriver ut hvilke qt themes som er tilgjengelige på brukerens system.
    //Vi kan beholde denne foreløpig slik at vi finner ut hvilken theme som man har til felles
    qDebug() << QStyleFactory::keys();


    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(153, 147, 142));
    darkPalette.setColor(QPalette::WindowText, QColor(255, 250, 246));
    darkPalette.setColor(QPalette::Base, QColor(137, 129, 122));
    darkPalette.setColor(QPalette::AlternateBase, QColor(137, 129, 122));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::black);
    darkPalette.setColor(QPalette::ToolTipText, Qt::black);
    darkPalette.setColor(QPalette::Text, QColor(255, 250, 246));
    darkPalette.setColor(QPalette::Button, QColor(137, 129, 122));
    darkPalette.setColor(QPalette::ButtonText, QColor(255, 250, 246));
//    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(175, 160, 147));

    darkPalette.setColor(QPalette::Highlight, QColor(189, 169, 152));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    qApp->setPalette(darkPalette);

    //qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
    //Fargetema: http://paletton.com/#uid=7000u0k2ljc6hnI3vhb50fr6wdx


    return a.exec();


    delete control;
    delete w;
    delete build;
    a.quit();
}
