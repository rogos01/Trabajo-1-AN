#ifndef mFalsa_h
#define mFalsa_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mFalsa(int*,double*,double,short); //Prototipo de la funcion.

void mFalsa(int *exponentes, double *coeficientes , double terminoIndep, short nuevoTam){
	double xl, xu, xr, errorAprox, producto;
	double fxl, fxu, fxr, xAnterior, xNuevo;
	int nIteraciones, i = 0, j = 0;

	printf("\n\nIngresa el l%cmite inferior (Xl): ",161);
	scanf("%lf",&xl);
	
	do{ //Bucle para que usuario ingrese un valor mayor al límite inferior.
		setbuf(stdin, NULL); //Limpiar el buffer.
		
		printf("\nIngresa el l%cmite superior (Xu): ",161);
		scanf("%lf",&xu);
		
		if(xu <= xl)//Condicional para verificar si el límite inferior es mayor que el límite superior.
			printf("",getchar(),getchar(), printf("Debes de ingresar un valor mayor a %lf.",xl));

	}
    while(xu <= xl);
	
    do{ //Bucle para pedir la cantidad de iteraciones.
		printf("\n\nIngresa la cantidad de iteraciones: ");
		scanf("%d",&nIteraciones);
	
	}
    while(nIteraciones < 1);	
			
	printf("\nTu expresi%cn algebraica es: \n\n\t\t\t%c(x) = ",162, 159);
	for(j=0; j<nuevoTam; j++)//Ciclo para mostrar la expresión que usuario ingresó.
		if(*(exponentes + j))
			*(coeficientes+j)!=1 ? printf("%+gx^%d ",*(coeficientes+j), *(exponentes + j)) : printf("x^%d ",*(exponentes + j));
			
	if(terminoIndep != 0)
		printf("%+g\n",terminoIndep);
		
	else printf("\n");
	
	for(j=0; j<21; j++)
		printf("%c%c%c%c",(!j ? '\t': 95), 95, 95, 95);
		
	printf("\n\tIteraci%cn\tXl\t\tXu\t\tXr\t\tError Aproximado(%%)\n",162);
	
	for(j=0; j<21; j++)
		printf("%c%c%c%c",(!j ? '\t': 196), 196, 196, 196);
	
	while(nIteraciones > i){
		fxl = 0, fxu = 0;

		printf("\n\n\t%d \t\t%lf \t%lf \t%lf",i, xl, xu, xr);//Muestra los datos.
				
		for(j=0; j<nuevoTam; j++) //Evalúa la función con el límite Xl.
			fxl += *(coeficientes+j) * pow(xl,*(exponentes+j));
			
		fxl += terminoIndep; //Le suma el término independiente.
	
		for(j=0; j<nuevoTam; j++) //Evalúa la función con el límite Xu.
			fxu += *(coeficientes+j) * pow(xu,*(exponentes+j));
						
		fxu += terminoIndep; //Le suma el término independiente.
		
		producto = fxu * fxl; //Hace el producto para verificar que exista al menos una raíz.
		
		if(producto > 0) //Si el producto es positivo, entonces no hay raices.
			break;
			
		if(fxl - fxu) //verifica que la diferencia entre fxl y fxu no sea 0.
			xr = xu - ( ((fxu)*(xl - xu)) / (fxl - fxu) ); //Fórmula del método de falsa posición.
		
		else break;
		
		for(j=0; j<nuevoTam; j++) //Evalúa la función con el valor de Xl.
			fxr += *(coeficientes+j) * pow(xr,*(exponentes+j));
			
		fxr += terminoIndep; //Le suma el término independiente.		
		
		producto = fxr * fxu; //realiza el producto de las evaluaciones.
		
		producto < 0 ? (xl = xr) : (xu = xr); //Asigna el nuevo límite.	
	
		xAnterior = xNuevo; //Asignará el valor anterior de xNuevo después de la segunda iteración.
		xNuevo = xr; //Asignar el nuevo valor de xR a xNuevo.
		
		if(i && xNuevo) //A partir de la segunda iteración, se obtendrá el error apróximado.
			errorAprox = ((xNuevo-xAnterior) / xNuevo) * 100;
			
		if(i++) //Muestra el error apróximado a partir de la segunda iteración.
			printf("\t%lf",errorAprox < 0 ? errorAprox*-1 : errorAprox);
	}
	
	getchar(); //Pausar.
	getchar();	
}

#endif