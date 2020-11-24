#include<stdio.h>
#include<stdlib.h>
#include"ColaM.h"
#include"MuestrasEntradaCL.h"

Cola *CrearCola(int max){
    Cola *nuevaCola;
    nuevaCola = (Cola *)malloc(1*sizeof(Cola));
    nuevaCola->arrCola = (Muestras *)calloc(max,sizeof(Muestras));

    nuevaCola->max = max;
    nuevaCola->h = nuevaCola->t = -1;
    return nuevaCola;
}
int validarespacio(Cola cola){
    return cola.t < cola.max-1;
}
void insertar(Cola *cola, Muestras dato) {
    if (cola->h ==-1)
        cola->h= 0;//INICIO DE LA FILA
    cola->t++;
    //INSERTA EL DATO EN LA FILA
    cola->arrCola[cola->t]=dato;//una estructura se copia a otra estructura a traves del igual
}

void listar(Cola cola){
   int i;
   printf("\n\tMUESTRAS:");
   if (!validarVacio(cola)){
       for (i=cola.h; i<=cola.t ; i++){
           ListarMuestras(cola.arrCola[i]);
       }
   }
   else
        printf("  No hay datos...\n");
}

int validarVacio(Cola cola){
   return cola.h == -1;
}

void liberarmemoria(Cola *cola){
    free(cola->arrCola);
    free(cola);
    cola = NULL;
}
