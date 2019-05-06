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

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Euler {
public:
    Euler() { }
    // Performs the calcuation.
    void run(EulerInterface &i) {}
    // Prints the name of the problem.
    virtual void name()=0;
    // Prints the description of the problem.
    virtual void description()=0;
    // Prints the help for the problem.
    virtual void help()=0;

    Euler* operator*() { return this; }

    // Public interface to access. To be used in the Parser, ie (input interface) == this->interface ?
    EulerInterface interface;
    // Commands used for the Parser.
    vector<string> commands;
};

#endif
