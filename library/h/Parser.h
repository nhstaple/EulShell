/*
\* Parser.h
\* Nick S.
 *
\* Parser - Computes the user's input into useful information
 *
\* This is a simple look ahead parser.
*/

#ifndef _PARSER_H_
#define _PARSER_H_

#include <vector>
#include <string>
using std::vector;
using std::string;

class Command;
class ParsedCommand;

class Parser
{
public:
    // Empty constructor.
    Parser() {}

    ParsedCommand parse(const string rawInput);
private:
    vector<ParsedCommand> commandHistory;
};

class Command {

};

class ParsedCommand : public Command {

};

#endif // _PARSER_H_
