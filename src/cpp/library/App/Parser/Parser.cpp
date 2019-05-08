#include "./Parser.h"
#include "../App.h"
#include <string>
#include <sstream>
#include <iostream>
#include <locale>

/** Note: need to verify on a linux distro. **/
#if defined(__linux__) || (__unix__) || (__APPLE__)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libgen.h>
#include <ctype.h>

using std::endl;
short int cd(string path);

/** Do other platforms. **/
#else
#endif

using namespace std;

Parser::Parser(AppObject* app)
{
    application = app;
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

    Command e001("e001");
    e001.alts.push_back("001");
    e001.description = "Multiples of 3 and 5.";

    Command cd("cd");
    cd.alts.push_back("changedir");
    cd.alts.push_back("change_directory");
    cd.description = "(*NIX operating systems only. Runs cd.";

    Command pwd("pwd");
    pwd.alts.push_back("printdir");
    pwd.alts.push_back("print_directory");
    pwd.description = "Prints the working directory.\n";

    cmds.push_back(help);
    cmds.push_back(exit);
    cmds.push_back(e001);
    cmds.push_back(pwd);
    cmds.push_back(cd);
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
    // Check each command and it's alts for a match.
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
    DataItem* data;
    vector<DataItem*> in;
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
            return res;
        } else {
            // Else set a new atom and push it to the input list.
            data = new DataItem(token);
            in.push_back(data);
        }
        i++;
    }

    res.input->set(in);

    // Check if command is valid then set the problem pointer.
    if(res.command.length() > 0 && res.command != "exit" && res.command != "help" && res.command != "pwd" && res.command != "cd") {
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

    /** Perform shell commands. **/
#if (defined(__linux__) || (__unix__) || (__APPLE__))
    if(res.command == "pwd") {
        // If you're the child then exec!
        if(fork() == 0) {
            char *list[3] = { "pwd", "-P", nullptr };
            execvp("pwd", list);
            exit(-1);
        }
        // Else you're the parent and wait.
        else {
            int status = 0;
            wait(&status);
            res.command = "parsed";
        }
    } else if (res.command == "cd") {
        string *path = res.input->getInterfaceCopy()[0].data.getString();
        cd(*path);
        res.command = "parsed";
    }
#else
    if(res.command == "pwd" || res.command == "cd") {
        cout << "< Erorr: your operating system is not supported!\n";
        res.command = "parsed";
    }
#endif
    // Delete the allocated memory.
    for(DataItem* d : in) {
        delete d;
    }
    return res;
}

short int cd(string path)
{
    // If there was no input.
    if(path.size() == 0) {
        cout << "< Error: Please include a directory as an argument.\n";
        return EXIT_FAILURE;
    // If the path is the current directory.
    } else if(strcmp(path.c_str(), ".") == 0) {
        return EXIT_SUCCESS;
    // If the path is the parent.
    } else if(strcmp(path.c_str(), "..") == 0) {
        char tmp[512];
        getcwd(tmp, 512);
        // Check if root.
        if(strcmp(tmp, "/") == 0) {
            cout << "@ root\n";
            return EXIT_SUCCESS;
        } else {
            char *parent = dirname(tmp);
            chdir(parent);
            return EXIT_SUCCESS;
        }
    } else {
        char tmp[512];
        getcwd(tmp, 512);
        // Check if root.
        if(chdir(path.c_str()) == 0) {
            return EXIT_SUCCESS;
        } else {
            cout << "> Error: " << strerror(errno) << endl;
        }
    }
    return EXIT_FAILURE;
}
