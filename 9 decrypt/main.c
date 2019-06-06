#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char in;
	char out;
	
   	FILE *fp;

   	if ((fp = fopen("buffer.dat","r")) == NULL)
	   {
    	   printf("Error! opening file");
    	   exit(1);
   		}else{
   			
   			/*while (!feof (fp)){
		
			fscanf(fp,"%d", &num);
			num = num+5;
   			printf(" %d ", num);
			}*/
			fclose(fp);
			int i = 1;
			for(i;i<20;i++){
				fp = fopen("buffer.dat","r");
				printf("Key N: %d \n",i);
				
				while(fscanf(fp, "%c", &in)!=EOF){
				
					out=in-i;
				
					if (in == '\n'){
						out = 32;
					}
					if (out < 32){
						out = out+94;
					}
					printf("%c ", out);
				}
				fclose(fp);
				
			printf("\n\n ");	
			//i++;	
			}
				
		}
	
	
	return 0;
}
