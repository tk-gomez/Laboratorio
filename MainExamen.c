#include<stdio.h>
#include"menu.h"
#include"ColaM.h"
#include"MuestrasEntradaCL.h"
#define MAX 2000



int main() {
    int opcion;
//crear las variables apuntador a la estructura de datos cola y a la estructura paciente
         Cola *cola;
         cola= CrearCola(MAX);
         Muestras *unaMuestra;
    do {
        opcion = desplegarMenu("\n\n1)Fase de recepcion de muestras\n2)Fase de procesado y analisis\n3)Fase de reporte y entrega al departamento solicitante\nOpcion: ",4);
        switch (opcion){
        case 1://Fase de recepcion de muestras
               if (validarespacio(*cola)){
                unaMuestra = crearMuestras();
                CapturarMuestras(unaMuestra);
                insertar(cola,*unaMuestra);
                listar(*cola);
               }
               else
                printf("No hay espacio en la agenda...\n");
            break;
        /*case 2://Fase de procesado y analisis
            if (!validarVacio(*cola)){
              *unPaciente=borrar(cola);
              printf("El paciente paso con el medico:\n");
              listarPaciente(*unPaciente);
              printf("Pacientes en la fila:\n");
              listar(*cola);
            }
            else
                printf("\nNo hay pacientes por atender...\n");
            break;*/
      //  case 3://Fase de reporte y entrega al departamento solicitante
        //   listar(*cola);
            break;
        }
    } while (opcion != 4);
    //LEBERAR MEMORIA
    return 0;
}
