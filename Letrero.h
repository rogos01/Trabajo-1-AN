#ifndef letrero_h
#define letrero_h
#include <stdio.h>
void Letrero(){
    int i;
	printf("\n     ======================================================================\n");
	printf("\t\t\t\t    Analisis Numerico\n");
    printf("\t\t\t\t        Grupo: 06\n");
    printf("\t\t\t\t   Metodo de Biseccion\n");
    printf("\n     ======================================================================\n");
    printf("\t\t     Integrantes:\t\tGomez Soriano, Rodrigo\n");
    printf("\t\t\t\t\t   UNAM \n");
	printf("     ======================================================================\n");

	i = 0;
	putchar('\n');
	for (; i < 80; i++) {
		putchar('_');
	}
}

#endif