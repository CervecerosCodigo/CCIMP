#ifndef GUITEST_H
#define GUITEST_H

#include "observertest.h"

class guitest
{
    observertest* listener; //lytter-peker som blir satt fra controller via set-metoden

public:
    guitest();
    ~guitest();
    void set_listener(observertest* l); //set-metode for lytter, settes fra controller

    //"dummy-metode som er det som kaller lytter->action_performed()-metode som i sin tur skrives ut i controller.
    void display_message();

    void gui_metode_emulerer_knappetrykk();
};

#endif // GUITEST_H
