#include <stdio.h>
#include <stdlib.h>
#include "wav.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	//char *audio1 = argv[1];
	char *audio1 = "guitar.wav";
	char *audio2 = "grancassa.wav";
	char *audioOut = "pippo.wav";
	
	//char *audioOut;
	//somma(audio1,audio2,audiOut);
	
   	WAVE a1;
   	WAVE a2;
   	WAVE out1;

   	FILE *file1;
   	FILE *file2;
   	FILE *fout1;

   	
   	
   	
   	if ((file1 = fopen(audio1,"rb") )== NULL){
   		
   		printf("qualcosa e' andato storto aprendo il file: %s  \n",audio1);
	   }else{
	   	
	   		printf("apertura file: %s avvenuta con successo  \n",audio1);
	   		
	   		if ((file2 = fopen(audio2,"rb") )== NULL){
	   			printf("qualcosa e' andato storto aprendo il file: %s  \n",audio2);
	   			
			   }else{
			   		printf("apertura file: %s avvenuta con successo  \n",audio2);
			   		
			   		if ((fout1 = fopen(audioOut,"wb") )== NULL){
			   			printf("qualcosa e' andato storto aprendo il file: %s  \n",audioOut);
			   			
			   		}else{
			   			printf("apertura file: %s avvenuta con successo  \n",audioOut);

			   			a1 = ReadWave (file1);
			   			a2 = ReadWave (file2);

			   			long int num = 0;
			   			
			   		
			   			if (a1.numofstereosamples >= a2.numofstereosamples){
			   				num = a1.numofstereosamples;
					   	}else{
					   		num = a2.numofstereosamples;
					   	}
						
						out1 = CreateEmptyCDaudioWave(num);
						long int i;
						long int sample1;
						long int sample2;
						long int sample3;
						
						for(i=0;i<num;i++){
							if (i>a1.numofstereosamples){
								sample1 = 0;
							}else{
								sample1 = SAMPLE(a1, 0, i);
							}
							if (i>a2.numofstereosamples){
								sample2 = 0;
							}else{
								sample2 = SAMPLE(a2, 0, i);
							}
							sample3 = sample1 + sample2;
							if(sample3 > 32760){
								sample3 = 32760;
							}
							if(sample3 < -32760){
								sample3 = -32760;	
							}
							SAMPLE(out1, 0, i) = sample3;
							}
							
							WriteWave (out1, fout1);
							
						 fclose(fout1);
					   	}  		
			   		
				fclose(file2);
			   }
		fclose(file1);
		
	   }
	
	ReleaseWaveData (&a1);
	ReleaseWaveData (&a2);
	ReleaseWaveData (&out1);
	return 0;
}

/*
void somma(char *nome1,char *nome2, char *nomeOut){				
	int a = (count(nome1)-4);
	int b = (count(nome2)-4);
	int i=0;
	
	for(i=0;i<(a+b+1);i++){
		if(i<=a){
			nomeOut[i] = nome1[i];	
		}
		if(i==a+1){
			nomeOut[i] = '+';
		}
		if(i>=a){
			nomeOut[i] = nome2[i];	
		}
		if(i==(a+b)){
		}			
	}		
}*/

int count(char *stringa){					
	long int i=0;
	while(stringa[i] != '\0' ){
		i++;
	}
	return i;
	
}

strconcat(dh);

