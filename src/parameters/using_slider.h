#ifndef USING_SLIDER_H
#define USING_SLIDER_H

#include "parameters/parameters.h"
#include <vector>
#include <QDebug>

class using_slider : public parameters
{

//    SLIDERVAL slider_val;
    std::vector<SLIDERVAL> slider_val;
    int slidercount;

public:
    using_slider();
    using_slider(int);
    virtual ~using_slider();

    inline void set_slider_val(int s){
        slider_val[0] = s;
        qDebug() << Q_FUNC_INFO << s;
    }

    inline SLIDERVAL get_slider_val(){return slider_val[0];}

    inline void set_slider_val(int sliderIdx, int s){
        slider_val[sliderIdx] = s;
        qDebug() << Q_FUNC_INFO << s;
    }

    inline SLIDERVAL get_slider_val(int sliderIdx){return slider_val[sliderIdx];}


};

#endif // USING_SLIDER_H
