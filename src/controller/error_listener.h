#ifndef ERROR_LISTENER_H
#define ERROR_LISTENER_H

#include "lib.h"

class error_listener{

public:
    error_listener(){}
    ~error_listener(){}

    virtual void on_exception_occured(TOOLIDENT)=0; //skal ta med seg definisjon av hvilket verktøy som ble brukt når error intruffet

};

#endif // ERROR_LISTENER_H

