#ifndef PARAMETER_USING_COORDIANTES_H
#define PARAMETER_USING_COORDIANTES_H

#include "parameters.h"

class parameter_using_coordiantes : public parameters
{

    //coordinates
    X_AXIS x_axis;
    Y_AXIS y_axis;
    HEIGHT height;
    WIDTH width;

public:
    parameter_using_coordiantes();
    virtual ~parameter_using_coordiantes();

    inline void set_x_axis(int x){x_axis = x;}
    inline void set_y_axis(int y){y_axis = y;}
    inline void set_width(int w){width = w;}
    inline void set_height(int h){height = h;}
    inline X_AXIS get_x_axis(){return x_axis;}
    inline Y_AXIS get_y_axis(){return y_axis;}
    inline WIDTH get_width(){return width;}
    inline HEIGHT get_height(){return height;}

   // parameters* get_param() override;
};

#endif // PARAMETER_USING_COORDIANTES_H
