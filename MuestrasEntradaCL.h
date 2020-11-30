#ifndef MUESTRASENTRADACL_H_INCLUDED
#define MUESTRASENTRADACL_H_INCLUDED
#define MAX 30

extern char muestraS [6][30];

typedef struct{
   int *clave;
   char *nombre;
   char *departamento;
} Muestras;

Muestras *CrearMuestras(Muestras muestra);


void crearMuestras(Muestras *muestras);
void listarMuestras(Muestras muestras);
void llenarMuestras(Muestras *arrMuestras);


#endif // MUESTRASENTRADACL_H_INCLUDED
