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

using namespace std;

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
            cout << "< Error: " << strerror(errno) << endl;
        }
    }
    return EXIT_FAILURE;
}
