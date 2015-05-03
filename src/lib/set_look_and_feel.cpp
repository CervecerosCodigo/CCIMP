#include "set_look_and_feel.h"

set_look_and_feel::set_look_and_feel()
{

}

set_look_and_feel::~set_look_and_feel()
{

}

void set_look_and_feel::execute_fabulous_style()
{

    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(153, 147, 142));
    darkPalette.setColor(QPalette::WindowText, QColor(255, 250, 246));
    darkPalette.setColor(QPalette::Base, QColor(137, 129, 122));
    darkPalette.setColor(QPalette::AlternateBase, QColor(137, 129, 122));
    darkPalette.setColor(QPalette::ToolTipBase, QColor(255, 250, 246));
    darkPalette.setColor(QPalette::ToolTipText, QColor(137, 129, 122));
    darkPalette.setColor(QPalette::Text, QColor(255, 250, 246));
    darkPalette.setColor(QPalette::Button, QColor(137, 129, 122));
    darkPalette.setColor(QPalette::ButtonText, QColor(255, 250, 246));
    darkPalette.setColor(QPalette::Link, QColor(175, 160, 147));

    darkPalette.setColor(QPalette::Highlight, QColor(189, 169, 152));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    qApp->setPalette(darkPalette);
}

