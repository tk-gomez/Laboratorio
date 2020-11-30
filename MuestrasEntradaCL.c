#include <stdio.h>
#include <stdlib.h> 

#include"MuestrasEntradaCL.h"

#define MAX 30

char muestraS[6][30]={"Sangre","Orina","Colesterol","Acido Urico","Semen","Saliva"};

Muestras *CrearMuestra(){
    Muestras *nuevaMuestra;
    nuevaMuestra = (Muestras *)malloc(1*sizeof(Muestras));
    if(nuevaMuestra==NULL){
    printf("No se creo la memoria\n");
    exit (0);
   }
    nuevaMuestra->clave = (int *)malloc(1*sizeof(int));
    nuevaMuestra->nombre = (char *)malloc(MAX*sizeof(char));
    nuevaMuestra->departamento = (char *)malloc(MAX*sizeof(char));

}


void CapturarMuestras(Muestras *muestra){
    printf("\nClave de la muestra: ");
    fflush(stdin);
    scanf("%i",&muestra->clave);
    strcpy(muestra->nombre,muestraS[rand()%5]);
    fflush(stdin);
    printf("Departamento: ");
    fflush(stdin);
    gets(muestra->departamento);
}
void listarMuestras(Muestras muestra){
    printf("\n%i\t %s\t %s",muestra.clave,muestra.nombre,muestra.departamento);

}

