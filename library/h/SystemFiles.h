/*
\* SystemFiles.h
\* Nick S.
 *
\* The system files and constants required for crossplatform dev.
*/
#ifndef _SYSTEMFILES_H_
#define _SYSTEMFILES_H_

#include <string>
using std::string;
// Constants
#define BIT 1
#define NIBBLE 4
#define BYTE 8
#define KILOBYTE 1024*BYTE

// Unix family of operating systems.
#if (defined(__linux__) || (__unix__) || (__APPLE__))
#include <unistd.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libgen.h>
#include <ctype.h>
#include <dirent.h>

// Windows and such.
#else
// Windows
#if (defined(_WIN32) || defined(_WIN64))
// TO DO

// ..
#endif // Windows

#endif // Unix

#endif // _SYSTEMFILES_H_
