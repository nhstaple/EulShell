// library/App/Parser/ParserObject.h
#ifndef PARSEROBJECT_H
#define PARSEROBJECT_H

/*
 * Parser Object
 *
 * These are objects used and created by the parser.
*/

#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

class Euler;
class EulerInterface;

// Abstract class used for polymoprphism and such.
class ParserObject
{
public:
/** Constructors. **/
    ParserObject() {}
    virtual ~ParserObject() {}
/** Prints functions. **/
    virtual void printObject()=0;
};

// Command- hosts viable command data. Instantiated in Parser::Parser()
class Command : public ParserObject {
public:
/** Constructors. **/
    Command();
    Command(string str);
    ~Command() override;

/** Prints functions. **/
    void printObject() override;

/** Public variables. **/
    // The actual command.
    string cmd;
    // The text description of what it does.
    string description;
    // The set of alternatives commands. Shorthands, subs, etc.
    vector<string> alts;
    // The parameters accepted by its command.
    EulerInterface *params;
};

// ParsedCommand - returned by the parser to App::App. The interface is used to exec programs.
class ParsedCommand {
public:
/** Constructors. **/
    ParsedCommand();
    ~ParsedCommand();

/** Prints functions. **/
    void printObject();

/** Overloaded operators. **/
    void operator=(const ParsedCommand& cmd);

/** Public variables. **/
    string command;
    Euler *problem;
    EulerInterface *input;
};

class TestCommand : public ParsedCommand {
public:
    TestCommand() {}
    map<string, bool> flags;
    int numTestIterations = 0;
};

#endif // _PARSEROBJECT_H
