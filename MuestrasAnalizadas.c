#include <stdio.h>
#include <stdlib.h>
#include "MuestrasAnalizadas.h"

#include "MuestrasEntradaCL.h"

Cola *crearColaMA(int max){
    Cola *nuevaCola;
    //CREACIÓN DINÁMICA DE LA ESTRUCTURA COLA
    nuevaCola=(Cola *)malloc(sizeof(Cola));
    if (nuevaCola==NULL){
        printf("Error: Espacio insuficiente...");
        return NULL;
    }
    //INICIALIZANDO h y t
    nuevaCola->h = NULL;
    nuevaCola->t = NULL;
    return nuevaCola;
}

void insertarMA(Cola *cola,Muestras dato){
    Nodo *nuevoNodo;
    //1.CREA EL NODO
    nuevoNodo=(Nodo *)malloc(1*sizeof (Nodo));
    if (nuevoNodo == NULL){
       printf("Error: memoria insuficiente...");
       return;
    }
    //2.ASIGNA VALORES AL NODO
    nuevoNodo->info = dato;
    nuevoNodo->sig = NULL;
    
    //3.INSERTA EL NODO EN LA COLA
    if(cola->h == NULL){
    	cola->h = nuevoNodo;
    	cola->t = nuevoNodo;
	}
	else {
		cola->t->sig = nuevoNodo;
		cola->t =nuevoNodo;
	}
	  cola->t->sig = cola->h;  //Liga con cola de h
}


int colaVaciaMA(Cola cola){
    return cola.h==NULL;
}

Muestras borrarMA(Cola *cola){
    Muestras dato;
    Nodo *q = cola->h;

    //BORRA EL ELEMENTO DE LA COLA
	if(!colaVacia(*cola)){
		if(cola->h == cola->t)
			cola->h = cola->t = NULL;
		else {
			cola->h = cola->h->sig;
			cola->t->sig = cola->h;   //ACTUALIZA la ligadura de h
		}
    	//EXTRAE LA INFORMACIÓN
		dato = q->info;
    	//LIBERA LA MEMORIA
    	free(q);
	}
    return dato;
}

void listarMA(Cola cola){
    Nodo *q;   //Crea la variable q
    
    if (colaVacia(cola))
        printf("\n\t***No hay muestras en la fila***\n");
    else{
    	q=cola.h;
    	printf("\n\t****MUESTRAS ANALIZADAS****");
    	do{
    	//	printf("%i\t", q->info);
    		ListarMuestras(q->info);
			q=q->sig;
			
		}  while (q!=cola.h);
    }
    printf("\n");
}

void inicializarColaMA(Cola *cola){
    Nodo *q=cola->h;
   //LIBERA MEMORIA
   if(!colaVacia(*cola)){
   		cola->t->sig = NULL;
	   	while(q!=NULL){
	   		cola->h = cola->h->sig;   //actualiza h
	   		free(q);					//libera q
			q= cola->h;					//q avanza a h
		   }
   }
   //INICIALIZA APUNTADORES COLA
    printf("Cola vacia...");
}


