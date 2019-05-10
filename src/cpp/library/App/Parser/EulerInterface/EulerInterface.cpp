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
        int var1;
        float var2;
        bool var3;
        string var4;
        if(d->getInt(var1)) {
            this->interface.push_back(InterfaceAtom(var1));
        } else if (d->getFloat(var2)) {
            this->interface.push_back(InterfaceAtom(var2));
        } else if (d->getBool(var3)) {
            this->interface.push_back(InterfaceAtom(var3));
        } else if (d->getString(var4)) {
            this->interface.push_back(InterfaceAtom(var4));
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
    for(unsigned int i = 0; i < this->interface.size(); i++) {
        if(this->interface[i].data.getType() != w.interface[i].data.getType()) {
            return false;
        }
    }

    // Check if the value provided by w is within this inerface's range.
    // If it is then tru!
    // If not, oooh noooooo.
    unsigned int i = 0;
    for(InterfaceAtom a : this->interface) {
        int int1;
        float float1;
        bool bool1;
        string string1;
        if(a.data.getType() == "int" || a.data.getType() == "int const&") {
            int min, max;
            int x = 0, y = 0, z = 0;
            if(w.getInterfaceCopy()[i].data.getInt(int1)) { x = int1; }
            if(a.min.getInt(min)) { y = min; } else { y = x; }
            if(a.max.getInt(max)) { z = max; } else { z = x; }
            if(x > z || x < y) { return false; }

        } else if(a.data.getType() == "float" || a.data.getType() == "float const&") {
            float min, max;
            float x = 0.f, y = 0.f, z = 0.f;
            if(w.getInterfaceCopy()[i].data.getFloat(float1)) { x = float1; }
            if(a.min.getFloat(min)) { y = min; } else { y = x; }
            if(a.min.getFloat(max)) { z = max;} else { z = x; }
            if(x > z || x < y) { return false; }

        } else if(a.data.getType() == "bool" || a.data.getType() == "bool const&") {
            // Empty
            bool1 = false;
        } else if(a.data.getType() == "std::string" || a.data.getType() == "std::string const&") {
            string min, max;
            unsigned long x = 0, y = 0, z = 0;
            if(w.getInterfaceCopy()[i].data.getString(string1)) { x = string1.length(); }
            if(a.min.getString(min)) { y = min.length(); } else { y = x; }
            if(a.max.getString(max)) { y = max.length(); } else { z = x; }
            if(x > z || x < y) { return false; }
        }

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
        int var1;
        float var2;
        bool var3;
        string var4;
        if(a.data.getInt(var1)) {
            cout << var1 << endl;
        } else if(a.data.getFloat(var2)) {
            cout << var2 << endl;
        } else if(a.data.getBool(var3)) {
            cout << var3 << endl;
        } else if(a.data.getString(var4)) {
            cout << var4 << endl;
        }
        i++;
    }
}

// Prints the interface as a list of parameters.
// If it's optional mark it with '?'s
void EulerInterface::paramPrint()
{
    int i = 0;
    for(InterfaceAtom a : interface) {
        cout << "\n> \t " << "  - ";
        string type = "";
        a.data.getString(type);
        bool optional = false;
        a.max.getBool(optional);
        bool printedValid = false;
        int var1;
        float var2;
        bool var3;
        string var4;
        if(a.min.getInt(var1)) {
            if(!optional) {
                cout << i;
                printedValid = true;
            } else { cout << '?'; }
            cout << " " << type << " -> " << var1;
        } else if(a.min.getFloat(var2)) {
            if(!optional) {
                cout << i;
                printedValid = true;
            } else { cout << '?'; }
            cout << " " << type << " -> " << var2;
        } else if(a.min.getBool(var3)) {
            if(!optional) {
                cout << i;
                printedValid = true;
            } else { cout << '?'; }
            cout << " " << type << " -> " << var3;
        } else if(a.min.getString(var4)) {
            if(!optional) {
                cout << i;
                printedValid = true;
            } else { cout << '?'; }
            cout << " " << type << " -> " << var4;
        }
        if(printedValid)
            i++;
    }
}
