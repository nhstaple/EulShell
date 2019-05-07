#include "./App.h"
#include "../../euler/001/e001.h"
#include <string>
#include <vector>

using namespace std;

void App::Setup()
{
    Setup001();
}

/** Problem 1 **/
// euler/001/e001.h
void App::Setup001()
{
    this->dataList.clear();
    this->dataList.push_back(InterfaceAtom(3, 1, 10));
    this->dataList.push_back(InterfaceAtom(5, 1, 10));
    this->dataList.push_back(InterfaceAtom(10, 10, 999));
    e001* euler1 = new e001(EulerInterface(dataList));
    eulerDictionary["e001"] = euler1;
}
