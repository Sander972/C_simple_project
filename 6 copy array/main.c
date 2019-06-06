#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char armadio[10]={0,1,2,3,4,5,6,7,8,9};
	char q[10];
	
	printf("stampo l'array 'armadio'\n");
	stampaArray(armadio);
	arrayCopy(armadio,q);
	printf("stampo l'array 'q'\n");
	stampaArray(q);
	
	return 0;
}

void arrayCopy(char *partenza, char *arrivo){
	int i;
	for(i=0;i<10;i++){
		arrivo[i] = partenza[i];
	}
}

int stampaArray(char *array){
	int i;
	int a;
	printf("[");
	for(i=0;i<10;i++){
		a = array[i];
		printf(" %d ", a);
	}
	printf("]\n");
}
