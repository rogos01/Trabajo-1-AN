#ifndef Newton_h
#define Newton_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//funcion del tipo 2x^2-5x+1
void Newton(){
	double n,x,y,dy,v_cr;
printf("\nEl programa resueve funciones del tipo funcion del tipo 2x^2-5x+1 \n");
	
	v_cr=.001;
	x=-4;
	y=2*x*x-5*x+1;
	while(fabs(y)>v_cr){
		y=2*x*x-5*x+1;
		dy= 4*x-5;
		x=x-(y/dy);
	}
	printf("\nLa x final es : %f\n",x);
	printf("\nLa y final es : %f\n",y);
}


#endif