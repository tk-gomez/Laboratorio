#include<stdio.h>
#include"MuestrasEntradaCL.h"
#include"ColaM.h"
#define MAX 30

char nombresMuestra[6][30]={"Orina","Sudor","Sangre","Semen","Colesterol","Acido Urico"};
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

}


void CapturarMuestras(Muestras *muestra){
    srand(time(NULL));
    printf("\nClave de la muestra: ");
    fflush(stdin);
    scanf("%i",&muestra->clave);
    strcpy(muestra->nombre,nombresMuestra[rand()%5]);
    fflush(stdin);
    printf("Departamento: ");
    fflush(stdin);
    gets(muestra->departamento);
}
void ListarMuestras(Muestras muestra){
    printf("\n%i\t %s\t %s",muestra.clave,muestra.nombre,muestra.departamento);

}
