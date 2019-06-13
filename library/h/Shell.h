/*
\* Shell.h
\* Nick S.
 *
\* Shell - The application interface for EulShell.
 *
\* This object abstracts all the logic required to run a shell.
*/

#ifndef _SHELL_H_
#define _SHELL_H_

#include "SystemFiles.h"

using std::string;

const bool DEBUG_INPUT = true;

class Shell
{
public:
    // Constructs the shell.
    Shell(const string &name, const string &tok)
    : appName(name), token(tok) { }

    // Runs the program infinitely until the user notifies an exit.
    virtual int execute() = 0;
    // Exits the shell.
    virtual int exit();

protected:
// Methods
    // Sets up all the internal data for the shell.
    virtual int initialize();
    // Prints the welcome info on the entry.
    virtual void welcome();
    // Prints the prompt, ie token followed by the input.
    virtual void prompt();
    // Unitiliaze.
    virtual int unitiliaze();
// New in v0.0.1
    // Gets raw input from the user, @this.MAX_CMD_LENGTH long.
    string readInput();
// ..

// Variables
    // The name of the shell.
    string appName;
    // The prompt printed before user input. For example, BASH.token = "$"
    string token;
    // Used for buffering the console output.
    // Default buffer.
    const string DEF_BUFF = "* ";
    // Output buffer. Used for descriptions, process messages, etc.
    const string OUT_BUFF = "< ";
    // Used to pad debugging statements.
    const string DBG_BUFF = "@ ";
// New in v0.0.1
    // The maximum amount of characters the user can enter, 128 bytes in size.
    const int MAX_CMD_LENGTH = BYTE * 128;
// ..
};

#endif // _SHELL_H_
