#include <stdio.h>
#include "menu.h"

int desplegarMenu (char texto[], int p) {
   int opcion;
   do {
       printf("%s ",texto);
       scanf("%d", &opcion);
       if (opcion < 1 || opcion > p)
        printf("Error: opcion no valida...\n");
   } while (opcion < 1 || opcion > p);
   return opcion;
}

