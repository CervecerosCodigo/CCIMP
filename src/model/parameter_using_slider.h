#ifndef PARAMETER_USING_SLIDER_H
#define PARAMETER_USING_SLIDER_H

#include "parameters.h"

class parameter_using_slider : public parameters
{

    SLIDERVAL slider_val;

public:
    parameter_using_slider();
    virtual ~parameter_using_slider();

    inline void set_slider(int s){slider_val = s;}
    inline SLIDERVAL get_slider_val(){return slider_val;}


};

#endif // PARAMETER_USING_SLIDER_H
