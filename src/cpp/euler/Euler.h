#ifndef _EULER_H_
#define _EULER_H_

#include "../library/App/Parser/EulerInterface/EulerInterface.h"

/*
 * Euler Abstract Class
 *
 * The base class for all Euler Problems. Ie, this will allow the shell to treat
 * all Euler Problems as a command with the interface being it's input method.
 *
*/

class Euler {
public:
    Euler() {}
    // Performs the calcuation.
    virtual void run()=0;
    // Prints the name of the problem.
    virtual void name()=0;
    // Prints the description of the problem.
    virtual void description()=0;
    // Public interface to access. To be used in the Parser, ie (input interface) == this->interface ?
    EulerInterface interface;
};

#endif
