#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void alphabet(int k);
FILE *archivo;

void alphabet(int k){
	
	 int i,j,cont1,cont2;
	 double aux;
	 char cadena[1];
	 
	 cadena[0]=0;
	 cadena[1]='1';
	 
	archivo = fopen("archivo.txt","w+");
	if(archivo != NULL){
		printf("\nEl valor de k es: %d\n",k);
	 	printf("E^%d{", k);
	 	fprintf(archivo, "\nEl valor de k es: %d\n",k);
	 	fprintf(archivo, "E^%d{", k);
	 	
		if(k==0)
			printf("e");
			
		else{
			for(cont1=0;cont1<pow(2,k);cont1++){//Hace el numero total de entradas en el alfabeto
				 aux=(pow(2,k)/2);
				 for(i=0;i<k;i++){//Hace el numero de entradas por entrada
					 int cont3=0;
					 for(j=cont1,cont2=cont1;j<pow(2,k);j++){//Imprime
						 while(cont2>=(aux)){//Permutaciones
						 	cont3++; 
							cont2-=aux;
							if(cont3==2) {
								cont3=0;
							}
						 }
						 if(cont1==j){ 
						 	fprintf (archivo, "%i", cadena[cont3]);
						 	printf ("%i", cadena[cont3]);
							break;
						 }
					 }
					 aux/=2;
			 	 }
				 if(cont1!=pow(2,k)-1)
				 {
				 	fprintf (archivo, ",");
				 	printf (",");
		 		 }
		 	 }
		 }

	fprintf(archivo,"}\n\n"); 
	printf("}\n\n"); 
	fclose(archivo);
	}
}

int main() {
	int op;	
	do{
		int k;
		printf("1.- Introducir potencia:\n");
		printf("2.- Numero Aleatorio 1-1000:\n");
		printf("3.- Asterisco:\n");
		printf("4.- Salir:\n");
		scanf("%i",&op);
		switch(op){
			case 1:
				printf("Introduce la potencia:\n");
				scanf("%i",&k);
				fflush(stdin);	
				alphabet(k);
				fflush(stdin);
			break;
				
			case 2:
				k=rand()%1000;
				alphabet(k);
				fflush(stdin);
			break;
			
			case 3:
				for(int i=0;true;i++)
					alphabet(i);
				fflush(stdin);
			break;
				
	    }
	}while(op<4);
return 0;
}	
