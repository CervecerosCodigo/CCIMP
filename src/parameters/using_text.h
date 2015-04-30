#ifndef USING_TEXT_H
#define USING_TEXT_H

#include "parameters.h"

class using_text : public parameters
{

    //Forskjellige textvariabler
    TEXT text;
    bool is_encryption;


public:
    using_text();
    virtual ~using_text();

    inline void set_text(std::string t){text = t;}
    inline void set_is_encryption(bool b){is_encryption = b;}
    inline TEXT get_text(){return text;}
    inline bool get_is_encryption(){return is_encryption;}

};

#endif // USING_TEXT_H
