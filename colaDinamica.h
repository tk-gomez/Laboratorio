#ifndef COLADINAMICA_H_INCLUDED
#define COLADINAMICA_H_INCLUDED
#include "MuestrasEntradaCL.h"

typedef struct nodo{
    Muestras info;
    struct nodo *sig; //APUNTADOR AL SIG NODO DE LA cola
}Nodo;

typedef struct {
  Nodo *h, *t;
}Cola;

//FUNCIONES
void insertar(Cola *cola,Muestras dato);
Muestras borrar(Cola *cola);
//FUNCIONES AUXILIARES
Cola *crearCola();
int colaVacia(Cola cola);
void inicializarCola(Cola *cola);
void listar(Cola cola);

#endif // COLADINAMICA_H_INCLUDED
