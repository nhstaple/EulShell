// library/App/Parser/Parser.h
#ifndef _PARSER_H_
#define _PARSER_H_

/*
 * Parser Object
 *
 * Reads a line of data from the user. Supports the following inputs:
    <cmd>
    <cmd> <input list>
 * Valid commands, see the constructor.
    help
    exit
    e001
 *
 * The parse can be bound to an AppObject. In the larger context it is bound
 * to the App object to be able to recieve the dictionary of euler problems
 * and access other metadata.
 *
*/

#include "../../../euler/Euler.h"
#include "./ParserObject.h"
#include <vector>
#include <array>

using std::string;
using std::vector;

#include "./Termcolor.h"

class AppObject;

class Parser {
    friend class App;
public:
/** Constructor. **/
    Parser(AppObject* app);

/** Parser functions. **/
    // Binds the parser to the app that is passed.
    void bindAppObject(AppObject* app) { application = app; }
    // Converts the raw input into a Parsed Command. See ParserObject.h.
    ParsedCommand* parse(string rawInput);
    // Simplifies a command. ie, reduce a command's alt to it's meta value.
    string simplifyCommand(string str);
private:
    // Tokenize the input.
    vector<DataItem*> tokenize(string &rawInput, ParsedCommand *res);
    // Returns true if str is a utility command.
    bool isUtil(string &str);
    // Returns true if str is an euler command.
    bool isEulerCmd(string &str);
    // Returns true if str is a util or euler command.
    bool contains(string &str);
    // Parses the command as a test command.
    TestCommand* parseTestCmd(ParsedCommand *cmd);

/** Private data members. **/
    AppObject* application;
    // List of shell implemented commands. Instantiated in Parser::Parser()
    vector<Command> utilCmds;
    vector<Command> eulerCmds;
};

#endif // _PARSER_H_
