#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include"MuestrasEntradaCL.h"

char muestraS[6][30]={"Sangre","Orina","Colesterol","Acido Urico","Semen","Saliva"};
char depar[6][30]={"UNAM","IPN","UVM","BCC","PBO","UACM"};
#define MAX 30

Muestras *crearMuestras(){
    Muestras *nuevaMuestra;
    nuevaMuestra = (Muestras *)malloc(1*sizeof(Muestras));
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
    fflush(stdin);    
    strcpy(muestra->nombre,muestraS[rand()%5]);
    fflush(stdin);    
    strcpy(muestra->departamento,depar[rand()%5]);
    fflush(stdin);  
    /*printf("Departamento: ");
    fflush(stdin);
    gets(muestra->departamento);*/
}

void ListarMuestras(Muestras muestra){
	//printf("\nClave de la muestra\t Nombre de la muestra\t Departamento");
    printf("\n\t %i\t\t\t %s\t\t\t %s",muestra.clave,muestra.nombre,muestra.departamento);
}



