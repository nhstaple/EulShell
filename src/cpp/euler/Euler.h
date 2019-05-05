#ifndef _EULER_H_
#define _EULER_H_

#include "../library/App/Parser/EulerInterface/EulerInterface.h"

class Euler {
public:
    Euler() {}
    virtual void run()=0;
    virtual void name()=0;
    virtual void description()=0;
    EulerInterface interface;
};

#endif
