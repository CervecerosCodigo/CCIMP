#include "gui/mainwindow.h"
#include <QApplication>

#include "model/test_klasse.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    test_klasse* test = new test_klasse();


    return a.exec();
}
