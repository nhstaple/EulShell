// library/App/Parser/EulerInterface/InterfaceAtom.h
#ifndef _INTERFACE_ATOM_H_
#define _INTERFACE_ATOM_H_

/*
 * Interface Atom Object
 *
 * The granular elemement of the Interface object.
 * Includes 3 DataItems- data, min, and max.
 * For Euler interfaces this is self explanatory.
 * For the Parser setting these elements for a command's parameter interface
 *  data := the type
 *  min := the value
 *  max := if it's optional
*/

#include "../../../Graphs/DataItem.h"

class InterfaceAtom {
public:
/** Constructors. **/
    InterfaceAtom()                 {}
    InterfaceAtom(DataItem d)
        : data(d)                   {}
    InterfaceAtom(DataItem d, DataItem mi, DataItem ma)
        : data(d), min(mi), max(ma) {}

/** Overloaded operators. **/
    void operator=(const InterfaceAtom& a)
        { this->data = a.data; this->min = a.min; this->max = a.max; }
    void operator=(InterfaceAtom& a)
        { this->data = a.data; this->min = a.min; this->max = a.max; }

/** Public data members. Experiment with being protected? **/
    DataItem data;
    DataItem min;
    DataItem max;
};

#endif // _INTERFACE_ATOM_H_
