// euler/Euler.h
#ifndef _EULER_H_
#define _EULER_H_

/*
 * Euler Abstract Class
 *
 * The base class for all Euler Problems. Ie, this will allow the shell to treat
 * all Euler Problems as a command with the interface being it's input.
 *
*/
#include "../library/App/Parser/EulerInterface/EulerInterface.h"

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using std::string;
using std::vector;
using namespace std::chrono;

// Make a synon between Euler Interface object and the keyword "Input."
// This will help in readability of code.
typedef class EulerInterface Input;

class Euler {
public:
/** Constructor. **/
    Euler() { }

/** Run functions. Performs the calculation. **/
    virtual nanoseconds run(Input &i)=0;
    nanoseconds run(Input* in);
    nanoseconds run() { return run(interface); }

/** Meta print functions. **/
    // Prints the name of the problem.
    virtual void name()=0;
    // Prints the description of the problem.
    virtual void description()=0;
    // Prints the help for the problem.
    virtual void help()=0;

/** Overladed operators. **/
    Euler* operator*() { return this; }

/** Public data members. **/
    // Public interface to access. To be used in the Parser, ie (input interface) == this->interface ?
    Input interface;

    // Used to time solutions.
    high_resolution_clock::time_point t0, t1;
};

#endif // _EULER_H_
