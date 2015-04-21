#include "controllertest.h"

controllertest::controllertest()
{
    gui = new guitest();        //Oppretter gui
    gui->set_listener(this);    //Registrer controller iform av interface-peker som lytter.

    gui->gui_metode_emulerer_knappetrykk(); //emulerer at man trykker på en knapp, og som da "fyrer" lytteren.
}

controllertest::~controllertest()
{

}

//Metoden kjøres i det den blir kalt fra gui..
void controllertest::action_performed(QString str){
   qDebug() << str;
}
