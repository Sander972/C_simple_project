#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int c = 1;
	char str[30];
	
	while(c > 0){
		
		printf("Inserisci la tua parola: \n");
		gets (str);
		printf("La tua parola inserita e': ");
		stampa(str);
		
		c = controllo(str);
		//printf("stampo controllo %d\n", c);
		
		if (c == 0){
			
			if (allDown(str) > 0){
				printf("Sembra che la tua parola non sia del tutto minuscola, l'ho corretta per te: ");
				stampa(str);	
			}
	
			//stampa(str);
			int a = count(str);
			int pal = palindrom(str);
			if (a % 2){
				pal = pal - 1;
			}
			if (pal == (a/2)){									//se il numero di lettere uguali (a due a due) è uguale alla metà della parola, la parola è palindroma
				printf("La parola e' palindroma!\n");
			}else{
				printf("La parola non e' palindroma!\n");
			}
		}
		
		//c = controllo(str);
	
	}
	
	
	return 0;
}

int palindrom(char *array){					//verifico se la parola è palindroma controllando n e n-1 per ogni lettera, i = lettere uguali
	int c = count(array) -1 ;
	int i = 0;
	printf("%s\n",array);
	while((array[i] == array[c-i])&&(i<(c/2))){
		//printf("%c ",array[i]);
		i++;
	}
	
	return i+1;
		
}

int count(char *stringa){					//conto quanti caratteri è lunga la parola
	int i=0;
	while(stringa[i] != '\0' ){
		i++;
	}
	return i;
}

int stampa(char *array){					//funzione per stampare la parola inserita
	int i;
	int a;
	int c = count(array);
	//printf("lunghezza parola: %d\n",c);
	//printf("[");
	for(i=0;i<c;i++){
		a = array[i];
		printf(" %c ", a);
	}
	//printf("]\n");
	printf("\n");
}

int allDown(char *input){					//converte i caratteri se maiuscolo in minuscoli
	int i;
	int c = count(input);
	int d =0;
	for(i=0;i<c;i++){
		if (input[i]<96){
			input[i] = input[i] + 32;
			d++;
		}	
	}
	return d;
}

int controllo(char *str){				//controlla se la parola è troppo lunga/corta
	int a = count(str);
	int c = 0;
	printf("Lunghezza parola: %d \n", a);
	
	if(a<=2){
		printf("ERROR: Parola troppo corta\n");
		c++;	
	}
	
	if (a>30){
		printf("ERROR: Parola troppo lunga\n");
		c++;	
	}
	return c;
}
