#include <unistd.h>
#include <string>
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
#include <dirent.h>
#include <iostream>
#include "./Parser/Termcolor.h"

#include "./Parser/Parser.h"

using namespace std;

int isDirectory(const char *path) {
   struct stat statbuf;
   if (stat(path, &statbuf) != 0)
       return 0;
   return S_ISDIR(statbuf.st_mode);
}

int isRegFile(const char *path) {
   struct stat statbuf;
   if (stat(path, &statbuf) != 0)
       return 0;
   return S_ISREG(statbuf.st_mode);
}

// https://www.geeksforgeeks.org/c-program-list-files-sub-directories-directory/
short int ls(string dir)
{
    if(dir == "help") {
        cout << "* ls - Color Map:\n";
        cout << "* \t" << DIRECTORY << "Directory\n" << termcolor::reset;
        cout << "* \t" << FILE << "File\n" << termcolor::reset;
        cout << "* \t" << README << "Readme.md\n" << termcolor::reset;
        cout << "* \t" << C_CPP << "Source.{c, cpp, h, hpp}\n" << termcolor::reset;
        cout << "* \t" << JAVASCRIPT << "JavaScript.js\n" << termcolor::reset;
        cout << "*\n";
        return EXIT_SUCCESS;
    }
    struct dirent *de;  // Pointer for directory entry

    // opendir() returns a pointer of DIR type.
    DIR *dr;
    if(dir.size() == 0) {
         dr = opendir(".");
    } else {
        dr = opendir(dir.c_str());
    }

    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 0;
    }

    // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
    // for readdir()
    while ((de = readdir(dr)) != NULL) {
        string filename(de->d_name);
        // If it's a .js, .cpp, .h, or .md file.
        if(filename.find(".js") != string::npos) {
            cout << JAVASCRIPT << filename << termcolor::reset << " ";
        } else if (filename.find(".cpp") != string::npos || filename.find(".c") != string::npos ||
                   filename.find(".h") != string::npos || filename.find(".hpp") != string::npos) {
            cout << C_CPP << filename << termcolor::reset << " ";
        } else if (filename.find(".md") != string::npos) {
            cout << README << filename << termcolor::reset << " ";
        }
        // Check it doesn't contain a period then print it.
        else if((filename.find_first_of("." ) == string::npos)) {
            if(filename != "Makefile" && isDirectory(filename.c_str())) {
                cout << DIRECTORY << filename << termcolor::reset << " ";
            } else if (isRegFile(filename.c_str())) {
                cout << FILE << filename << termcolor::reset << " ";
            }
        }
    }
    cout << endl;
    closedir(dr);
    return 0;
}
