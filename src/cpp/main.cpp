#include <iostream>

#include "./library/App/Parser/EulerInterface/EulerInterface.h"

using namespace std;

int main()
{
    DataItem i1(1), i2(2);
    i1 = i2;
    Node n(i1), m(i2);
    n.display();
    *static_cast<int*>(m.getData().get()) = 100;
    n.display();
    m.display();
    return 0;
}
