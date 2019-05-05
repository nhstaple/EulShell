#ifndef _APP_H_
#define _APP_H_

#include "../../euler/Euler.h"
#include "./Parser/Parser.h"
#include <map>

#define MAX_CMD_LENGTH 256

class App {
public:
    App();
    void run();
private:
    /** Parsing Stuff **/
    Parser parser;

    /** Euler Stuff **/
    std::map<std::string, Euler*> eulerDictionary;
    void Setup();
    void Setup001();
};

#endif
