#ifndef _E_001_H_
#define _E_001_H_

#include "../Euler.h"

class e001 : public Euler {
public:
    e001(EulerInterface e);
    void run() override;
    virtual void name() override;
    virtual void description() override;
};

#endif
