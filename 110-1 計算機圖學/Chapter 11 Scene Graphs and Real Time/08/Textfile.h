// textfile.h: interface for reading and writing text files  
#ifndef TEXTFILE_H
#define TEXTFILE_H
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char *textFileRead(const char *fn);
int textFileWrite(char *fn, char *s);
unsigned char *readDataFromFile(char *fn);
 
#endif

