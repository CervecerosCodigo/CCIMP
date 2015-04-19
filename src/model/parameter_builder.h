#ifndef PARAMETER_BUILDER_H
#define PARAMETER_BUILDER_H


class parameter_builder
{
    //coordinates
    int x_coord;
    int y_coord;

    //colors
    int r_col;
    int g_col;
    int b_col;
    int a_col;




public:
    parameter_builder();
    ~parameter_builder();

    parameter_builder set_x_coord(int x);
    parameter_builder set_y_coord(int y);

    parameter_builder set_r_color(int r);
    parameter_builder set_g_color(int g);
    parameter_builder set_b_color(int b);
    parameter_builder set_a_color(int a);

};

#endif // PARAMETER_BUILDER_H
