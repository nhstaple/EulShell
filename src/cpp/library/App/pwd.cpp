// library/App/pwd.cpp

/** Unix family of operating systems. **/
#if (defined(__linux__) || (__unix__) || (__APPLE__))
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libgen.h>
#include <ctype.h>
#include <dirent.h>

/** Windows and such. **/
#else
// Windows
#if (defined(_WIN32) || defined(_WIN64))
// TO DO
#endif // Windows

#endif // Unix

#include <iostream>

using namespace std;
short int pwd(string command)
{
    if(command.size() > 0) {
        cout << "* pwd - Help\n";
        return EXIT_SUCCESS;
    }
/** Unix systems. **/
#if (defined(__linux__) || (__unix__) || (__APPLE__))
    // If you're the child then exec!
    if(fork() == 0) {
        // Instantiated new strings per C++11 standards.
        char cmd[] = "pwd";
        char param[] = "-P";
        char *list[3] = { cmd, param, nullptr };
        execvp("pwd", list);
        exit(-1);
    }
    // Else you're the parent and wait.
    else {
        int status = 0;
        wait(&status);
        if(status < 0) { return EXIT_FAILURE; }
    }
    return EXIT_SUCCESS;

/** All others, ie Windows. **/
#else

    cout << "< Erorr: your operating system is not supported!\n";
    res.command = "parsed";

/** Windows and such. **/
// Windows
#if (defined(_WIN32) || defined(_WIN64))
// TO DO
#endif // Windows

    return EXIT_FAILURE;

#endif // Unix
}
