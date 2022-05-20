/*
 * servicio.c
 *
 *  Created on: 17 may. 2022
 *      Author: Rodrigo
 */

#include <stdio.h>
#include <stdlib.h>
#include "servicio.h"

int listarTiposServicios(eServicio tipos[], int tam){

    int todoOk = 0;
    if(tipos != NULL && tam > 0 ){

        printf("*****LISTADO DE TIPOS*****\n");
        printf("            TIPOS DE SERVICIOS\n");
        printf("     ID        SERVICIO          PRECIO\n");
        printf("__________________________________________\n");

         for(int i= 0; i < tam; i++){

                printf("     %-4d |     %-15s|     $%-10.2f\n", tipos[i].id, tipos[i].descripcion, tipos[i].precio);

            }
        todoOk = 1;
         }
    return todoOk;
}
