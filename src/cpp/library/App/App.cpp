#include "./App.h"
#include <string>
#include <vector>
#include <iostream>
#include <chrono>

extern short int cd(string path);
extern short int ls(string dir);
extern short int pwd();
extern short int read(ParsedCommand &cmd);

using namespace std;
using namespace std::chrono;

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
    }
}

void App::help()
{
    cout << "> github/nhstaple/Project-Euler C++ Help\n";
    cout << "> Available commands:";
    for(Command cmd : parser->utilCmds) {
        cmd.printObject();
        cout << "\n>";
    }
    cout << " Available solutions:";
    for(Command cmd : parser->eulerCmds) {
        cmd.printObject();
        cout << "\n>";
    }
    cout << endl;
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

        /** Perform shell commands. **/
        checkFunctions(cmd);
        if(cmd.problem) {
            nanoseconds time = cmd.problem->run(cmd.input);
            cout << "* Time := " << time.count() << endl;
        } else if (cmd.command == "help"){
            help();
        } else if(cmd.command == "read") {
            read(cmd);
        }
        /** **/
    } while(cmd.command != "exit");
}

void App::checkFunctions(ParsedCommand &cmd)
{
#if (defined(__linux__) || (__unix__) || (__APPLE__))
    if(cmd.command == "pwd") {
        pwd();
        cmd.command = "parsed";
    } else if (cmd.command == "cd") {
        string *path = nullptr;
        if(cmd.input->getInterfaceCopy().size() > 0) {
            path = cmd.input->getInterfaceCopy()[0].data.getString();
        } else {
            path = new string("");
        }
        if(path) { cd(*path); }
        else { cd("@"); }
        cmd.command = "parsed";
        delete path;
    } else if(cmd.command == "ls") {
        // The user supplied input.
        if(cmd.input->getInterfaceCopy().size() > 0) {
            string *dir = cmd.input->getInterfaceCopy()[0].data.getString();
            if(parser && parser->contains(*dir)) {
                *dir = parser->simplifyCommand(*dir);
            }
            ls(*dir);
            cmd.command = "parsed";
            delete dir;
        } else {
            // Print the current directory.
            ls(".");
            cmd.command = "parsed";
        }
    }

#else
    if(res.command == "pwd" || res.command == "cd" || res.command == "ls") {
        cout << "< Erorr: your operating system is not supported!\n";
        res.command = "parsed";
    }
#endif
}
