#ifndef _PARSER_H_
#define _PARSER_H_
// library/App/Parser/Parser.h
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
*/
#include "../../../euler/Euler.h"
#include "./ParserObject.h"
#include <vector>
#include <array>

using std::string;
using std::vector;

#include "./Termcolor.h"
#define JAVASCRIPT termcolor::red
#define C_CPP termcolor::green
#define README termcolor::white
#define FILE termcolor::yellow
#define DIRECTORY termcolor::bold << termcolor::cyan

class AppObject;

class Parser {
public:
    // Constructor sets valid commands stored in cmd
    Parser(AppObject* app);
    // Binds the
    void bindAppObject(AppObject* app) { application = app; }
    // Converts the raw input into a Parsed Command. See ParserObject.h.
    ParsedCommand parse(string rawInput);
    // Simplifies a command. ie, reduce a command's alt to it's meta value.
    string simplifyCommand(string str);
    friend class App;
private:
    // Tokenize the input.
    vector<DataItem*> tokenize(string &rawInput, ParsedCommand &res);
    // Check functions.
    // void checkFunctions(ParsedCommand &cmd);
    AppObject* application;
    // List of shell implemented commands.
    vector<Command> utilCmds;
    vector<Command> eulerCmds;
    bool isUtil(string &str);
    bool isEulerCmd(string &str);
    // Returns true if cmds contains str.
    bool contains(string &str);
};

#endif
