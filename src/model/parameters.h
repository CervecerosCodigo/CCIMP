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


class parameters{

    class color_param{

        //colors
        RED red;
        GREEN green;
        BLUE blue;
        ALPHA alpha;

        inline void set_red(int r){red = r;}
        inline void set_green(int g){green = g;}
        inline void set_blue(int b){blue = b;}
        inline void set_alpha(int a){alpha = a;}
        inline RED get_red(){return red;}
        inline GREEN get_green(){return green;}
        inline BLUE get_blue(){return blue;}
        inline ALPHA get_alpha(){return alpha;}
    };


    class axis_param{
        //coordinates
        X_AXIS x_axis;
        Y_AXIS y_axis;

        inline void set_x_axis(int x){x_axis = x;}
        inline void set_y_axis(int y){y_axis = y;}
        inline X_AXIS get_x_axis(){return x_axis;}
        inline Y_AXIS get_y_axis(){return y_axis;}
    };


    class slide_param{

        SLIDERVAL slider_val;

        inline void set_slider(int s){slider_val = s;}
        inline SLIDERVAL get_slider_val(){return slider_val;}
    };

    color_param* cp;
    axis_param* ap;
    slide_param* sp;

public:

    inline color_param* get_color_param(){return cp;}
    inline void use_color_param(){cp = new color_param();}


};

#endif // PARAMETERS_H
