#ifndef WAVFILE_H
#define WAVFILE_H

#include <stdio.h>
#include <inttypes.h>

FILE * wavfile_open( const char *filename,int sampsrate);
void wavfile_write( FILE *file, short data[], int length );
void wavfile_close( FILE * file );

#endif
