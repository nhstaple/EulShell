#include "./e001.h"
#include <iostream>
using namespace std;

e001::e001(EulerInterface e)
{
    this->interface = e;
}

void e001::name()
{
    cout << "* Project Euler #1 - Multiples of 3 and 5\n";
    cout << "* https://projecteuler.net/problem=1\n*\n";
}

void e001::description()
{
    cout << "* If we list all the natural numbers below 10 that are multiples of\n";
    cout << "*  3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.\n";
    cout << "*  Find the sum of all the multiples of 3 or 5 below 1000.\n";
}

void e001::help()
{
    cout << "* Euler 001 - Help\n";
    name();
    description();
    cout << "*\n* Interface read as- \"<index> <default>, <min>, <max>\":\n";
    int i = 0;
    for(InterfaceAtom a : interface.getInterfaceCopy()) {
        cout << "*\t" << i << ": ";
        void* val = nullptr;
        void* min = nullptr;
        void* max = nullptr;

        if((val = a.data.getInt())) {
            cout << *static_cast<int*>(val);
        } else if((val = a.data.getFloat())) {
            cout << *static_cast<float*>(val);
        } else if((val = a.data.getBool())) {
            cout << *static_cast<bool*>(val);
        } else if((val = a.data.getString())) {
            cout << *static_cast<string*>(val);
        }

        if(val) {
            cout << ", ";
            if((min = a.min.getInt())) {
                cout << *static_cast<int*>(min);
            } else if((min = a.min.getFloat())) {
                cout << *static_cast<float*>(min);
            } else if((min = a.min.getBool())) {
                cout << *static_cast<bool*>(min);
            } else if((min = a.min.getString())) {
                cout << *static_cast<string*>(min);
            }
            if((max = a.max.getInt())) {
                cout << ", " << *static_cast<int*>(max);
            } else if((max = a.max.getFloat())) {
                cout << ", " << *static_cast<float*>(max);
            } else if((max = a.max.getBool())) {
                cout << ", " << *static_cast<bool*>(max);
            } else if((max = a.max.getString())) {
                cout << ", " << *static_cast<string*>(max);
            }
        }

        // Free the malloced memory.
        if(val) { freemem(val, a.data.getType()); }
        if(min) { freemem(min, a.min.getType()); }
        if(max) { freemem(max, a.max.getType()); }
        i++;
        cout << endl;
    }
    cout << "*\n";
}

nanoseconds e001::run(Input *i)
{
    vector<InterfaceAtom> data;
    vector<InterfaceAtom> copy = i->getInterfaceCopy();
    for(auto a = copy.begin(); a != copy.end(); a++) {
        data.push_back(*a);
    }
    Input newInput(data);
    return run(newInput);
}

nanoseconds e001::run(Input &input)
{
    auto data = input.getInterfaceCopy();
    if(data.size() > 0) {
         string* cmd = data[0].data.getString();
         if(cmd && (*cmd == "help" || *cmd == "h")) {
             help();
             delete cmd;
             return nanoseconds(0);
         }
         if(cmd) { delete cmd; }
    }
    name();
    /** Local variables. **/
    // The first number to multiply.
    int const1;
    // The second number to multiply.
    int const2;
    // The maximum value of the product to be summed.
    int cap = 0;
    // The total sum to be returned.
    int sum = 0;

    /** Data validation. **/
    if(this->interface == input && ENABLE) {
        // Set vars based off interface. See the header for me details.
        int *ptr = data[0].data.getInt();
        const1 = *ptr;
        delete ptr;

        ptr = data[1].data.getInt();
        const2 = *ptr;
        delete ptr;

        ptr = data[2].data.getInt();
        cap = *ptr;
        delete ptr;

    } else {
        // Else use the default input.
        if(input.getInterfaceCopy().size() > 0) {
            string *cmd = input.getInterfaceCopy()[0].data.getString();
            if(cmd && *cmd == "test") {
                cout << "> Running test...\n";
            } else {
                cout << "> Error: bad input.\n";
                input.print();
            }
        }
        data = this->interface.getInterfaceCopy();
        int *ptr = data[0].data.getInt();
        const1 = *ptr;
        delete ptr;

        ptr = data[1].data.getInt();
        const2 = *ptr;
        delete ptr;

        ptr = data[2].data.getInt();
        cap = *ptr;
        delete ptr;
    }

    /** Program Start **/
    t0 = high_resolution_clock::now();

    // Add constant 1.
    for(int i = 1; i*const1 < cap; i++)
        sum += i*const1;

    // Add constant 2.
    for(int i = 1; i*const2 < cap; i++)
        sum += i*const2;

    // Const1 and const2 overlap. Remove duplicates.
    for(int i = 1; i*const1*const2 < cap; i++)
        sum -= i*const1*const2;

    /** Program end. **/
    t1 = high_resolution_clock::now();

    // Print the solution.
    cout << "= " << sum << "\n";
    return duration_cast<nanoseconds>(t1 - t0);
}

/*
void e001::exec(Input *in) {
    vector<InterfaceAtom> data;
    vector<InterfaceAtom> copy = in->getInterfaceCopy();
    for(auto a = copy.begin(); a != copy.end(); a++) {
        data.push_back(*a);
    }
    Input newInput(data);
    data = newInput.getInterfaceCopy();

    if(data.size() == 2) {
        string *cmd = data[0].data.getString();
        int *numExperiments = data[1].data.getInt();
        // Parse and check for test.
        if(cmd && numExperiments && *cmd == "test" && *numExperiments > 0) {
            nanoseconds total;
            for(int i = 0; i < *numExperiments; i++) {
                nanoseconds thisTest = run(newInput);
                total = nanoseconds(total.count() + thisTest.count());
                cout << "* This run: " << thisTest.count() << " nanoseconds.\n";
            }
            nanoseconds average = duration_cast<nanoseconds>(total / *numExperiments);
            cout << "* Average time: " << duration_cast<nanoseconds>(average).count() << " nanoseconds.\n";
        }
        if(cmd) { freemem(cmd, "std::string"); }
        if(numExperiments) { freemem(numExperiments, "int"); }
    } else {
        run(newInput);
    }
}

void e001::exec(Input &in) {
    // Parse and check for test.
    vector<InterfaceAtom> data = in.getInterfaceCopy();

    if(data.size() == 2) {
        string *cmd = data[0].data.getString();
        int *numExperiments = data[1].data.getInt();
        // Parse and check for test.
        if(cmd && numExperiments && *cmd == "test" && *numExperiments > 0) {
            nanoseconds total;
            for(int i = 0; i < *numExperiments; i++) {
                nanoseconds res = run(in);
                total = nanoseconds(total.count() + res.count());
            }
            //nanoseconds average = duration_cast<nanoseconds>(total / *numExperiments);
            //cout << "* Average time: " << average.count() << "nanoseconds.\n";
        }
        if(cmd) { freemem(cmd, "std::string"); }
        if(numExperiments) { freemem(numExperiments, "int"); }
    } else {
        run(in);
    }
}
*/
