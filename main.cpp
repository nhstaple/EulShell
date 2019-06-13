/*
 * main.cpp
 * https://github.com/nhstaple/EulShell
 * EulShell - nhstaple@github
 * Nick S.
 *
 * TODO
 * v0.1.0 Get input from the user.
 * v0.2.0 Parse it.
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

#include <iostream>
#include "library/h/EulShell.h"

using namespace std;

int main(int argc, char* argv[])
{
    cout << "In main\n\n";

    // Initialize the shell.
    EulShell euler("EulShell", "eul# ");
    // Run the program.
    euler.execute();

    cout << "\nIn main\n\n";
    return 0;
}
