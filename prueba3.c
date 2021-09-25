#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Letrero.h"


int main(){
    int imax, iter;
    double x0,fx0,dfx0,ea,em,xa,xaold,test;
    printf("\nIntroduce el valor inicial: \n");
    scanf("%lf",&x0);
    printf("\nIntroduce el error minimo del calculo: \n");
    scanf("%lf",&em);
    printf("\nLa iteracion maxima es de 50 si no se llega antes al error minimo: \n");

    iter=0;
    xa=0;
    
    printf("\nIteraciones       raiz        error aprox");
    printf("\n--------------------------------------------");    
    do{
        iter++;
        xaold=xa;
        //fx0=(x0*x0*x0)-(2*x0)-5;
        //dfx0= 3*x0*x0-2;
        xa=x0-(((x0*x0*x0)-(2*x0)-5)/(dfx0= 3*x0*x0-2));
        ea=fabs((xa-xaold)/xa)*100;
        test=xa-x0;
        if(fabs(test)<=0){
            printf("\nLa raiz es: %f\n",xa);
        }
        else if (fabs(test)>0){
            ea=0;
        }

        printf("\n    %d-\t\t%lf       %lf\n", iter, xa,ea);
        system("pause>nul");
    }
    while(ea>em && iter<50);
}
