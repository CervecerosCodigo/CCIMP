#ifndef USING_SLIDER_H
#define USING_SLIDER_H

#include "parameters/parameters.h"
#include <QDebug>
class using_slider : public parameters
{

    SLIDERVAL slider_val;

public:
    using_slider();
    virtual ~using_slider();

    inline void set_slider_val(int s){slider_val = s;}
    inline SLIDERVAL get_slider_val(){return slider_val;}


};

#endif // USING_SLIDER_H
