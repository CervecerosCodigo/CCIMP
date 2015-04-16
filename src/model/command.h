#ifndef COMMAND_H
#define COMMAND_H

#include "image_tool.h"

template<typename T>
class command
{

    image_tool tool;

public:
    command(T t);
    ~command();

    void execute() = 0;
    void set_image(QImage img);
};


////////////////implementasjon av command////////////////////

template<typename T>
command<T>::command(T t): tool{t}{}

template<typename T>
command<T>::~command(){}

#endif // COMMAND_H
