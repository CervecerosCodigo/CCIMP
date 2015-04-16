#ifndef COMMAND_BLUR_UNDO
#define COMMAND_BLUR_UNDO


#include "command.h"
#include "tool_blur.h"

template<typename T>
class command_blur_undo : public command<T>
{
public:
    command_blur_undo(T t);
    ~command_blur_undo();
    void execute();

};


template<typename T>
command_blur_undo<T>::command_blur_undo(T t): command(t)
{

}

template<typename T>
command_blur_undo<T>::~command_blur_undo()
{

}


template<typename T>
void command_blur_undo<T>::execute(){

}
#endif // COMMAND_BLUR_UNDO

