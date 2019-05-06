#ifndef _INTERFACE_ATOM_H_
#define _INTERFACE_ATOM_H_

/*
 * library/App/Parser/EulerInterface/InterfaceAtom.h
 * Interface Atom Object
 *
 * The granular elemement of the Interface object.
 * Includes 3 DataItems- data, min, and max.
*/

#include "../../../Graphs/DataItem.h"

class InterfaceAtom {
public:
    InterfaceAtom()                 {}
    InterfaceAtom(DataItem d)
        : data(d)                   {}
    InterfaceAtom(DataItem d, DataItem mi, DataItem ma)
        : data(d), min(mi), max(ma) {}

    // Overloaded operators.
    void operator=(const InterfaceAtom& a)  { this->data = a.data; this->min = a.min; this->max = a.max; }
    void operator=(InterfaceAtom& a)        { this->data = a.data; this->min = a.min; this->max = a.max; }

    // friend class EulerInterface;
    // friend void  Euler::run(Input &i);
// protected:
    DataItem data;
    DataItem min;
    DataItem max;
};
#endif
