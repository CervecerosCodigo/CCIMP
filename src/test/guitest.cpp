#include "guitest.h"

guitest::guitest()
{

}

guitest::~guitest()
{

}

void guitest::set_listener(observertest *l){
    listener = l;

}

void guitest::display_message(){
    QString s = "Skriver nå ut via observer";
    listener->action_performed(s);     //går via lytter ogned på controller
}


void guitest::gui_metode_emulerer_knappetrykk(){
    display_message();
}
