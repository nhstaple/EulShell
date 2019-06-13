/*
\* EulShell.h
\* Nick S.
 *
\* EulShell - The application interface for EulShell.
 *
\* This is
*/

#ifndef _EULSHELL_H_
#define _EULSHELL_H_

#include "Shell.h"

class EulShell : public Shell
{
public:
    // Constructs the shell and initalizes the shell.
    EulShell(const std::string &n, const std::string &t)
    : Shell(n, t) { initialize(); }

    // Runs the program infinitely until the user notifies an exit.
    int execute() override;
    // Exits the shell.
    // int exit() override;

private:
/** Methods **/
    // Sets up all the interal data for the shell.
    int initialize() override;
    // Prints the welcome info on the entry.
    // void welcome() override;
    // Prints the prompt, ie token followed by the input.
    // void prompt() override;
    // Frees all allocated data.
    int unitiliaze() override;

/* Inherited variables
protected:
    string appName;
    string token;
    const string DEF_BUFF;
    const string OUT_BUFF;
    const string DBG_BUFF;
*/
};

#endif // _EULSHELL_H_
