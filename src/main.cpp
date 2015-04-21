#include "gui/mainwindow.h"
#include <QApplication>
#include <QDebug>

#include "model/processing_interface.h"
#include "model/test_klasse.h"
#include "test/test_lab.cpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    image_processing_unit p(w);

    w.show();


/*
 * Tester
 * Avkommenter for å kjøre testene under
 */

//    test_klasse* test = new test_klasse();

//    test_lab *t_lab;
//    t_lab->test_data_cont_template();

    return a.exec();
}
