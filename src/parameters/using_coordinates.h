#ifndef USING_COORDINATES_H
#define USING_COORDINATES_H

#include "parameters.h"

class using_coordinates : public parameters
{

    //coordinates
    X_AXIS x_axis;
    Y_AXIS y_axis;
    HEIGHT height;
    WIDTH width;

public:
    using_coordinates();
    virtual ~using_coordinates();

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

#endif // USING_COORDINATES_H