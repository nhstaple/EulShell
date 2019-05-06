#ifndef _PARSER_H_
#define _PARSER_H_

#include "../../../euler/Euler.h"
#include "../AppObject.h"
#include "./ParserObject.h"
#include <vector>
#include <array>
#include <map>

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
