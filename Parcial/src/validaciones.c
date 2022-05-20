/*
 * validaciones.c
 *
 *  Created on: 17 may. 2022
 *      Author: Rodrigo
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "mascota.h"


int buscarLibre(eMascota vec[], int tam, int* pIndex)
{

    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarCadena(char cadena[50]){

	int i=0;
	int sw=0;
	int j;

	j=strlen(cadena);

	while(i<j && sw==0)
	{
		if(isalpha(cadena[i]) != 0)
		{
			i++;
		}
		else
		{
			sw=1;
		}
	}

	return sw;
}

int mayusculaPrimerCaracter(char cadena[]){
	int todoOK = 0;
	if(cadena !=NULL)
	{
		todoOK = 1;
		strlwr(cadena);
		cadena[0] = toupper(cadena[0]);
	}

	return todoOK;
}

int init(eMascota vec[], int tam)
{
    int todoOk = 0;
    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarMascotasPorId(eMascota vec[], int tam, int id, int* pIndex){

	int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty  && vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
