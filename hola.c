#include <stdio.h>
#include <math.h>

int main(){
	double n,x,y,dy,v_cr;
	printf("El programa resueve funciones del tipo funcion del tipo 2x^2-5x+1 ");
	
	v_cr=.001;
	x=-4;
	y=2*x*x-5*x+1;
	while(fabs(y)>v_cr){
		y=2*x*x-5*x+1;
		dy= 4*x-5;
		x=x-(y/dy);
	}
	printf("La x final es : %f\n",x);
	printf("La y final es : %f",y);
	return 0;
}