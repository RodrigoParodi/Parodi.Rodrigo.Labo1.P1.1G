/*
 * tipo.c
 *
 *  Created on: 17 may. 2022
 *      Author: Rodrigo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"





int listarTiposMascotas(eTipo tipos[], int tam){

    int todoOk = 0;
    if(tipos != NULL && tam > 0 ){

        printf("*****LISTADO DE TIPOS*****\n");
        printf("   	     TIPOS DE MASCOTAS\n");
        printf("     ID       MASCOTAS\n");
        printf("_______________________________\n");

         for(int i= 0; i < tam; i++){

                printf("     %4d     %-10s\n", tipos[i].id, tipos[i].descripcion);

            }
        todoOk = 1;
         }
    return todoOk;
}

int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char desc[]){

    int todoOk = 0;
    if(tipos != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( tipos[i].id == id){
                strcpy( desc, tipos[i].descripcion);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}
