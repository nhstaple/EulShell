#include "./Parser.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

ParsedCommand Parser::parse(std::string rawInput)
{
    istringstream iss(rawInput);
    std::string token;
    ParsedCommand res;
    int i = 0;
    while (std::getline(iss, token, '-'))
    {
        if(i == 0) {
            res.command = token;
        } else {
            // TO DO add input
        }
        // std::cout << token << std::endl;
    }
    return res;
}
