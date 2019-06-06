#include <stdio.h>
#include <stdlib.h>
#define D 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char s[D] = "minuscolo";
	
	stampaArray(s);
	upperAll(s);
	stampaArray(s);
	
	
	return 0;
}

void upperAll(char *input){
	int i;
	for(i=0;i<20;i++){
		input[i] = input[i] - 32;	
	}
}

int stampaArray(char *array){
	int i;
	int a;
	printf("[");
	for(i=0;i<D;i++){
		a = array[i];
		printf(" %c ", a);
	}
	printf("]\n");
}

