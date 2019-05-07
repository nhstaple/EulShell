#ifndef PARSEROBJECT_H
#define PARSEROBJECT_H
#include <string>
#include <vector>
using std::string;
using std::vector;

class Euler;
class EulerInterface;

class ParserObject
{
public:
    ParserObject() {}
    virtual void printObject()=0;
};

class Command : public ParserObject {
public:
    Command() {}
    Command(string str) : cmd(str) {}
    void printObject() override;
    string cmd;
    string description;
    vector<string> alts;
};

class ParsedCommand : public ParserObject {
public:
    ParsedCommand();
    ~ParsedCommand() { delete input; }
    void printObject() override;
    void operator=(const ParsedCommand& cmd);
    string command;
    Euler* problem = nullptr;
    EulerInterface* input;
};

#endif // PARSEROBJECT_H
