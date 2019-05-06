#ifndef PARSEROBJECT_H
#define PARSEROBJECT_H

#include "./EulerInterface/EulerInterface.h"

class ParserObject
{
public:
    ParserObject();
    virtual void printObject()=0;
};

class Command {
public:
    Command() {}
    Command(std::string str) : cmd(str) {}
    std::string cmd;
    std::string description;
    std::vector<std::string> alts;
};

class ParsedCommand {
public:
    ParsedCommand() {}

    std::string command;
    Euler* problem = nullptr;
    EulerInterface input;
};

#endif // PARSEROBJECT_H
