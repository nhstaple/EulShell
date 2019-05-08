#include "./Parser.h"
#include "../App.h"
#include <string>
#include <sstream>
#include <iostream>
#include <locale>

/** Note: need to verify on a linux distro. **/
// #if defined(__linux__) || (__unix__) || (__APPLE__)
#include <unistd.h>
using std::endl;

/** Do other platforms. **/
//#else
//#endif

using namespace std;

Parser::Parser(AppObject* app)
{
    application = app;
    /** Setup util commands. **/
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
    exit.description = "Terminates the application.";

    Command cd("cd");
    cd.alts.push_back("changedir");
    cd.alts.push_back("change_directory");
    cd.description = "(*NIX operating systems only. Runs cd.";

    Command pwd("pwd");
    pwd.alts.push_back("printdir");
    pwd.alts.push_back("print_directory");
    pwd.description = "Prints the working directory.";

    Command ls("ls");
    ls.alts.push_back("list");
    ls.alts.push_back("show");
    ls.description = "Prints all .js files and subdirectories.";

    Command read("read");
    read.alts.push_back("cat");
    read.alts.push_back("open");
    read.description = "Displays the content of the file.";

    utilCmds.push_back(help);
    utilCmds.push_back(exit);
    utilCmds.push_back(pwd);
    utilCmds.push_back(cd);
    utilCmds.push_back(ls);
    utilCmds.push_back(read);

    /** Setup Euler commands. **/
    Command e001("e001");
    e001.alts.push_back("001");
    e001.description = "Multiples of 3 and 5.";

    eulerCmds.push_back(e001);
}

bool Parser::contains(string &str){
    return isUtil(str) || isEulerCmd(str);
}

bool Parser::isUtil(string &str)
{
    for(Command cmd : utilCmds) {
        if(cmd.cmd == str)
            return true;
        for(string alt : cmd.alts) {
            if(alt == str)
                return true;
        }
    }
    return false;
}

bool Parser::isEulerCmd(string &str)
{
    for(Command cmd : eulerCmds) {
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
    // Check each command and it's alts for a match.
    for(Command cmd : utilCmds) {
        if(cmd.cmd == str)
            return cmd.cmd;
        for(string alt : cmd.alts) {
            if(alt == str)
                return cmd.cmd;
        }
    }
    for(Command cmd : eulerCmds) {
        if(cmd.cmd == str)
            return cmd.cmd;
        for(string alt : cmd.alts) {
            if(alt == str)
                return cmd.cmd;
        }
    }
    return "";
}

vector<DataItem*> Parser::tokenize(string &rawInput, ParsedCommand &res)
{
    vector<DataItem*> in;
    DataItem* data;
    istringstream iss(rawInput);
    std::string token;
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

        /** Structure the data into useful information. **/
        // consts.
        const bool has_only_digits = (token.find_first_not_of( "0123456789." ) == string::npos);
        // If the the first command is valid then simplify it and set the field in the data structure.
        if(i == 0 && contains(token)) {
            // Simplify turns any alt command into it's meta value.
            token = simplifyCommand(token);
            res.command = token;
        } else if (i == 0) {
            // Else if the command is not valid.
            cout << "< Error: invalid command \"" + token + "\".\n";
            res.command = "error";
            res.problem = nullptr;
            return vector<DataItem*>();
        } else {
            // Else set a new atom and push it to the input list.
            data = new DataItem(token);
            in.push_back(data);
        }
        i++;
    }
    return in;
}

ParsedCommand Parser::parse(std::string rawInput)
{
    ParsedCommand res;
    /** Tokenize the input. **/
    vector<DataItem*> data = tokenize(rawInput, res);

    // Set the input.
    res.input->set(data);

    // Check if command is valid then set the problem pointer.
    if(res.command.length() > 0 &&
            isEulerCmd(res.command)) {
        // Get the dictionary
        if(application)
        {
            res.problem = static_cast<App*>(application)->eulerDictionary[res.command];
            if(res.problem == nullptr) {
                res.command = "error";
                res.problem = nullptr;
                res.input->reset();
            }
        }
    }

    /** Clean up the alloced memory. **/
    for(auto d : data)
        if(d) { delete d; }

    return res;
}

