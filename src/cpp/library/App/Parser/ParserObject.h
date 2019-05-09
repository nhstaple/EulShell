#ifndef PARSEROBJECT_H
#define PARSEROBJECT_H
// library/App/Parser/ParserObject.h
/*
 * Parser Object - Parser objects
 *
 * These are objects used and created by the parser.
*/
#include <string>
#include <vector>
using std::string;
using std::vector;

class Euler;
class EulerInterface;

// Abstract class used for polymoprphism and such.
class ParserObject
{
public:
    ParserObject() {}
    virtual void printObject()=0;
};

// Command- hosts viable command data. Instantiated in Parser::Parser()
class Command : public ParserObject {
public:
    Command();
    Command(string str);
    ~Command();
    void printObject() override;
    string cmd;
    string description;
    vector<string> alts;
    EulerInterface *params;
};

// ParsedCommand - returned by the parser to App::App. The interface is used to exec programs.
class ParsedCommand : public ParserObject {
public:
    ParsedCommand();
    ~ParsedCommand();
    void printObject() override;
    void operator=(const ParsedCommand& cmd);
    string command;
    Euler *problem = nullptr;
    EulerInterface *input;
};

#endif // PARSEROBJECT_H
