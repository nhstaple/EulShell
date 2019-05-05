#include "./App.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

App::App()
{
    Setup();
}

void App::run()
{
    ParsedCommand cmd;
    do {
        char buf[MAX_CMD_LENGTH];
        cin.getline(buf, MAX_CMD_LENGTH);
        cmd = parser.parse(string(buf));
    } while(cmd.command != "exit");
}
