#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wav.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	//char *audio1 = argv[1];
	char *audio1 = "charleston.wav";
	
   	WAVE a1;
   	FILE *file1;
   	
   	
   	
   	if ((file1 = fopen(audio1,"r") )== NULL){
   		
   		printf("qualcosa è andato storto aprendo il file: %s  \n",audio1);
	   }else{
	   	
	   		printf("apertura file: %s avvenuta con successo  \n",audio1);
			a1 = ReadWave (file1);
			
			int pippo = a1.numofstereosamples;
			printf("num of samples: %d  \n",pippo);
			int i;
			int max=0;
			for(i=0;i<pippo;i++){
				int sample = SAMPLE(a1, 0, i);
				if(sample>max){
					max = sample;
				}
			}
			printf("max val: %d",max);

			
				
	   }
   	
   	
	
	
	return 0;
}
