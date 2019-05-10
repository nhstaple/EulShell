#include "./Parser.h"
#include "../App.h"
#include <string>
#include <sstream>
#include <iostream>
#include <locale>

using namespace std;

Parser::Parser(AppObject* app)
{
    application = app;
    vector<InterfaceAtom> data;
    /** Setup util commands. **/
    Command help("help");
    help.alts.push_back("halp");
    help.alts.push_back("h");
    help.description = "Displays the help information.";

    Command exit("exit");
    exit.alts.push_back("e");
    exit.alts.push_back("bye");
    exit.alts.push_back("q");
    exit.alts.push_back("quit");
    exit.alts.push_back("I'm making my own shell with black jack and hookers.");
    exit.description = "Terminates the application.";

    Command cd("cd");
    cd.alts.push_back("changedir");
    cd.alts.push_back("change_directory");
    cd.description = "*NIX operating systems only. Runs cd.";
    data.push_back(InterfaceAtom(string("std::string"), string("directory"), bool(false)));
    cd.params->set(data);
    data.clear();

    Command pwd("pwd");
    pwd.alts.push_back("printdir");
    pwd.alts.push_back("print_directory");
    pwd.description = "Prints the working directory.";

    Command ls("ls");
    ls.alts.push_back("list");
    ls.alts.push_back("show");
    ls.description = "Prints all valid files and subdirectories.";
    data.push_back(InterfaceAtom(string("std::string"), string("directory"), bool(true)));
    ls.params->set(data);
    data.clear();

    Command read("read");
    read.alts.push_back("cat");
    read.alts.push_back("open");
    read.description = "Displays the content of the file.";
    data.push_back(InterfaceAtom(string("std::string"), string("file"), bool(false)));
    read.params->set(data);
    data.clear();

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
    data.push_back(InterfaceAtom(string("int"), string("const1"), bool(false)));
    data.push_back(InterfaceAtom(string("int"), string("const2"), bool(false)));
    data.push_back(InterfaceAtom(string("int"), string("max"), bool(false)));
    data.push_back(InterfaceAtom(string("std::string"), string("help"), bool(true)));
    e001.params->set(data);
    data.clear();

    eulerCmds.push_back(e001);
}

// True if str is a util or euelr command.
bool Parser::contains(string &str){
    return isUtil(str) || isEulerCmd(str);
}

// True if str is a util command and simplifies it.
bool Parser::isUtil(string &str)
{
    for(Command cmd : utilCmds) {
        if(cmd.cmd == str)
            return true;
        for(string alt : cmd.alts) {
            if(alt == str) {
                str = cmd.cmd;
                return true;
            }
        }
    }
    return false;
}

// True if str is an euler command and simplifies it.
bool Parser::isEulerCmd(string &str)
{
    for(Command cmd : eulerCmds) {
        if(cmd.cmd == str)
            return true;
        for(string alt : cmd.alts) {
            if(alt == str) {
                str = cmd.cmd;
                return true;
            }
        }
    }
    return false;
}

string Parser::simplifyCommand(string str)
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

/** Tokenize each iteration. **/
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
        // If the the first command is valid then simplify it and set the field in the data structure.
        if(i == 0 && contains(token)) {
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
    // Return value.
    ParsedCommand res;
/** Tokenize the input. **/
    vector<DataItem*> data = tokenize(rawInput, res);

    // Set the input.
    res.input->set(data);

    // Check if command is valid then set the problem pointer.
    if(res.command.length() > 0 && isEulerCmd(res.command)) {
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
    for(auto d : data) {
        if(d)
            delete d;
    }

    return res;
}

