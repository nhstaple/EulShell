/*
\* EulShell.cpp
\* Nick S.
*/

#include "../h/EulShell.h"
#include <iostream>

using std::string;
using namespace std;

int EulShell::execute()
{
    if(DEBUG_INPUT) { cout << DEF_BUFF << endl; }

    // Welcome's the user to the shell.
    welcome();

    do{ // The main loop.
        // Prompt the user for input.
        prompt();
        // Get the user's input.
        string input = readInput();

        if(DEBUG_INPUT) {
            cout << DBG_BUFF << "Read:\n" << OUT_BUFF << input << endl\
                 << DEF_BUFF << endl;
        }

    /* TODO
     * v0.2.0 Parse the user's input.
     *.... v0.2.1 Tokeneize.
     *.... v0.2.2 First Set.
     *.... v0.2.3 Follow Set.
     *.... v0.2.4 Parse Table.
     *.... v0.2.5 Parse Algorithm.
     * v0.3.0 Execute the command.
     *.... v0.3.1 ls
     *.... v0.3.2 pwd
     *.... v0.3.3 read
     *.... v0.3.4 cd
    */

    } while(false); // While input != Command.exit

    return exit();
}

// TODO
int EulShell::initialize()
{
    Shell::initialize();
    cout << DBG_BUFF << "TODO: EulShell::initialize()\n";
    return EXIT_SUCCESS;
}

// TODO
int EulShell::unitiliaze()
{
    Shell::unitiliaze();
    cout << DBG_BUFF << "TODO: EulShell::unitiliaze()\n";
    return EXIT_SUCCESS;
}
