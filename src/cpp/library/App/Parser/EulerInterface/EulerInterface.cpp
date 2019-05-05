#include "./EulerInterface.h"

#include <string>
using std::string;

// The Inteface is set on contruction.
EulerInterface::EulerInterface(std::vector<InterfaceAtom> v)
{
    for(InterfaceAtom e : v) {
        this->interface.push_back(e);
        // this->value.push_back(e.data);
    }
}

// The Interface's data is set on a function call.
void EulerInterface::set(std::vector<DataItem> v)
{
    this->value.clear();
    for(DataItem e : v) {
        value.push_back(e);
    }
}

// This will check the this Interface's size with the comparison. If they aren't equal, then
// the interfaces aren't equal. False.
// If the types of each InterfaceAtom arent's equal- false.
// If the data of each value is not within the comparison Inteface's range- false.
// True otherwise.
bool EulerInterface::operator==(EulerInterface& w) {
    if(w.interface.size() != this->interface.size())
        return false;

    // Check if the types are correct.
    for(int i = 0; i < this->interface.size(); i++) {
        if(this->interface[i].data.getType() != w.interface[i].data.getType()) {
            return false;
        }
    }

    // Check if this Interface has any input data.
    if(this->value.size() > 0) {
        // Loop over all of the contents.
        for(int i = 0; i < this->value.size(); i++) {
            // Check each type and it's bounds against
            if(this->value[i].getType() == "int") {
                int data = *static_cast<int*>(this->value[i].get());
                if(this->interface[i].min.getType() != "null" && this->interface[i].max.getType() != "null") {
                    int min = *static_cast<int*>(w.interface[i].min.get());
                    int max = *static_cast<int*>(w.interface[i].max.get());
                    if(data > max || data < min)
                        return false;
                }
            } else if(this->value[i].getType() == "float") {
                float data = *static_cast<float*>(this->value[i].get());
                if(this->interface[i].min.getType() != "null" && this->interface[i].max.getType() != "null") {
                    float min = *static_cast<float*>(w.interface[i].min.get());
                    float max = *static_cast<float*>(w.interface[i].max.get());
                    if(data > max || data < min)
                        return false;
                }
            } else if(this->value[i].getType() == "bool") {
                bool data = *static_cast<bool*>(this->value[i].get());
                if(this->interface[i].min.getType() != "null" && this->interface[i].max.getType() != "null") {
                    bool min = *static_cast<bool*>(w.interface[i].min.get());
                    bool max = *static_cast<bool*>(w.interface[i].max.get());
                    if(data > max || data < min)
                        return false;
                }
            } else if(this->value[i].getType() == "std::string") {
                int data = (*static_cast<string*>(this->value[i].get())).length();
                if(this->interface[i].min.getType() != "null" && this->interface[i].max.getType() != "null") {
                    int min = (*static_cast<string*>(w.interface[i].min.get())).length();
                    int max = (*static_cast<string*>(w.interface[i].max.get())).length();
                    if(data > max || data < min)
                        return false;
                }
            }
        }
    }
    return true;
}

void EulerInterface::operator=(EulerInterface &w)
{
    this->interface.clear();
    this->value = w.value;
    for(InterfaceAtom a : w.interface) {
        this->interface.push_back(a);
    }
}

void EulerInterface::operator=(const EulerInterface &w)
{
    this->interface.clear();
    this->value = w.value;
    for(InterfaceAtom a : w.interface) {
        this->interface.push_back(a);
    }
}
