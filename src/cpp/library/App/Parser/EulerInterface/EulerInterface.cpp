#include "./EulerInterface.h"

#include <iostream>
#include <string>
using namespace std;

// The Inteface is set on contruction.
EulerInterface::EulerInterface(std::vector<InterfaceAtom> v)
{
    for(InterfaceAtom e : v) {
        this->interface.push_back(e);
    }
}

// The Interface's data is set on a function call.
void EulerInterface::set(std::vector<DataItem> &v)
{
    this->interface.clear();
    for(auto d : v) {
        this->interface.push_back(d);
    }
}

void EulerInterface::set(std::vector<DataItem*> &v)
{
    this->interface.clear();
    for(auto d : v) {
        void* ptr = nullptr;
        if(ptr = d->getInt()) {
            this->interface.push_back(InterfaceAtom(*static_cast<int*>(ptr)));
            delete ptr;
        } else if (ptr = d->getFloat()) {
            this->interface.push_back(InterfaceAtom(*static_cast<float*>(ptr)));
            delete ptr;
        } else if (ptr = d->getBool()) {
            this->interface.push_back(InterfaceAtom(*static_cast<bool*>(ptr)));
            delete ptr;
        } else if (ptr = d->getString()) {
            this->interface.push_back(InterfaceAtom(*static_cast<string*>(ptr)));
            delete ptr;
        }
    }
}

// The Interface's data is set on a function call.
void EulerInterface::set(std::vector<InterfaceAtom> &v)
{
    this->interface.clear();
    for(InterfaceAtom &a : v) {
        this->interface.push_back(a);
    }
}

// This will check the this Interface's size with the comparison. If they aren't equal, then
// the interfaces aren't equal. False.
// If the types of each InterfaceAtom arent's equal- false.
// If the data of each value is not within the comparison Inteface's range- false.
// True otherwise.
bool EulerInterface::operator==(EulerInterface& w) {
    // Check the length.
    if(w.interface.size() != this->interface.size())
        return false;

    // Check if the types are correct.
    for(int i = 0; i < this->interface.size(); i++) {
        if(this->interface[i].data.getType() != w.interface[i].data.getType()) {
            return false;
        }
    }

    // Check if the value provided by w is within this inerface's range.
    // If it is then tru!
    // If not, oooh noooooo.
    int i = 0;
    for(InterfaceAtom a : this->interface) {
        void *val = nullptr;
        void *min = nullptr;
        void *max = nullptr;
        if(a.data.getType() == "int") {
            val = w.getInterfaceCopy()[i].data.getInt();
            min = a.min.getInt();
            max = a.max.getInt();
            int x = 0, y = 0, z = 0;
            if(val) { x = *static_cast<int*>(val); }
            if(min) { y = *static_cast<int*>(min); } else { y = x; }
            if(max) { z = *static_cast<int*>(max); } else { z = x; }
            if(x > z || x < y) { return false; }
        } else if(a.data.getType() == "float") {
            val = w.getInterfaceCopy()[i].data.getFloat();
            min = a.min.getInt();
            max = a.max.getInt();
            float x = 0.f, y = 0.f, z = 0.f;
            if(val) { x = *static_cast<float*>(val); }
            if(min) { y = *static_cast<float*>(min); } else { y = x; }
            if(max) { z = *static_cast<float*>(max); } else { z = x; }
            if(x > z || x < y) { return false; }
        } else if(a.data.getType() == "bool") {
            // Empty
        } else if(a.data.getType() == "std::string") {
            val = w.getInterfaceCopy()[i].data.getInt();
            min = a.min.getString();
            max = a.max.getString();
            int x = 0, y = 0, z = 0;
            if(val) { x = static_cast<string*>(val)->length(); }
            if(min) { y = static_cast<string*>(min)->length(); } else { y = x; }
            if(max) { y = static_cast<string*>(max)->length(); } else { z = x; }
            if(x > z || x < y) { return false; }
        }
        if(val) { free(val); }
        if(min) { free(min); }
        if(max) { free(max); }
        i++;
    }
    return true;
}

void EulerInterface::operator=(EulerInterface &w)
{
    this->interface.clear();
    for(InterfaceAtom &a : w.interface) {
        this->interface.push_back(a);
    }
}

void EulerInterface::operator=(const EulerInterface &w)
{
    this->interface.clear();
    for(InterfaceAtom a : w.interface) {
        this->interface.push_back(a);
    }
}

void EulerInterface::print()
{
    int i = 0;
    for(InterfaceAtom a : interface) {
        cout << ".  " << i << " " << a.data.getType() << " -> ";
        void *ptr = nullptr;
        if(ptr = a.data.getInt()) {
            cout << *static_cast<int*>(ptr) << endl;
        } else if(ptr = a.data.getFloat()) {
            cout << *static_cast<float*>(ptr) << endl;
        } else if(ptr = a.data.getBool()) {
            cout << *static_cast<bool*>(ptr) << endl;
        } else if(ptr = a.data.getString()) {
            cout << *static_cast<string*>(ptr) << endl;
        }
        if(ptr) { free(ptr); }
        i++;
    }
}
