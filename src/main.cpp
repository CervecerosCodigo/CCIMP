#include "gui/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "test/controllertest.h"
#include "model/processing_interface.h"
#include "model/test_klasse.h"
#include "test/test_lab.cpp"
#include "model/instantiate_tools.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    image_processing_unit p(w);
    processing_interface* process = &p;
    instantiate_tools{process};
    w.show();

    //controllertest* cont = new controllertest();    //Starter test-controller for observer-pattern


/*
 * Tester
 * Avkommenter for å kjøre testene under
 */

//    test_klasse* test = new test_klasse();

//    test_lab *t_lab;
//    t_lab->test_data_cont_template();

    return a.exec();
}
