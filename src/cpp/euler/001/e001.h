#ifndef _E_001_H_
#define _E_001_H_
/*
 * Euler #1 - Multiples 3 and 5
 *
 * Interface:
 *      [0] int const1  : the first constant
 *      [1] int const2  : the second constant
 *      [2] int max     : the maximum value to look at
*/

#include "../Euler.h"
#define ENABLE false

class e001 : public Euler {
public:
    e001(EulerInterface e);
    // Runs the program and takes an EulerInterface as Input.
    void run(Input &input) override;
    void run() { this->Euler::run(); }
    // Prints the program name.
    virtual void name() override;
    // Prints the program description.
    virtual void description() override;
    // Prints the interface, info, or additional helpful information.
    virtual void help() override;
};

#endif
