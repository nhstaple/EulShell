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
    cout << "* Interface:\n";
    int i = 0;
    for(InterfaceAtom a : interface.getInterfaceCopy()) {
        cout << "*\t" << i << ": ";
        void* val = nullptr;
        void* min = nullptr;
        void* max = nullptr;

        if(val = a.data.getInt()) {
            cout << *static_cast<int*>(val);
        } else if(val = a.data.getFloat()) {
            cout << *static_cast<float*>(val);
        } else if(val = a.data.getBool()) {
            cout << *static_cast<bool*>(val);
        } else if(val = a.data.getString()) {
            cout << *static_cast<string*>(val);
        }

        if(val) { cout << ", "; }
        if(min = a.min.getInt()) {
            cout << *static_cast<int*>(min);
        } else if(min = a.min.getFloat()) {
            cout << *static_cast<float*>(min);
        } else if(min = a.min.getBool()) {
            cout << *static_cast<bool*>(min);
        } else if(min = a.min.getString()) {
            cout << *static_cast<string*>(min);
        }

        if(min) { cout << ", "; }
        if(max = a.max.getInt()) {
            cout << ", " << *static_cast<int*>(max);
        } else if(max = a.max.getFloat()) {
            cout << ", " << *static_cast<float*>(max);
        } else if(max = a.max.getBool()) {
            cout << ", " << *static_cast<bool*>(max);
        } else if(max = a.max.getString()) {
            cout << ", " << *static_cast<string*>(max);
        }

        // Free the malloced memory.
        if(val) { free(val); }
        if(min) { free(min); }
        if(max) { free(max); }
    }
    cout << "\n*\n";
}

void e001::run(EulerInterface &input)
{
    // Print meta data.
    name();
    description();

    // Declare variables local to this instance here.
    // The first number to multiply.
    int const1;
    // The second number to multiply.
    int const2;
    // The maximum value of the product to be summed.
    int cap = 0;
    // The total sum to be returned.
    int sum = 0;
// ***

    // The user has provided valid data.
    if(this->interface == input) {
        // Set vars based off interface. See the header for me details.
        auto intrfc = input.getInterfaceCopy();
        int *ptr = intrfc[0].data.getInt();
        const1 = *ptr;
        free(ptr);

        ptr = intrfc[1].data.getInt();
        const2 = *ptr;
        free(ptr);

        ptr = intrfc[2].data.getInt();
        cap = *ptr;
        free(ptr);

    } else {
        // Else use the default input.
        if(input.getInterfaceCopy().size() > 0)
            cout << "> Error: bad input, using default values.\n";
        auto intrfc = this->interface.getInterfaceCopy();
        int *ptr = intrfc[0].data.getInt();
        const1 = *ptr;
        free(ptr);

        ptr = intrfc[1].data.getInt();
        const2 = *ptr;
        free(ptr);

        ptr = intrfc[2].data.getInt();
        cap = *ptr;
        free(ptr);
    }

    /** Program Start **/
    // Add constant 1.
    for(int i = 1; i*const1 < cap; i++)
        sum += i*const1;

    // Add constant 2.
    for(int i = 1; i*const2 < cap; i++)
        sum += i*const2;

    // Const1 and const2 overlap. Remove duplicates.
    for(int i = 1; i*const1*const2 < cap; i++)
        sum -= i*const1*const2;

    // Print the solution.
    cout << "* -> " << sum << "\n\n";
}
