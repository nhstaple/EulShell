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
    cout << "> Available commands";
    for(Command cmd : parser->utilCmds) {
        cmd.printObject();
        cout << "\n>";
    }
    cout << " Available solutions";
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

        /** Check for an euler problem. **/
        if(cmd.problem) {
            nanoseconds time = cmd.problem->run(cmd.input);
            cout << "* Time := " << time.count() << " nanoseconds.\n";
        }
    } while(cmd.command != "exit");
}

void App::checkFunctions(ParsedCommand &cmd)
{
 /** pwd **/
    if(cmd.command == "pwd") {
        pwd();
        cmd.command = "parsed";
    }

/** cd **/
    else if (cmd.command == "cd") {
        string path = ".";
        if(cmd.input->getInterfaceCopy().size() > 0)
            cmd.input->getInterfaceCopy()[0].data.getString(path);
        cd(path);
        cmd.command = "parsed";
    }

/** ls **/
    else if(cmd.command == "ls") {
        // The user supplied input.
        if(cmd.input->getInterfaceCopy().size() > 0) {
            string dir;
            if(cmd.input->getInterfaceCopy()[0].data.getString(dir) && parser && parser->contains(dir))
                dir = parser->simplifyCommand(dir);
            ls(dir);
            cmd.command = "parsed";
        } else {
            // Print the current directory.
            ls(".");
            cmd.command = "parsed";
        }
    }

/** help **/
    else if(cmd.command == "help") {
        help();
        cmd.command = "parsed";
    }

/** read **/
    else if(cmd.command == "read") {
        read(cmd);
        cmd.command = "parsed";
    }
}
