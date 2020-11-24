#ifndef COLAM_H_INCLUDED
#define COLAM_H_INCLUDED
#include"MuestrasEntradaCL.h"
typedef struct{
   int max;
   int h;
   int t;
   Muestras *arrCola;
} Cola;

Cola *CrearCola(int max);
int validarespacio(Cola cola);
int validarVacio(Cola cola);
void listar(Cola cola);
void liberarmemoria(Cola *cola);

void insertar(Cola *cola, Muestras dato) ;




#endif // COLAM_H_INCLUDED
