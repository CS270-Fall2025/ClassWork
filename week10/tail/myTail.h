#ifndef MYTAIL_H
#define MYTAIL_H
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//#define MAX_LINE_LENGTH 256
#define SIZE_BUFFER 2048

void wrongArg();
void printLastNLines(char * file, int n);
void printFirstNLines(char * file, int n);
void printTenLines(char * file);
void lastOrFirst(char * args[]);
int openFile(char * file);
int readFileIntoArray(char **lines, int fd, int * full, int numLines);
void printLines(char **lines, int start, int count, int numLines);
int isNumber(char * value);
void freeMemory(char **lines, int numLines);

#endif