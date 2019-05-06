#ifndef _EULER_H_
#define _EULER_H_
// euler/Euler.h
/*
 * Euler Abstract Class
 *
 * The base class for all Euler Problems. Ie, this will allow the shell to treat
 * all Euler Problems as a command with the interface being it's input method.
 *
*/
#include "../library/App/Parser/EulerInterface/EulerInterface.h"

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

// Make a synon between Euler Interface object and the keyword "Input."
// This will help in readability of code.
typedef class EulerInterface Input;

class Euler {
public:
    Euler() { }
    // Performs the calcuation.
    virtual void run(Input &i)=0;
    void run() { run(interface); }
    // Prints the name of the problem.
    virtual void name()=0;
    // Prints the description of the problem.
    virtual void description()=0;
    // Prints the help for the problem.
    virtual void help()=0;
    Euler* operator*() { return this; }

    // Public interface to access. To be used in the Parser, ie (input interface) == this->interface ?
    Input interface;
};

/*
 * class e001 inherits from class Euler.
 * See euler/001/e001.h for more information about the problem and its interface.
 * Sample code:
    vector<InterfaceAtom> dataList;

    // Set the interface for the eueler object and run with default values.
    dataList.push_back(InterfaceAtom(3, 0, 10));
    dataList.push_back(InterfaceAtom(5, 0, 10));
    dataList.push_back(InterfaceAtom(10, 10, 100));

    EulerInterface input(dataList);
    e001 euler1(input);
    euler1.run();

    // Clear and run with new data.
    dataList.clear();
    dataList.push_back(InterfaceAtom(10));
    dataList.push_back(InterfaceAtom(6));
    dataList.push_back(InterfaceAtom(100));
    input.set(dataList);
    euler1.run(input);
 * Expected output:
    * ...
    * -> 23
    * ...
    * -> 1206
*/

#endif
