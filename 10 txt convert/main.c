#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	const char *a[8];
	a[0] = "DO";
	a[1] = "RE";
	a[2] = "MI";
	a[3] = "FA";
	a[4] = "SOL";
	a[5] = "LA";
	a[6] = "SI";
	a[7] = "D06";
	/*
	a[8] = "Do";
	a[9] = "Re";
	a[10] = "Mi";
	a[11] = "Fa";
	a[12] = "Sol";
	a[13] = "La";
	a[14] = "Si";
	*/

	
	char *nome1 = argv[1];
	char nome2[200] = "";
	trasla(nome1,nome2);

	int check = 0;
	char str[200];
	char *word = "";
	char *pch = "";
	int i = 0;
	
   	FILE *fp;
   	FILE *fout;
   	
   	if ((fp = fopen(nome1,"r") )== NULL)
	   {
    	   printf("Error! opening file");
    	   exit(1);
   		}else{
   			
   			//if((fout = fopen(("./conv/%d", nome1),"w" ))== NULL){s
   			//if((fout = fopen(("./conv/out.txt"),"w" ))== NULL){
   			if((fout = fopen((nome2),"w" ))== NULL){
    	   		printf("Error! opening file");
    	   		exit(1);
   			}else{
   				while (fgets(str,200,fp) != NULL){ 
   					for(i = 0; i<8; i++){
   						word = a[i];
				   		if(strstr(str, word) != NULL) {
				   			check++;
				   			break;	
						}
					}	
					if(check == 0){
						//printf("%s  \n", str );
						fprintf(fout, "%s  \n", str);
					
					}else check = 0;
				}
			}
		}
	fclose(fp);
	fclose(fout);
	return 0;
}

int count(char *stringa){					//conto quanti caratteri è lunga la parola
	int i=0;
	while(stringa[i] != '\0' ){
		i++;
	}
	return i;
	
}

void trasla(char *nome1,char *nome2){				
	int a = count(nome1);
	//printf("a: %d  \n", a);
	
	int i=0;
	
	//printf("nome1: %s",nome1);
	printf("\n");	

	int b=0;
	for(i=0; i != (a+1);i++){
		
		nome2[i] = nome1[b];
		if(i==(a-4)){
			nome2[i]= '2';
			b = b-1;
		}
		b++;
	}
	nome2[a+1] = '\0';
	//printf("nome2: %s\n",nome2);
	
	//return nome2;
}


