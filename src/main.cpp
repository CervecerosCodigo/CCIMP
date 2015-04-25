#include "gui/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <Magick++.h>
#include "model/controller_iface.h"
#include "test/test_lab.cpp"
#include "model/build_tools.h"
#include "model/controller.h"


int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    MainWindow w;
    controller p(w); //controller
    controller_iface* control = &p;
    build_tools{control};
    w.show();

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
