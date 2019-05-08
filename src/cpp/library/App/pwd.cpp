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
short int pwd()
{
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
        if(status < 0) { return EXIT_FAILURE;}
    }
    return EXIT_SUCCESS;
}
