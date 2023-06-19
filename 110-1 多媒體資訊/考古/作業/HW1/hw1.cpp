#include <iostream>
#include <fstream>
#include <math.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define _USE_MATH_DEFINES

struct wavfile_header {
    char    riff_tag[4];
    int    riff_length;
    char    wave_tag[4];
    char    fmt_tag[4];
    int    fmt_length;
    short    audio_format;
    short    num_channels;
    int    sample_rate;
    int    byte_rate;
    short    block_align;
    short    bits_per_sample;
    char    data_tag[4];
    int    data_length;
};

FILE * wavfile_open( const char *filename,int sampsrate)
{
    struct wavfile_header header;

    int samples_per_second = sampsrate;
    int bits_per_sample = 16;

    strncpy(header.riff_tag,"RIFF",4);
    strncpy(header.wave_tag,"WAVE",4);
    strncpy(header.fmt_tag,"fmt ",4);
    strncpy(header.data_tag,"data",4);

    header.riff_length = 0;
    header.fmt_length = 16;
    header.audio_format = 1;
    header.num_channels = 1;
    header.sample_rate = samples_per_second;
    header.byte_rate = samples_per_second*(bits_per_sample/8);
    header.block_align = bits_per_sample/8;
    header.bits_per_sample = bits_per_sample;
    header.data_length = 0;

    FILE * file = fopen(filename,"wb+");
    if(!file) return 0;

    fwrite(&header,sizeof(header),1,file);

    fflush(file);

    return file;

}

void wavfile_write( FILE *file, short data[], int length )
{
    fwrite(data,sizeof(short),length,file);
}

void wavfile_close( FILE *file )
{
    int file_length = ftell(file);

    int data_length = file_length - sizeof(struct wavfile_header);
    fseek(file,sizeof(struct wavfile_header) - sizeof(int),SEEK_SET);
    fwrite(&data_length,sizeof(data_length),1,file);

    int riff_length = file_length - 8;
    fseek(file,4,SEEK_SET);
    fwrite(&riff_length,sizeof(riff_length),1,file);

    fclose(file);
}

int main(){
	
	double frequency;
    double frequency2=1480.0;
    double frequency3=2200.0;
    int volume = 10000;
    int sampsrate;
    int wav;
    
    printf("choose the mode to generate (1~6) : ");
    scanf("%d", &wav);
    
	if((wav>=1)&&(wav<=6)){
		
		printf("Frequency : ");
    scanf("%lf", &frequency);
    
    switch (wav) {
        case 1:
            sampsrate = 100;
            break;
        
        case 2:
            sampsrate = 22050;
            break;
        
        case 3:
            sampsrate = 11025;
            break;
            
        case 4:
            sampsrate = 11025;
            break;
            
        case 5:
        sampsrate = 44100;
        break;
        case 6:
        sampsrate = 44100;
        break;
    }
    
    int num_samples = (sampsrate*8);
    short waveform[num_samples];
    int length = num_samples;
    
    if(wav==4){
        
        int i;
        for(i=0;i<length;i+=2) {
            double t = (double) i / sampsrate;
            waveform[i] = volume*cos(frequency*t*2*M_PI);
            waveform[i+1] = waveform[i];
        }

    }
    else if(wav==5){
        int i;
        
        for(i=0;i<length/2;i+=3) {
            double t = (double) i / sampsrate;
            waveform[i] = volume*cos(frequency*t*2*M_PI);
            waveform[i+1] = volume*cos(frequency2*t*2*M_PI);
            waveform[i+2] = volume*cos(frequency3*t*2*M_PI);
        }
        for(i=length/2;i<length;i++) {
            double t = (double) i / sampsrate;
            waveform[i] = volume*cos(frequency*t*2*M_PI);
            waveform[i+1] = volume*cos(frequency2*t*2*M_PI);
            waveform[i+2] = volume*cos(frequency*t*2*M_PI);
        }

    }
    else if(wav ==6){
    	int i;
    	for(i=0;i<length;i++) {
            double t = (double) i / sampsrate;
            waveform[i] = (volume*cos(frequency*t*2*M_PI)+volume*cos(frequency2*t*2*M_PI))/2;
            //waveform[i+1] = volume*cos(frequency2*t*2*M_PI);
        }
	}
    else{
        
        int i;
        for(i=0;i<length;i++) {
            double t = (double) i / sampsrate;
            waveform[i] = volume*cos(frequency*t*2*M_PI);
        }
        
    }
    
    

    FILE * f = wavfile_open("sound.wav",sampsrate);
    if(!f) {
        printf("couldn't open the file for writing: %s",strerror(errno));
        return 1;
    }

    wavfile_write(f,waveform,length);
    wavfile_close(f);
	}
    
	return 0;
}
