// library/App/App.h
#ifndef _APP_H_
#define _APP_H_

/*
 * App Object
 *
 * The main abstraction of the shell.
 *
*/

#include "../../euler/Euler.h"
#include "./AppObject.h"
#include "./Parser/Parser.h"
#include <map>

using std::map;
using std::string;

/** Constants. **/
#define MAX_CMD_LENGTH 256

class App : AppObject {
    friend class Parser;
public:
/** Constructor. **/
    App();

/** Print functions. **/
    void printAppObject() override;

/** App functions. **/
    // Performs the main application loop.
    void run();
private:
    // Prints the welcome info on the entry.
    void welcome();
    // Prints the prompt, for example "BASH$ "
    void prompt();
    // Prints the help information of all available commands.
    void help();
    // Performs the functions based off the input command.
    void checkFunctions(ParsedCommand &cmd);

/** Private data members. **/
/** Parsing Stuff **/
    Parser* parser;

/** Euler Stuff **/
    // Hastable that holds <problem name, euler object> key-value pair.
    map<string, Euler*> eulerDictionary;

/** Setup function. **/
    // Main setup function.
    void Setup();
    // Sets up problem 001.
    void Setup001();

    // Used for initilizing interfaces.
    vector<InterfaceAtom> dataList;
};

#endif // _APP_H_
