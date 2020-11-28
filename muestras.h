#define MAX 30
#define N 6
#define ARCHIVO "Muestras.csv"

typedef struct{
   int *clave;
   char *nombre;
   char *departamento;
}Muestras;

void crearMuestras(Muestras *muestras);
void listarMuestras(Muestras muestras);
void llenarMuestras(Muestras *arrMuestras);
