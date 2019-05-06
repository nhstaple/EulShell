#pragma once
#ifndef _PARSER_H_
#define _PARSER_H_

#include "../../../euler/Euler.h"
#include "../AppObject.h"
#include <vector>
#include <array>
#include <map>

#define NUM_VALID_COMMANDS 9

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

class Parser {
public:
    Parser();
    void bindAppObject(AppObject* app) { application = app; }
    ParsedCommand parse(std::string rawInput);
    bool contains(std::string str);
    std::string simplifyCommand(std::string str);
    std::vector<Command> cmds;
    friend class App;
private:
    AppObject* application;
};

#endif
