#include "./App.h"
#include "../../euler/001/e001.h"
#include <string>
#include <vector>

using namespace std;

// Used for initilizing interfaces.
vector<InterfaceAtom> face;

void App::Setup()
{
    Setup001();
}

/** Problem 1 **/
// euler/001/e001.h
void App::Setup001()
{
    face.clear();
    face.push_back(InterfaceAtom(3));
    face.push_back(InterfaceAtom(5));
    face.push_back(InterfaceAtom(10));
    e001* euler1 = new e001(EulerInterface(face));
    eulerDictionary["001"] = euler1;
}
