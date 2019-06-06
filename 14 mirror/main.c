#include <stdio.h>
#include <stdlib.h>
#include "qdbmp.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	BMP* file;
	char *imgI = "image.bmp";
	//char *imgI = argv[1];
	//char *imgO = "image2.bmp";
	char imgO[200] = "";
	trasla(imgI,imgO);
	
	file = BMP_ReadFile(imgI);
	int z = controllo(file,imgI);
	//printf("controllo: %d\n",z);
	
	if(!z){
		printf("mirroring dell'immagine\n");
		mirror(file,imgO);
	}
	
	
	return 0;
}

void mirror(char *file, char *imgO){
	int riga;
	int colonna;
	char r;
	char g;
	char b;
	char mr;	
	char mg;
	char mb;
	unsigned int a = BMP_GetHeight(file);
	unsigned int l = BMP_GetWidth(file);
	
	for(riga=0; riga<a; riga++)
	{
		for(colonna=0; colonna<(l/2); colonna++)
		{
			BMP_GetPixelRGB(file, colonna, riga, &r, &g, &b ); 
			
			BMP_GetPixelRGB(file, l - colonna -1, riga, &mr, &mg, &mb ); 
			
			BMP_SetPixelRGB(file, colonna, riga, mr, mg, mb); 
		}
	}
	BMP_WriteFile(file,imgO);
	printf("mirroring dell'immagine completato\n");
	
}

int controllo(char *file,char *imgI){
	int err=0;
	if ((file = BMP_ReadFile(imgI) )== NULL){
		err++;
		printf("qualcosa e' andato storto aprendo i file: %s\n",imgI);
	}else{
		
	}
	return err;	
}

int count(char *stringa){				
	int i=0;
	while(stringa[i] != '\0' ){
		i++;
	}
	return i;	
}

void trasla(char *nome1,char *nome2){				
	
	int a = count(nome1);
	int i=0;
	int b=0;
	printf("nome del file di input: %s\n",nome1);
	
	for(i=0; i != (a+1);i++){
		
		nome2[i] = nome1[b];
		if(i==(a-4)){
			nome2[i]= '2';
			b = b-1;
		}
		b++;
	}
	nome2[a+1] = '\0';
	printf("nome del file di output: %s\n",nome2);
}
