// EulShell.cpp
// Nick S.

#include "../h/EulShell.h"
#include <iostream>

using std::string;
using namespace std;

int EulShell::execute()
{
    if(DEBUG_INPUT) { cout << DEF_BUFF << endl; }

    // Welcome's the user to the shell.
    welcome();

    // The main loop.
    do
    {
        // Prompt the user for input.
        prompt();
        if(DEBUG_INPUT) { cout << endl << DEF_BUFF << endl; }

    /* 1. Get input from the user.
     * 2. Parse it.
     * 3. Execute the command.
    */

    } while(false); // While input != Command.exit

    return exit();
}

/** TODO **/
int EulShell::initialize()
{
    Shell::initialize();
    cout << DBG_BUFF << "TODO: EulShell::initialize()\n";
    return EXIT_SUCCESS;
}

/** TODO **/
int EulShell::unitiliaze()
{
    Shell::unitiliaze();
    cout << DBG_BUFF << "TODO: EulShell::unitiliaze()\n";
    return EXIT_SUCCESS;
}
