#ifndef COLADINAMICA_H_INCLUDED
#define COLADINAMICA_H_INCLUDED
#include "MuestrasEntradaCL.h"
//#include "colaDinamica.h"

typedef struct nodo{
    Muestras info;
    struct nodo *sig; //APUNTADOR AL SIG NODO DE LA cola
}Nodo;

typedef struct {
  Nodo *h, *t;
} Cola;

//FUNCIONES
void insertarMA(Cola *cola,Muestras dato);
Muestras borrarMA(Cola *cola);
//FUNCIONES AUXILIARES
Cola *crearColaMA();
int colaVaciaMA(Cola cola);
void inicializarColaMA(Cola *cola);
void listarMA(Cola cola);

#endif // COLADINAMICA_H_INCLUDED
