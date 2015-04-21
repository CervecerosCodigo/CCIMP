#ifndef CONTROLLERTEST_H
#define CONTROLLERTEST_H

#include "guitest.h"
#include "observertest.h"
#include <QDebug>

class controllertest : public observertest
{

    guitest* gui;
public:
    controllertest();
    ~controllertest();

    void action_performed(QString str) override;    //Arves fra observer-interfacet.

};

#endif // CONTROLLERTEST_H
