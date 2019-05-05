#ifndef EULERINTERFACE_H
#define EULERINTERFACE_H

#include "../../../Graphs/node.h"
#include "../../../Utility/Typedata.h"

#include <vector>

/*
 * Euler Interface Object
 *
 * This takes in a list of data elements to provide data interfaces for
 * Project Euler functions. For example, the Parser extracts n data elements
 * to pass to the Euler problem to be run. Th Parser checks the provided
 * input with the Euler problem's interface. If the interface's match,
 * ie each element has the same type, then the Parser will pass the input
 * data via this object to the problem.
 *
 * Example code
    InterfaceAtom a1(0, -1, 1), a2(3.14f, 0.f, 4.f);
    vector<InterfaceAtom> face;
    face.push_back(a1);
    face.push_back(a2);

    EulerInterface ei1(face), ei2(face);
    vector<DataItem> data;
    for(InterfaceAtom boop : face) {
        data.push_back(boop.data);
    }
    ei1.set(data);

    face.push_back(a1);
    EulerInterface ei3(face);

    cout << (ei1 == ei2) << endl;
    cout << (ei1 == ei3) << endl;
 * Expected Output:
    1
    0
*/

class InterfaceAtom {
public:
    InterfaceAtom(DataItem d) : data(d) {}
    InterfaceAtom();
    InterfaceAtom(DataItem d, DataItem mi, DataItem ma) : data(d), min(mi), max(ma) {}

    void operator=(const InterfaceAtom& a) { this->data = a.data; this->min = a.min; this->max; a.max; }
    DataItem data;
    DataItem min;
    DataItem max;
};

class EulerInterface
{
public:
    EulerInterface(std::vector<InterfaceAtom> v);
    EulerInterface() {}

    void set(std::vector<DataItem> v);

    bool operator==(EulerInterface& w);

private:
    std::vector<InterfaceAtom> interface;
    std::vector<DataItem> value;
};

#endif // EULERINTERFACE_H
