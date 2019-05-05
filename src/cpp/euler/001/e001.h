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
    void run() override;
    virtual void name() override;
    virtual void description() override;
};

#endif
