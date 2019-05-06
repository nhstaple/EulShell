#ifndef _E_001_H_
#define _E_001_H_

#include "../Euler.h"

/*
 * Euler #1 - Multiples 3 and 5
 *
 * Interface:
 *      [0] int const1  : the first constant
 *      [1] int const2  : the second constant
 *      [2] int max     : the maximum value to look at
*/

class e001 : public Euler {
public:
    e001(EulerInterface e);
    // Runs the program and takes an EulerInterface as Input.
    void run(EulerInterface &i);
    // Prints the program name.
    virtual void name() override;
    // Prints the program description.
    virtual void description() override;
    // Prints the interface, info, or additional helpful information.
    virtual void help() override;
};

#endif
