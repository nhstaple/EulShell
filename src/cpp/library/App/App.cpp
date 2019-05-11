// library/App/App.cpp

#include "./App.h"
#include <string>
#include <vector>
#include <iostream>
#include <chrono>

extern short int cd(string path);
extern short int ls(string dir);
extern short int pwd(string command);
extern short int read(string filepath);

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

// Assumed that the cmd is valid.
void App::help(string &cmd)
{
    if(cmd.size() == 0) {
        cout << "> github/nhstaple/Project-Euler C++ Help\n";
        cout << "> Available " << COMMAND << "commands" << termcolor::reset << ":";
        for(Command cmd : parser->utilCmds) {
            cmd.printObject();
            cout << "\n>";
        }
        cout << "\n> Available " << EULER_PROBLEM << "problems" << termcolor::reset << ":";
        for(Command cmd : parser->eulerCmds) {
            cmd.printObject();
            cout << "\n>";
        }
        cout << endl;
    } else {
        // Perform checkfunctions with the new command
        // with the parameters set to help.
        ParsedCommand newCmd;
        newCmd.command = cmd;
        newCmd.input = new EulerInterface();
        vector<InterfaceAtom> newInput;
        newInput.push_back(InterfaceAtom(string("help")));
        newCmd.input->set(newInput);
        checkFunctions(newCmd);
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
        cmd = parser->parse(string(buf));

        /** Perform shell commands. **/
        checkFunctions(cmd);

        /** Check for an euler problem. **/
        if(cmd.problem) {
            nanoseconds time = cmd.problem->run(cmd.input);
            cout << "* Time := " << time.count() << " nanoseconds.\n";
        }
    } while(cmd.command != "exit");
    cout << "> Closing the shell... goodbye.\n";
}

void App::checkFunctions(ParsedCommand &cmd)
{
    auto input = cmd.input->getInterfaceCopy();
    string param1 = "";
    if(input.size() > 0) {
        input[0].data.getString(param1);
        param1 = parser->simplifyCommand(param1);
    }

    // See Parser::Parser() for information about the input interface for these functions.
 /** pwd **/
    if(cmd.command == "pwd") {
        pwd(param1);
        cmd.command = "parsed";
    }
/** cd **/
    else if (cmd.command == "cd") {
        if (param1.size() > 0) {
            cd(param1);
        } else {
            cout << "< Error: please provide a directory.\n";
        }
        cmd.command = "parsed";
    }
/** ls **/
    else if(cmd.command == "ls") {
        // The user supplied input.
        if(param1.size() > 0) {
            ls(param1);
        } else if(input.size() == 0) {
            ls(".");
        } else {
           cout << "< Error: invalid input type. Try again with a string.\n";
        }
        cmd.command = "parsed";
    }
/** help **/
    else if(cmd.command == "help") {
        help(param1);
        cmd.command = "parsed";
    }
/** read **/
    else if(cmd.command == "read") {
        // The user supplied input.
        if(cmd.input->getInterfaceCopy().size() > 0) {
            string filepath;
            // Validated input to parameter type.
            if(cmd.input->getInterfaceCopy()[0].data.getString(filepath)) {
                read(filepath);
                cmd.command = "parsed";
            }
        } else {
            cout << "< Error: please provide a filename or path to a file!\n";
        }
    }
}
