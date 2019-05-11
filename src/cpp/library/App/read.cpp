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

short int read(string filepath)
{
    if(filepath == "help") {
        cout << "* read - Help\n";
        return EXIT_SUCCESS;
    }
/** Unix family of operating systems. **/
#if (defined(__linux__) || (__unix__) || (__APPLE__))
    bool canView = false;
    string filename = filepath;

/** Check file extensions then set canView flag to true. **/
    if(filename.find(".js") != string::npos) {
        canView = true;
    } else if (filename.find(".cpp") != string::npos || filename.find(".c") != string::npos || filename.find(".h") != string::npos || filename.find(".hpp") != string::npos) {
        canView = true;
    } else if (filename.find(".md") != string::npos) {
        canView = true;
    }
    // Check it doesn't contain a period then print it.
    else if((filename.find_first_of("." ) == string::npos)) {
        if(filename == "Makefile" || filename == "makefile") {
            filename = "makefile";
            canView = true;
        }
    }

    char *ptr = nullptr;
    if(canView) {
        // Copy the filename into a c string for execvp.
        ptr = new char[filename.size() + 1];
        for(unsigned int i = 0; i < filename.size(); i++)
            ptr[i] = filename.c_str()[i];
        ptr[filename.size()] = '\0';
        // If you're the child process.
        if(fork() == 0) {
            // Declaring new memory per C++11 standards.
            char cmd[] = "cat";
            char *args[] = { cmd, ptr, nullptr };
            execvp(args[0], args);
            exit(-1);
        } else {
            // Else you're the parent.
            int status = 0;
            // Wait for the child process.
            wait(&status);
            // If there was an error.
            if(status < 0) {
                if(ptr)
                    delete ptr;
                return EXIT_FAILURE;
            }
        }

    // Else you can't view the file.
    } else {
        // If it's a directory.
        if(isDirectory(filepath.c_str())) {
            cout << "< Error: cannot read a directory! \"" << filepath << "\"\n";
        } else {
            // Else it's a file.
            cout << "< Error: cannot find: " << filepath
                 << ". Is this a legal file extension for EulShell?\n< Type \"read help\" for more info.\n";
        }
        return EXIT_FAILURE;
    }
    if(ptr)
        delete ptr;
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
