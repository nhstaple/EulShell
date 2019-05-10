// library/App/read.cpp

/** Unix family includes. **/
#if (defined(__linux__) || (__unix__) || (__APPLE__))

#include <unistd.h>
extern int isDirectory(const char *path);

/** Windows and such. **/
#else
// Windows
#if (defined(_WIN32) || defined(_WIN64))
// TO DO
#endif // Windows

#endif // Unix

#include <iostream>
#include <string>
#include "./Parser/ParserObject.h"
#include "./Parser/EulerInterface/EulerInterface.h"

using namespace std;

short int read(string &filepath)
{
/** Unix family of operating systems. **/
#if (defined(__linux__) || (__unix__) || (__APPLE__))
    bool canView = false;
    string filename = filepath;
    if(filename.find(".js") != string::npos) {
        canView = true;
    } else if (filename.find(".cpp") != string::npos || filename.find(".c") != string::npos || filename.find(".h") != string::npos || filename.find(".hpp") != string::npos) {
        canView = true;
    } else if (filename.find(".md") != string::npos) {
        canView = true;
    }
    // Check it doesn't contain a period then print it.
    else if((filename.find_first_of("." ) == string::npos)) {
        if(filename == "Makefile") {
            canView = true;
        }
    }
    if(fork() == 0) {
        char *ptr = new char[filename.size()];
        for(unsigned int i = 0; i < filename.size(); i++)
            ptr[i] = filename.c_str()[i];
        // Declaring new memory per C++11 standards.
        char cmd[] = "cat";
        char *args[] = { cmd, ptr, nullptr };
        execvp(args[0], args);
        exit(-1);
    } else {
        int status = 0;
        wait(&status);
        if(status < 0) { return EXIT_FAILURE;}
    }
    return EXIT_SUCCESS;

/** All other operating systems. **/
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
