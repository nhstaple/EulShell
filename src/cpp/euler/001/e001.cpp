#include "./e001.h"
#include <iostream>
using namespace std;

/*
 * Sample code:
    InterfaceAtom a1(3), a2(5), a3(10), a4(1000);
    vector<InterfaceAtom> face;
    vector<DataItem> newData;

    face.push_back(a1);
    face.push_back(a2);
    face.push_back(a3);
    newData.push_back(a1.data);
    newData.push_back(a2.data);
    newData.push_back(a4.data);

    EulerInterface ei1(face);
    e001 euler1(ei1);
    euler1.run();
    euler1.interface.set(newData);
    euler1.run();
 * Expected output:
    * ...
    * -> 23

    * ...
    * -> <solution>
*/

e001::e001(EulerInterface e)
{
    this->interface = e;
    this->commands.push_back("help");
}

void e001::name()
{
    cout << "* Project Euler #1 - Multiples of 3 and 5\n";
    cout << "* https://projecteuler.net/problem=1\n*\n";
}

void e001::description()
{
    cout << "*  If we list all the natural numbers below 10 that are \n";
    cout << "*   multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.\n";
    cout << "*   Find the sum of all the multiples of 3 or 5 below 1000.\n";
}

void e001::help()
{
    cout << "* No help available.\n\n";
}

void e001::run()
{
    // Print meta data.
    name();
    description();

    // Declare variables local to this instance here.
    int const1;
    int const2;
    int cap = 0;
    int total = 0;
    // ***

    // The user has provided data.
    if(this->interface.getValues().size() != 0) {
        // Set vars based off interface.
        auto intrfc = this->interface.getValues();
        const1 = *static_cast<int*>(intrfc[0].get());
        const2 = *static_cast<int*>(intrfc[1].get());
        cap = *static_cast<int*>(intrfc[2].get());
    } else {
        // Else use the default input.
        auto intrfc = this->interface.getInterface();
        const1 = *static_cast<int*>(intrfc[0].data.get());
        const2 = *static_cast<int*>(intrfc[1].data.get());
        cap = *static_cast<int*>(intrfc[2].data.get());
    }

    /** Program Start **/

    // Add constant 1.
    for(int i = 1; i*const1 < cap; i++)
        total += i*const1;

    // Add constant 2.
    for(int i = 1; i*const2 < cap; i++)
        total += i*const2;

    // Const1 and const2 overlap. Remove duplicates.
    for(int i = 1; i*const1*const2 < cap; i++)
        total -= i*const1*const2;

    cout << "* -> " << total << "\n\n";
}
