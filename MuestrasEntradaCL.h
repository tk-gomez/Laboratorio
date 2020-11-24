#ifndef MUESTRASENTRADACL_H_INCLUDED
#define MUESTRASENTRADACL_H_INCLUDED
#define MAX 30

extern char nombre[6][30];
typedef struct{
   int *clave;
   char *nombre;
   char *departamento;
} Muestras;

Muestras *CrearMuestras(Muestras muestra);
void CapturarMuestras(Muestras *muestra);
void ListarMuestras(Muestras muestra);

#endif // MUESTRASENTRADACL_H_INCLUDED
