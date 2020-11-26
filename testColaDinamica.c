#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "menu.h"
#include "MuestrasEntradaCL.h"
#include "colaDinamica.h"

#define MAX 30


int main() {
    int opcion;
    int num;
    
//crear las variables apuntador a la estructura de datos cola y a la estructura paciente 
	Cola *cola;
	cola = crearCola(MAX);  //MAXIMO DE 5 ELEMENTOS
	Muestras *unaMuestra;
	
	do {
        opcion = desplegarMenu("\n1)Fase de recepcion de muestras\n2)Fase de procesado y analisis\n3)Fase de reporte y entrega al departamento solicitante\n\nOpcion: ",4);
        switch (opcion){
        case 1://Fase de recepcion de muestras
                srand(time(NULL));
                num=rand()%100;
                if (num<=50){
         //           if (validarespacio(*cola)){
                        unaMuestra = crearMuestras();
                        CapturarMuestras(unaMuestra);
                        insertar(cola,*unaMuestra);
                        listar(*cola);
          //          }
          //          else
          //              printf("No hay espacio en la COLA\n");
                }
                else
                    printf("\nRequisitos incompletos, por favor regrese nuevamente\n");
                break;
                
        case 2://Fase de procesado y analisis
            if (!colaVacia(*cola)){
              *unaMuestra=borrar(cola);
              printf("\nLa muestra sera atendida:\n");
              ListarMuestras(*unaMuestra);
              printf("\nMuestras en la fila de espera:\n");
              listar(*cola);
            }
            else
                printf("\nNo hay muestras por analizar...\n");
            break;
            
      //  case 3://Fase de reporte y entrega al departamento solicitante
        //   listar(*cola);
         //   break;
        }
    } while (opcion != 4);
    //LEBERAR MEMORIA
    return 0;
}
