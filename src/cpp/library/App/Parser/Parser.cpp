#include "./Parser.h"
#include "../App.h"
#include <string>
#include <sstream>
#include <iostream>
#include <locale>

using namespace std;

Parser::Parser()
{
    Command help("help");
    help.alts.push_back("halp");
    help.alts.push_back("h");
    help.description = "Displays the help information.";

    Command exit("exit");
    exit.alts.push_back("e");
    exit.alts.push_back("exit");
    exit.alts.push_back("bye");
    exit.alts.push_back("q");
    exit.alts.push_back("quit");
    //exit.description = "Terminates the application.";

    Command e001("e001");
    e001.alts.push_back("001");
    e001.description = "Multiples of 3 and 5";

    cmds.push_back(help);
    cmds.push_back(exit);
    cmds.push_back(e001);
}

bool Parser::contains(string str){
    for(Command cmd : cmds) {
        if(cmd.cmd == str)
            return true;
        for(string alt : cmd.alts) {
            if(alt == str)
                return true;
        }
    }
    return false;
}

std::string Parser::simplifyCommand(std::string str)
{
    if(!contains(str)) { return ""; }
    for(Command cmd : cmds) {
        if(cmd.cmd == str)
            return cmd.cmd;
        for(string alt : cmd.alts) {
            if(alt == str)
                return cmd.cmd;
        }
    }
    return "";
}

ParsedCommand Parser::parse(std::string rawInput)
{
    istringstream iss(rawInput);
    std::string token;
    ParsedCommand res;
    DataItem data;
    vector<DataItem> in;
    int i = 0;
    /** Tokenize. **/
    while (std::getline(iss, token, ' '))
    {
        { // Convert the token to lower case for easy parsing.
            string lowerCase;
            for(char c : token) {
                lowerCase += tolower(c);
            }
            token = lowerCase;
        }

        /** Do the parsing. **/
        bool flag = contains(token);

        if(i == 0 && flag) {
            token = simplifyCommand(token);
            res.command = token;
        } else if (i == 0 && !flag) {
            cout << "Error: invalid command \"" + token + "\".\n";
            res.command = "error";
            res.problem = nullptr;
            return res;
        }else {
            // Set the atom. Do some type checking.
            data = DataItem(token);
            int *ptr = data.getInt();
            if(ptr) { cout << *ptr << endl; free(ptr); }
            in.push_back(data);
        }
        i++;
    }

    res.input.set(in);
    res.input.print();

    // Check if command is valid then set the problem pointer.
    if(res.command.length() > 0 &&
            res.command != "exit" &&
            res.command != "help") {
        string problem = res.command;
        // Get the dictionary
        res.problem = static_cast<App*>(application)->eulerDictionary[res.command];
        if(!res.problem) {
            res.command = "error";
            res.problem = nullptr;
            res.input.reset();
        }
    }

    return res;
}
