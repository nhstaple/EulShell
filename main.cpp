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
