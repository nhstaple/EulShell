// library/App/AppTest.cpp

#include "./App.h"
#include <iostream>

using namespace std;

void testHelp()
{
    cout << "* test - Help\n";
}

void App::test(TestCommand *cmd)
{
/** Check flags. **/
/** Check for help. **/
    if(cmd->flags["help"]) {
        testHelp();
        return;
    }

/** Validate input. **/
    if(cmd->flags["error"]) {
        return;
    }
    if(!cmd->problem) {
        cout << "< Error: problem does not exist: " << cmd->problem << endl;
        return;
    }
    if(cmd->numTestIterations <= 0) {
        cout << "< Error: please enter a number of test cases greater than 0.\n";
        testHelp();
        return;
    }

/** Do the testing. **/
    nanoseconds total = nanoseconds(0);
    for(int i = 0; i < cmd->numTestIterations; i++) {
        nanoseconds res = cmd->problem->run(cmd->input, cmd->flags["display"]);
        total = nanoseconds(total.count() + res.count());
    }
    cout << "* " << cmd->numTestIterations << " tests with an average of: " << total.count()/cmd->numTestIterations << " nanoseconds.\n";
}
