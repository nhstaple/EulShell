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
*/
#include "../../../euler/Euler.h"
#include "./ParserObject.h"
#include <vector>
#include <array>

using std::string;
using std::vector;

class AppObject;

class Parser {
public:
    // Constructor sets valid commands stored in cmd
    Parser(AppObject* app);
    // Binds the
    void bindAppObject(AppObject* app) { application = app; }
    // Converts the raw input into a Parsed Command. See ParserObject.h.
    ParsedCommand parse(string rawInput);
    // Returns true if cmds contains str.
    bool contains(string str);
    // Simplifies a command. ie, reduce a command's alt to it's meta value.
    string simplifyCommand(string str);
    // List of valid command.
    vector<Command> cmds;
    friend class App;
private:
    AppObject* application;
};

#endif
