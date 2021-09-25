/*#ifndef Falsa_c
#define Falsa_c*/
#include "mFalsa.h"

void mFalsa(int*,double*,double,short); //Prototipo de la funcion.

void main(void){	
	short grado, i, j, nuevoTam = 0;
	char coeficienteAscii = 'a';
	int *exponentes;
	double *coeficientes, terminoIndep;
	
	do{ //Bucle para que usuario ingrese el grado del polinomio.
		setbuf(stdin,NULL); 
		
		printf("\n\nIngresa el grado del polinomio: ");
		scanf("%hd",&grado);
		
	}
    while(grado < 1 || grado > 12); //El grado debe de ser mayor a 0 y menor a 12.
	
	printf("\nEstructura de la expresi%cn algebraica\n\n        ",162);
	for(i=0; i<grado-1; i++) //Muestra el grado de la variable X.
		printf(" %2d  ",grado-i);
		
	printf("\n %c(x) = ",159);
	for(i=0; i<grado; i++) //Ciclo para mostrar el coeficiente y la variable X.
		printf("%cx + ",coeficienteAscii++);
		
	printf("%c\n",coeficienteAscii++);	//Muestra el término independiente.
	
	coeficientes = (double*) malloc(grado * sizeof(double)); //Reservar espacio en la memoria.

	if(!coeficientes){ //Condicional en caso de que no haya suficiente espacio.
		printf("",getchar(),getchar(),printf("\n\nNo se ha podido reservar suficiente memoria."));
		exit(-1);
	}

	exponentes = (int*) malloc(grado*sizeof(int));
	
	if(!exponentes){ //Condicional en caso de que no haya suficiente espacio.
		printf("",getchar(),getchar(),printf("\n\nNo se ha podido reservar suficiente memoria."));
		exit(-1);
	}
			
	for(i=0; i<grado; i++)//Bucle para pedirle al usuario los coeficientes de las variables.
		printf("",scanf("%lf",(coeficientes+i)), printf("\nIngresa el coeficiente de la variable de grado %d: ",grado-i));
	
	printf("\n\nAhora ingresa el t%crmino independiente: ",130);
	scanf("%lf",&terminoIndep);
	
	for(j=0,i=0; i<grado; i++) //Bucle guardar las posiciones donde el coeficiente no sea 0.
		if(*(coeficientes + i)){ //Verifica que el coeficiente en esa posición no sea 0.
			*(exponentes + (j)) = grado - i; //Se guarda el grado en la posición j.
			*(coeficientes + (j++)) = *(coeficientes + i); //Se guarda el coeficiente en la posición j.
			nuevoTam++; //Variable para el nuevo tamaño del arreglo.
		}
			
	coeficientes = (double*) realloc(coeficientes, (sizeof(double)*nuevoTam));//Nuevo tamaño
	
	if(!coeficientes){
		printf("",getchar(),getchar(),printf("\n\nNo se ha podido reservar suficiente memoria."));
		exit(-1);
	}
			
	mFalsa(exponentes, coeficientes, terminoIndep, nuevoTam); //Función que calcula la raíz.
	
	free(coeficientes); //Liberar la memoria dinámica.
	free(exponentes);
	
	//return 0;
}


//#endif