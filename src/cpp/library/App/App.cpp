#include "./App.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

App::App()
{
    Setup();
    parser.bindAppObject(this);
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
    for(Command cmd : parser.cmds) {
        cout << "> \t * " + cmd.cmd + "\t\t : ";
        int i = 0;
        for(string str : cmd.alts) {
            cout << str;
            if(i != cmd.alts.size() - 1) {
                cout << ", ";
            }
        }
        if(cmd.description.size()) {
            cout << "\n> \t ->" + cmd.description + "\n>\n";
        } else {
            cout << "\n>\n";
        }
    }
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
        cmd = parser.parse(string(buf));
        if(cmd.problem) {
            cmd.problem->run(cmd.input);
        } else if (cmd.command == "help"){
            help();
        }
    } while(cmd.command != "exit");
}
