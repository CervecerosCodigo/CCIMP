#include "gui/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <Magick++.h>
#include "test/controllertest.h"
#include "model/processing_interface.h"
#include "model/test_klasse.h"
#include "test/test_lab.cpp"
#include "model/instantiate_tools.h"



int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    //InitializeMagick(*argv);

    MainWindow w;
    image_processing_unit p(w); //controller
    processing_interface* process = &p;
    instantiate_tools{process};
    w.show();

    //controllertest* cont = new controllertest();    //Starter test-controller for observer-pattern


/***********************************************
 * Tester
 * Avkommenter for å kjøre testene under
 * *********************************************
 */

//    test_klasse* test = new test_klasse();

//    test_lab *t_lab;
//    t_lab->test_data_cont_template();

    /*
     * Avkommenter for å kjøre test. Denne leser inn bilde girl.gif som skal finnes i build mappen der programmet kompileres.
     * Dersom ImageMagick fungerer kommer det bilde til å bli beskjært å lagret i samme mappe med x.gif som filformat.
     */
//    crop_test *c_test = new crop_test();


    return a.exec();
}
