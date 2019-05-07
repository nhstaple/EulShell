#include "./App.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

App::App()
{
    Setup();
    parser = new Parser(this);
}

void App::prompt()
{
    cout << "Euler -> ";
}

void App::printAppObject()
{
    for(std::pair<std::string, Euler*> x : eulerDictionary) {
        cout << x.first << endl;
        // x.second->run();
    }
}

void App::help()
{
    cout << "> github/nhstaple/Project-Euler C++ Help\n";
    cout << "> \tAvailable commands:\n";
    for(Command cmd : parser->cmds)
        cmd.printObject();
}

void App::welcome()
{
    cout << "> Welcome to github/nhstaple/Project-Euler C++!\n";
    cout << "> This is kind of a crappy shell for running my C++ solutions.\n";
    cout << "> For more information, or if you're stuck, enter \"help\".\n";
}

void App::run()
{
    welcome();
    ParsedCommand cmd;
    char buf[MAX_CMD_LENGTH];
    do {
        prompt();
        cin.getline(buf, MAX_CMD_LENGTH);
        cmd = parser->parse(string(buf));
        if(cmd.problem) {
            cmd.problem->exec(cmd.input);
        } else if (cmd.command == "help"){
            help();
        }
    } while(cmd.command != "exit");
}
