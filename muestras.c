#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "muestras.h"

void crearMuestras(Muestras *muestras){
    muestras->clave =(int *)malloc(1*sizeof(int));
    muestras->nombre =(char *)malloc(MAX*sizeof(char));
    muestras->departamento =(char *)malloc(MAX*sizeof(char));
}

void listarMuestras(Muestras muestras){
    printf("%s\t %s\t %s\t %s\n",muestras.clave,muestras.nombre,
           muestras.departamento);
}

void llenarMuestras(Muestras *arrMuestras){
    FILE *archivo;
    char linea[1024], delimitador[] = ",\n";
    char *token;
    int indice;

    archivo = fopen( ARCHIVO, "rt" );
    if( archivo == NULL ){
        printf( "Error (NO ABIERTO)\n" );
        return ;
    }
    indice = -1;
    printf("\nLEYENDO DATOS DEL ARCHIVO:\n");
    while(fgets(linea,1023, archivo) != NULL){
        token = strtok(linea, delimitador);
        indice++;
        printf("\n----------------\n");
        while (token != NULL){
            crearMuestras(&arrMuestras[indice]);
            strcpy(arrMuestras[indice].clave,token);
            printf("token: %s\n", token);
            token = strtok(NULL, delimitador);
            strcpy(arrMuestras[indice].nombre,token);
            printf("token: %s\n", token);
            token = strtok(NULL, delimitador);
            strcpy(arrMuestras[indice].departamento,token);
            printf("token: %s\n", token);
            token = strtok(NULL, delimitador);
        }
    }
}
