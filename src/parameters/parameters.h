#ifndef PARAMETERS_H
#define PARAMETERS_H

#include "lib.h"

class parameters{

    PARAMTYPE type;

public:
    parameters(PARAMTYPE t):type{t}{}
    virtual ~parameters(){}

    inline virtual PARAMTYPE get_paramtype(){return type;}
};


#endif // PARAMETERS_H
