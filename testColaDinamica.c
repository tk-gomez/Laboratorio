#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "menu.h"
#include "MuestrasEntradaCL.h"
//#include "MuestrasAnalizadas.h"
#include "colaDinamica.h"

#define MAX 30


int main() {
    int opcion;
    int num, numAnalizar, i;
    
//crear las variables apuntador a la estructura de datos cola y a la estructura paciente 
	Cola *cola;
	Cola *colaA;
	cola = crearCola(MAX);  //MAXIMO DE 5 ELEMENTOS
	colaA = crearColaMA(MAX);  //MAXIMO DE 5 ELEMENTOS
	Muestras *unaMuestra;
	
	Muestras *unaMuestraMA;
	
	do {
		printf("\n\tLABORATORIO FASTER\n\t===========================");
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
                        printf("\n\t****CONTENEDOR DE MUESTRAS DE ENTRADA****");
                        printf("\nClave de la muestra\t Nombre de la muestra\t\t Departamento");
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
		            printf("\n\t****Muestras en la fila de espera****\n");
		            listar(*cola);
		              
		            unaMuestraMA = unaMuestra;
		            insertarMA(colaA,*unaMuestraMA);
		//            printf("\n****Muestras Analizadas****\n");
		            listarMA(*colaA);
				
	            
	        	}
            else
                printf("\nNo hay muestras por ANALIZAR...\n");
            break;
            
        case 3://Fase de reporte y entrega al departamento solicitante

        	if (!colaVaciaMA(*colaA)){ 	
	           *unaMuestraMA=borrar(colaA);
	           printf("\nLa muestra sera entregada:\n");
		        ListarMuestras(*unaMuestraMA);
		        printf("\n\t****Muestras en la fila de espera****\n");
		        listarMA(*colaA);
		    }
		    else
                printf("\nNo hay muestras por ENTREGAR...\n");
           break;
        }
    } while (opcion != 4);
    //LEBERAR MEMORIA
    return 0;
}
