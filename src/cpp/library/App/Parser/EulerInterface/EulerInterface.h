#pragma once
// library/App/Parser/EulerInterface/EulerInterface.h
#ifndef _EULERINTERFACE_H
#define _EULERINTERFACE_H

#include "../../../Graphs/Node.h"
#include "../../../Utility/Typedata.h"
#include "./InterfaceAtom.h"

#include <vector>
#include <iostream>

/*
 * Euler Interface Object
 *
 * An interface in this context is used to link between the parser
 * and the project euler problem parameters. This allows the user
 * to run a project euler solution with different parameters than
 * the base case provided by the website.
 *
 * Example:
 *  [0] int  theLowerBound  : The lower bound for a function.
 *  [1] int  theUpperBound  : The upper boound for a function.
 *  [2] bool flagDisplay    : If true then the program will display data during exection.
 *
 * Each row above is an Interface Atom.
 *
 * An euler problem's constructor will initial it's atoms with mins and maxs, and a default value.
 * The parse will pass the problem an interface with atoms that has no mins and maxs, but has a value.
 *
 * If this value is within the min and max of the euler problem's interface then the solution is executed with those parameters.
 * Otherwise the default values of the euler problem's interface are used.
*/
using std::string;
using std::vector;
using std::cout;

class EulerInterface
{
public:
    EulerInterface(){}
    EulerInterface(vector<InterfaceAtom> v);
    // Sets the interface.
    void set(vector<DataItem> &v);
    // Returns a copy of the interface's list.
    std::vector<InterfaceAtom> getInterfaceCopy() { return interface; }
    // Overloaded operators.
    bool operator==(EulerInterface& w);
    void operator=(EulerInterface& w);
    void operator=(const EulerInterface& w);
    EulerInterface* operator*() { return this; }
    // Clears the interface. Should not ?
    void reset() { interface.clear(); cout << "** WARNNING CLEARED AN EULER INTERFACE\n";}
    // Prints each atom of the interface and its value.
    void print();
private:
    vector<InterfaceAtom>  interface;
};

// typedef EulerInterface Input;

#endif // EULERINTERFACE_H
