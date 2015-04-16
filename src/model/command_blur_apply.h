#ifndef COMMAND_BLUR_APPLY_H
#define COMMAND_BLUR_APPLY_H

#include "command.h"
#include "tool_blur.h"

template<typename T>
class command_blur_apply : public command<T>
{
public:
    command_blur_apply(T t);
    ~command_blur_apply();
    void execute();

};

template<typename T>
command_blur_apply<T>::command_blur_apply(T t): command(t)
{

}

template<typename T>
command_blur_apply<T>::~command_blur_apply()
{

}


template<typename T>
void command_blur_apply<T>::execute(){

}

#endif // COMMAND_BLUR_APPLY_H
