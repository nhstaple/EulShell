// euler/e001/e001.h
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
#define ENABLE true

class e001 : public Euler {
public:
/** Constructors. **/
    e001(EulerInterface e);

/** Exec functions. **/
    // void exec() override;
    // void exec(Input &i) override;
    // void exec(Input *in) override;

/** Run functions. Performs the calculation. **/
    nanoseconds run(Input &input) override;
    nanoseconds run(Input* in) override;
    nanoseconds run() { return run(interface); }


/** Print functions. **/
    // Prints the program name.
    virtual void name() override;
    // Prints the program description.
    virtual void description() override;
    // Prints the interface, info, or additional helpful information.
    virtual void help() override;
};

#endif
