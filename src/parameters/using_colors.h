#ifndef USING_COLORS_H
#define USING_COLORS_H

#include "parameters.h"

class using_colors : public parameters
{

    //colors
    RED red;
    GREEN green;
    BLUE blue;
    ALPHA alpha;


public:
    using_colors();
    virtual ~using_colors();

    inline void set_red(int r){red = r;}
    inline void set_green(int g){green = g;}
    inline void set_blue(int b){blue = b;}
    inline void set_alpha(int a){alpha = a;}
    inline RED get_red(){return red;}
    inline GREEN get_green(){return green;}
    inline BLUE get_blue(){return blue;}
    inline ALPHA get_alpha(){return alpha;}

    //parameters* get_param() override;
};

#endif // using_colors_H
