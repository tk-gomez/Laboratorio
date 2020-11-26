#include <stdio.h>
#include <stdlib.h> 

#include"MuestrasEntradaCL.h"

#define MAX 30

Muestras *crearMuestras(){
    Muestras *nuevaMuestra = (Muestras *)calloc(1,sizeof(Muestras));
    if(nuevaMuestra==NULL){
	    printf("No se creo la memoria\n");
	    exit (0);
   }
    nuevaMuestra->clave = (int *)malloc(1*sizeof(int));
    nuevaMuestra->nombre = (char *)malloc(MAX*sizeof(char));
    nuevaMuestra->departamento = (char *)malloc(MAX*sizeof(char));
	return nuevaMuestra;
}


void CapturarMuestras(Muestras *muestra){
    printf("\nClave de la muestra: ");
    fflush(stdin);
    scanf("%i",&muestra->clave);
    printf("Nombre de la muestra: ");
    fflush(stdin);
    gets(muestra->nombre);
    printf("Departamento: ");
    fflush(stdin);
    gets(muestra->departamento);
}


void ListarMuestras(Muestras muestra){
    printf("\n%i\t %s\t %s",muestra.clave,muestra.nombre,muestra.departamento);
}


