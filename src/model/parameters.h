#ifndef PARAMETERS_H
#define PARAMETERS_H

typedef int X_AXIS;
typedef int Y_AXIS;
typedef int RED;
typedef int GREEN;
typedef int BLUE;
typedef int ALPHA;
typedef int SLIDERVAL;

#define MIN_COL_VAL 0
#define MAX_COL_VAL 255

enum PARAMTYPE{SLIDER, COORDINATE, COLOR};

class parameters{

    PARAMTYPE type;

public:
    parameters(PARAMTYPE t):type{t}{}
    virtual ~parameters(){}

    inline virtual PARAMTYPE get_paramtype(){return type;}
};


#endif // PARAMETERS_H
