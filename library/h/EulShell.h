/*
\* EulShell.h
\* Nick S.
 *
\* EulShell - The application interface for EulShell.
 *
\* This is shell is an implementation of the abstract Shell Class.
*/

#ifndef _EULSHELL_H_
#define _EULSHELL_H_

#include "Shell.h"

class EulShell : public Shell
{
public:
    // Constructs the shell and initializes the shell.
    EulShell(const std::string &name, const std::string &tok)
    : Shell(name, tok) { initialize(); }

    // Runs the program infinitely until the user notifies an exit.
    int execute() override;

private:
// Methods
    // Sets up all the internal data for the shell.
    int initialize() override;
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
