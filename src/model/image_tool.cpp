#include "model/image_tool.h"


void image_tool::set_image(QImage* img){
    orig_image = img;
}


const QImage* image_tool::return_result(){
    return result_image;
}
