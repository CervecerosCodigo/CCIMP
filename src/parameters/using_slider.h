#ifndef USING_SLIDER_H
#define USING_SLIDER_H

#include "parameters/parameters.h"
#include <vector>
#include <QDebug>

class using_slider : public parameters
{
    std::vector<SLIDERVAL> slider_val;
    int slidercount;

public:
    using_slider();
    using_slider(int);
    virtual ~using_slider();

    inline void set_slider_val(int s){      //When using one slider
        slider_val[0] = s;

    }

    //when using multiple sliders
    inline void set_slider_val(int sliderIdx, int val){slider_val[sliderIdx] = val;}

    inline SLIDERVAL get_slider_val(){return slider_val[0];}


    inline SLIDERVAL get_slider_val(int sliderIdx){return slider_val[sliderIdx];}


};

#endif // USING_SLIDER_H
