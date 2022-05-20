/*
 * color.c
 *
 *  Created on: 17 may. 2022
 *      Author: Rodrigo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"





int listarTiposColor(eColor tipos[], int tam){

    int todoOk = 0;
    if(tipos != NULL && tam > 0 ){

        printf("*****LISTADO DE TIPOS*****\n");
        printf("   		TIPOS DE COLORES\n");
        printf("     ID      COLORES\n");
        printf("_______________________________\n");

         for(int i= 0; i < tam; i++){

                printf("     %4d     %-10s\n", tipos[i].id, tipos[i].nombreColor);

            }
        todoOk = 1;
         }
    return todoOk;
}


int cargarDescripcionColor(eColor color[], int tam, int id, char desc[]){

    int todoOk = 0;
    if(color != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( color[i].id == id){
                strcpy( desc, color[i].nombreColor);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}
