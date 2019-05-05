#include <iostream>

#include "./library/App/Parser/EulerInterface/EulerInterface.h"

using namespace std;

int main()
{
    InterfaceAtom a1(0, -1, 1), a2(3.14f, 0.f, 4.f);
    vector<InterfaceAtom> face;
    face.push_back(a1);
    face.push_back(a2);

    EulerInterface ei1(face), ei2(face);
    vector<DataItem> data;
    for(InterfaceAtom boop : face) {
        data.push_back(boop.data);
    }
    ei1.set(data);

    face.push_back(a1);
    EulerInterface ei3(face);

    cout << (ei1 == ei2) << endl;
    cout << (ei1 == ei3) << endl;
    return 0;
}
