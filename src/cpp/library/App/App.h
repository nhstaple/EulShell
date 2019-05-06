#ifndef _APP_H_
#define _APP_H_

#include "../../euler/Euler.h"
#include "./AppObject.h"
#include "./Parser/Parser.h"
#include <map>

#define MAX_CMD_LENGTH 256

class App : AppObject {
public:
    App();
    void prompt();
    void run();
    void help();
    void welcome();
    void printAppObject() override;

    friend class Parser;
private:
    /** Parsing Stuff **/
    Parser parser;

    /** Euler Stuff **/
    std::map<std::string, Euler*> eulerDictionary;
    void Setup();
    void Setup001();
};

#endif
