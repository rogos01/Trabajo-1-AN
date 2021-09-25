#ifndef Biseccion_h
#define Biseccion_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Letrero.h"

double f(double);
void Biseccion(){
    int imax, iter;
    double xi,xd,ea,em,test,xa,xaold;

    system("cls");
    Letrero();
    printf("\nMetodo de Biseccion\n");

    printf("\nIntroduce el extremo del intervalo por la izquierda: \n");
    scanf("%lf",&xi);
    printf("\nIntroduce el extremo del intervalo por la derecha: \n");
    scanf("%lf",&xd);
    printf("\nIntroduce el error minimo del calculo: \n");
    scanf("%lf",&em);
    printf("\nLa iteracion maxima es de 50 si no se llega antes al error minimo: \n");

    iter=0;
    xa=0;
    if(f(xi)*f(xd)>0){
        printf("No se encontro ninguna raiz dentro del intervalo");
    }
    else{
        printf("\nIteraciones       raiz        error aprox");
        printf("\n--------------------------------------------");
        do{
            //system("cls");
            iter++;
            xaold=xa;
            xa=(xi+xd)/2;
            ea=fabs((xa-xaold)/xa)*100;
            test=f(xi)*f(xa);
            /*if(test<0){
                xd=xa;
            }
            else if(test>0){
                xi=xa;
            }
            else{
                ea=0;
            }*/
            printf("\n    %d-\t\t%lf       %lf\n", iter, xa,ea);
            system("pause>nul");
        }
        while(ea>em && iter<50);
    }
    //return true;
}
double f(double x){
    return x*x-2;
}

#endif