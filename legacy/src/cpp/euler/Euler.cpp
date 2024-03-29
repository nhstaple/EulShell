// euler/Euler.cpp

#include "./Euler.h"

// Converts the input to new data and runs the program.
nanoseconds Euler::run(Input *in, const bool &display)
{
    vector<InterfaceAtom> data;
    vector<InterfaceAtom> copy = in->getInterfaceCopy();
    for(auto a = copy.begin(); a != copy.end(); a++) {
        data.push_back(*a);
    }
    Input newInput(data);
    return this->run(newInput, display);
}

