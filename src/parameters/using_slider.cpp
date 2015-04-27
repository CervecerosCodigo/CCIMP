#include "using_slider.h"

using_slider::using_slider() : parameters(PARAMTYPE::SLIDER)
{
    slider_val.push_back(0);
    slidercount++;
}

using_slider::using_slider(int n) : slidercount{n}, parameters(PARAMTYPE::SLIDER)
{
    for(int i = 0; i < slidercount; i++)
        slider_val.push_back(0);
}

using_slider::~using_slider()
{

}

