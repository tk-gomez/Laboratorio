#include <stdio.h>
#include <stdlib.h>
#include "colaDinamica.h"
#include "MuestrasEntradaCL.h"

Cola *crearCola(int max){
    Cola *nuevaCola;
    //CREACIÓN DINÁMICA DE LA ESTRUCTURA COLA
    nuevaCola=(Cola *)malloc(sizeof(Cola));

    if (nuevaCola==NULL){
        printf("Error: Espacio insuficiente...");
        return NULL;
    }
    //INICIALIZANDO h y t de la estructura cola
    nuevaCola->h = NULL;
    nuevaCola->t = NULL;
    return nuevaCola;
}


void insertar(Cola *cola,Muestras dato){
    Nodo *nuevoNodo;
    
    //CREA EL NODO
    nuevoNodo=(Nodo *)malloc(1*sizeof (Nodo));
    if (nuevoNodo == NULL){
       printf("Error: memoria insuficiente...");
       return;
    }
    //ASIGNA VALORES AL NODO
    nuevoNodo->info = dato;
    nuevoNodo->sig = NULL;

    //INSERTA EL NODO EN LA COLA
    if(cola->h == NULL){ 	//Si la variable h es igual a NULL significa que es el primer dato en la cola
    	cola->h = nuevoNodo;
    	cola->t = nuevoNodo;
	}
	else {
		cola->t->sig = nuevoNodo;
		cola->t = nuevoNodo;
	}
}


int colaVacia(Cola cola){
    return cola.h==NULL;
}




Muestras borrar(Cola *cola){
    Muestras dato;
    Nodo *q = cola->h;

    //BORRA EL ELEMENTO DE LA COLA
	if(!colaVacia(*cola)){
		if(cola->h == cola->t)
			cola->h = cola->t = NULL;
		else 
			cola->h = cola->h->sig;
		//	cola->t->sig = cola->h;   //ACTUALIZA la ligadura de h
	    //EXTRAE LA INFORMACIÓN
	    dato = q->info;
	    //LIBERA LA MEMORIA
	    free(q);
	}   
    return dato;   
}


void listar(Cola cola){
    Nodo *q;   //Crea la variable q. No se debe de reservar memoria con malloc porque solo quiere una copia directa a la variable cola en su campo h
    
    if (colaVacia(cola))
        printf("\nNo hay muestras en la fila...\n");
    else{
    	q=cola.h;
    //	printf("COLA:");
		while (q!=NULL){
			ListarMuestras(q->info);
			q= q->sig;
		}
    }
    printf("\n");
}


void inicializarCola(Cola *cola){
    Nodo *q=cola->h;
   //LIBERA MEMORIA
   while (q!=NULL){

   }
   //INICIALIZA APUNTADORES COLA


    printf("Cola vacía...");
}
