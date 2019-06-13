/*
 * Shell.cpp
 * Nick S.
*/

#include "../h/Shell.h"
#include <iostream>

using std::string;
using namespace std;

void Shell::welcome()
{
    cout << DEF_BUFF + "Welcome to " + appName + "!\n";
    cout << DEF_BUFF << endl;
}

void Shell::prompt()
{
    cout << token;
}

/** TODO **/
int Shell::exit()
{
    cout << DBG_BUFF << "TODO: Shell::exit()\n";
    if(DEBUG_INPUT) { cout << DEF_BUFF << endl; }
    cout << OUT_BUFF << "Closing " << appName << endl;
    if(DEBUG_INPUT) { cout << DEF_BUFF << endl; }
    // Clear up the data.
    return unitiliaze();
}

/** TODO **/
int Shell::initialize()
{
    cout << DBG_BUFF << "TODO: Shell::initialize()\n";
    return EXIT_SUCCESS;
}

/** TODO **/
int Shell::unitiliaze()
{
    cout << DBG_BUFF << "TODO: Shell::unitiliaze()\n";
    return EXIT_SUCCESS;
}
