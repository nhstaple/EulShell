// euler/e001/e001.cpp

#include "./e001.h"
#include <iostream>
using namespace std;

// Sets the internal interface.
// It should have data, min, and max for Atom.
e001::e001(EulerInterface e)
{
    this->interface = e;
}

// Prints the name.
void e001::name()
{
    cout << "* Project Euler #1 - Multiples of 3 and 5\n";
    cout << "* https://projecteuler.net/problem=1\n*\n";
}

// Prints the description.
void e001::description()
{
    cout << "* If we list all the natural numbers below 10 that are multiples of\n";
    cout << "*  3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.\n";
    cout << "*  Find the sum of all the multiples of 3 or 5 below 1000.\n";
}

// Prints the help info.
void e001::help()
{
    cout << "* Euler 001 - Help\n";
    name();
    description();
    cout << "*\n* Interface read as- \"<index> <default>, <min>, <max>\":\n";
    int i = 0;
    for(InterfaceAtom a : interface.getInterfaceCopy()) {
        cout << "*\t" << i << ": ";
        int value, min, max;

        if(a.data.getInt(value)) {
            cout << value;
        }

        if(a.min.getInt(min)) {
            cout << ", " << min;
        }
        if(a.max.getInt(max)) {
            cout << ", " << max;
        }
        i++;
        cout << endl;
    }
    cout << "*\n";
}

// Performs the actual calculation.
nanoseconds compute(const int &const1, const int &const2, const int &cap, bool display = false) {
    high_resolution_clock::time_point t0, t1;
    int sum = 0;

    t0 = high_resolution_clock::now();
    for(int i = 1; i*const1 < cap; i++)
        sum += i*const1;

    // Add constant 2.
    for(int i = 1; i*const2 < cap; i++)
        sum += i*const2;

    // Const1 and const2 overlap. Remove duplicates.
    for(int i = 1; i*const1*const2 < cap; i++)
        sum -= i*const1*const2;

    t1 = high_resolution_clock::now();

    // Print the solution.
    if(display) {
        cout << "= " << sum << endl;
        cout << "t " << duration_cast<nanoseconds>(t1 - t0).count() << endl;
   }
   return duration_cast<nanoseconds>(t1 - t0);
}

// The main program.
nanoseconds e001::run(Input &input, const bool &display)
{
    auto data = input.getInterfaceCopy();
    if(data.size() > 0) {
         string cmd;
         if(data[0].data.getString(cmd) && (cmd == "help" || cmd == "h")) {
             help();
             return nanoseconds(0);
         }
    }
    if(display)
        name();

/** Local variables. **/
    // The first number to multiply.
    int const1;
    // The second number to multiply.
    int const2;
    // The maximum value of the product to be summed.
    int cap = 0;

/** Data validation. **/
    if(this->interface == input && ENABLE) {
        // Set vars based off interface. See the header for me details.
        data[0].data.getInt(const1);
        data[1].data.getInt(const2);
        data[2].data.getInt(cap);
    } else {
        // Else use the default input.
        if(input.getInterfaceCopy().size() > 0) {
            cout << "> Error: bad input.\n";
            input.print();
        }
        data = this->interface.getInterfaceCopy();
        data[0].data.getInt(const1);
        data[1].data.getInt(const2);
        data[2].data.getInt(cap);
    }

    return compute(const1, const2, cap, display);
}
