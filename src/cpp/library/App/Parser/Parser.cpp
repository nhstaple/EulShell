// library/App/Parser/Parser.cpp

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
    data.push_back(InterfaceAtom(string("std::string"), string("command"), bool(true)));
    help.params->set(data);
    data.clear();

    Command exit("exit");
    exit.alts.push_back("e");
    exit.alts.push_back("bye");
    exit.alts.push_back("q");
    exit.alts.push_back("quit");
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

    Command test("test");
    test.alts.push_back("sample");
    test.alts.push_back("experiment");
    test.alts.push_back("exper");
    test.description = "Runs an Euler problem.";
    data.push_back(InterfaceAtom(string("std::string"), string("euler problem"), bool(false)));
    data.push_back(InterfaceAtom(string("int"), string("num of iterations"), bool(false)));
    data.push_back(InterfaceAtom(string("std::string"), string("display flag"), bool(true)));
    data.push_back(InterfaceAtom(string("std::string"), string("all flag"), bool(true)));
    data.push_back(InterfaceAtom(string("std::string"), string("js flag"), bool(true)));
    data.push_back(InterfaceAtom(string("std::string"), string("python flag"), bool(true)));
    test.params->set(data);
    data.clear();

    utilCmds.push_back(help);
    utilCmds.push_back(exit);
    utilCmds.push_back(pwd);
    utilCmds.push_back(cd);
    utilCmds.push_back(ls);
    utilCmds.push_back(read);
    utilCmds.push_back(test);

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
    if(!contains(str)) { return str; }
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
    return str;
}

vector<DataItem*> Parser::tokenize(string &rawInput, ParsedCommand *res)
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
        if(contains(token) && i == 0) {
            res->command = token;
        } else if (i == 0) {
            // Else if the command is not valid.
            cout << "< Error: invalid command \"" + token + "\".\n";
            res->command = "error";
            res->problem = nullptr;
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

TestCommand* Parser::parseTestCmd(ParsedCommand* cmd)
{
/** Validate input. **/
    if(cmd == nullptr) { return nullptr; }

/** Seed return data. **/
    TestCommand *test = new TestCommand();
    string problem;
    if(cmd->input->getInterfaceCopy().size() > 0 && application) {
        cmd->input->getInterfaceCopy()[0].data.getString(problem);
    } else {
        return nullptr;
    }
    test->command = cmd->command;
    test->problem = static_cast<App*>(application)->eulerDictionary[problem];

    // Validate the user input matches the type of the problem's interface.
    vector<InterfaceAtom> input = cmd->input->getInterfaceCopy();
    vector<InterfaceAtom> dataCopy;
    // 1 to skip the problem name.
    for(unsigned long i = 0; i < test->problem->interface.getInterfaceCopy().size(); i++) {
        if(i + 1 < input.size())
            dataCopy.push_back(input[i+1]);
    }
    Input inputCopy(dataCopy);

/** Check if the input is valid to the problem's interface. **/
    if(inputCopy == test->problem->interface) {
        test->input->set(dataCopy);
        // + 1 for euler problem.
        // + 1 for num of times.
        input[test->problem->interface.getInterfaceCopy().size()].data.getInt(test->numTestIterations);
        for(unsigned long i = 1 + 1 + test->problem->interface.getInterfaceCopy().size(); i < input.size(); i++) {
            string res;
            input[i].data.getString(res);
            test->flags[res] = true;
        }
/** The input is not valid to the problem, so check for input to the test function. **/
    } else {
        // The input does not match the interface.
        // Check if the first input parameter is number of iterations
        if(dataCopy.size() > 0) {
            if(dataCopy[0].data.getInt(test->numTestIterations)) {
                string str;
                for(unsigned int i = 1; i < dataCopy.size(); i++) {
                    if(dataCopy[i].data.getString(str)) {
                        test->flags[str] = true;
                    } else {
                        // It's not a string so it's not a flag. Error!
                        cout << "< Error: bad input!\n";
                        test->flags["error"] = true;
                    }
                }
            }
        } else {
            cout << "< Error: bad input!\n";
        }
    }
    // Cleanup the original data.
    delete cmd;
    // Return the parsed Test Command.
    return test;
}

ParsedCommand* Parser::parse(std::string rawInput)
{
    // Return value.
    ParsedCommand* res = new ParsedCommand;
/** Tokenize the input. **/
    vector<DataItem*> data = tokenize(rawInput, res);

    // Set the input.
    res->input->set(data);

    // Check if command is valid then set the problem pointer.
    if(application) {
        res->problem = static_cast<App*>(application)->eulerDictionary[res->command];
        if(res->problem == nullptr && res->command != "test") {
            // cout << "< Error: please enter a valid problem number.\n";
        } else if(res->command == "test") {
            res = static_cast<ParsedCommand*>(parseTestCmd(res));
        }
    }

/** Clean up the alloced memory. **/
    for(auto d : data) {
        if(d)
            delete d;
    }

    return res;
}

