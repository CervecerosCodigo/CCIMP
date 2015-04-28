#ifndef LIB_H
#define LIB_H

#include <iostream>

typedef int X_AXIS;     //x-coordinate
typedef int Y_AXIS;     //y-coordinate
typedef int RED;        //red color
typedef int GREEN;      //green color
typedef int BLUE;       //blue color
typedef int ALPHA;      //alpha chanel
typedef int SLIDERVAL;  //slider value
typedef int NUMTOOLS;   //number of tools loaded
typedef int WIDTH;      //width
typedef int HEIGHT;     //height
typedef double ANGLE;      //angle of rotation
typedef std::string PASSPHRASE;

#define MIN_COL_VAL 0   //lowest allowed value of a color
#define MAX_COL_VAL 255 //highest allowed value of a color


/**
 * This Enum is used as a member parameter in parameter-objects.
 * It identifies the kind of parameters the respective parameter-object has
 */
enum PARAMTYPE{SLIDER, COORDINATE, COLOR};


/**
 * This enum is used as a constant that defines the origin ov the tool.
 * image_tools are passed by pointer up to controller and we need to make sure
 * that a butten called "blur_button" is connected to the right tool in the back end.
 */
enum TOOLIDENT{BLUR, SHARPEN, RESIZE, COL, CROP, BRIGTHEN, CONTRAST, ROTATE, ENCRYPT};

#endif // LIB_H

