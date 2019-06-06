#include <stdio.h>
#include <stdlib.h>

	
int main(int argc, char *argv[]) {
	
	printf("inserisci dei numeri\n");
	
	int i = 1;
	int t = 0;
	int c = 0;
	//char array[10];				//dimensione di partenza
	int *array;				
	int term=0;
	char *num;
	while(i>t){
		
		printf("N. %d ",i);
		scanf("%s" ,&num);
		
		term = terminator(&num);
		if(term>0){
			t = i+1;
			stampa(array);
			//free(array);
			printf("no maria io esco");	
		}else{
			c = convert(&num);
			//printf("\n%d\n",c);
		
			array = (int *) realloc(array, sizeof(int)*i);
			*(array+i) = c;
			//array[i] = c;
			i++;
		}
		

	}
	
	
	
	
	
	
	return 0;
}


int terminator(char *num){
	char *x = "exit";
	int c = count(num);
	int i=0;
	while(i<c){
		if(num[i] == x[i]){
			i++;
		}else{
			c = -1;
		}
	}
	return i;
		
}

int count(char *stringa){					
	int i=0;
	while(stringa[i] != '\0' ){
		i++;
	}
	return i;
}

int stampa(char *array){				
	int i;
	int a;
	int c = count(array);
	printf("lunghezza array: %d\n",c);
	for(i=0;i<c;i++){
		a = *(array+i);
		printf(" %d ", a);
	}
	printf("\n");
}

int convert(char *num){
	int c = count(num)-1;
	//printf("c:%d",c);
	int r = 0;
	int i = 0;
	while(i<=c){
		r = (r+ (num[i]-'0')*pow(10,(c-i)));
		i++;
	}
	return r;
}
