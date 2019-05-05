#ifndef _PARSER_H_
#define _PARSER_H_

#include "../../../euler/Euler.h"
#include <vector>
#include <array>
#include <map>

class ParsedCommand {
public:
    ParsedCommand() {}

    std::string command;
    Euler* problem = nullptr;
    std::vector<DataItem> input;
};

class Parser {
public:
    Parser() {}
    ParsedCommand parse(std::string rawInput);
    std::string cmds[3] = { "help", "001", "empty"};
};

#endif
