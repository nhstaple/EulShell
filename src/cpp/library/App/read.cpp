#include <iostream>
#include <string>
#include "./Parser/ParserObject.h"
#include "./Parser/EulerInterface/EulerInterface.h"

#if (defined(__linux__) || (__unix__) || (__APPLE__))
#include <unistd.h>
#endif

extern int isDirectory(const char *path);

using namespace std;

short int read(ParsedCommand &cmd)
{
#if (defined(__linux__) || (__unix__) || (__APPLE__))
    bool canView = false;
    string filename;
    if(cmd.input->getInterfaceCopy().size() > 0) {
        cmd.input->getInterfaceCopy()[0].data.getString(filename);

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

            char *args[] = { "cat", ptr, nullptr };
            execvp(args[0], args);
            exit(-1);
        } else {
            int status = 0;
            wait(&status);
            if(status < 0) { return EXIT_FAILURE;}
        }

    } else {
        cout << "< Error: please enter a file.\n";
    }
    return EXIT_SUCCESS;
#else
    if(res.command == "pwd" || res.command == "cd" || res.command == "ls") {
        cout << "< Erorr: your operating system is not supported!\n";
        res.command = "parsed";
    }
    return EXIT_FAILURE;
#endif
}
