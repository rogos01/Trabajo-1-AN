#include <stdio.h>

#include "letrero.h"
#include "Biseccion.h"
#include "Newton.h"


void Letrero();
void Biseccion();

void Newton();

int main(){
    int opc = 0;

    do{
        system("cls");
        Letrero();
        printf("\n\t\t\t\tOpciones\n");
        printf("\n\t\t\t\t[1]Metodo de Biseccion\n");
        printf("\n\t\t\t\t[2]Metodo de falsa posicion\n");
        printf("\n\t\t\t\t[3]Metodo de Newton Raphson\n");
        printf("\n\t\t\t\t[4]Salir\n");
        scanf("%d",&opc);
        switch (opc){
            case 1:
                Biseccion();
                break;
            /*case 2:
                ();
                break;*/
            case 3:
                Newton();
                break;
            default:
                printf("\n\tEleccion no recconocida");
                break;
            }
        system("pause>nul");
    }
    while(opc != 4);
    return 0;
}

