/*
 * trabajo.c
 *
 *  Created on: 17 may. 2022
 *      Author: Rodrigo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "validaciones.h"
#include "servicio.h"
#include "fecha.h"



int initTrabajos(eTrabajo vec[], int tam)
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

int buscarLibreTrabajo(eTrabajo vec[], int tam, int* pIndex)
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

int altaTrabajo(eTrabajo vec[], eMascota vecDos[], int tam, eServicio servicos[], int tamSec, int* pNextId){

	int todoOK;
	int indice;
	int indiceDos;
	int idMascota;
	int idServicio;
	eTrabajo nuevoTrabajo;
	eFecha fecha;


	    if( vec != NULL && pNextId != NULL && tam > 0)
	    {
	        printf("    *** Alta Trabajo ***\n\n");
	        buscarLibreTrabajo(vec, tam, &indice);

	        if(indice == -1)
	        {
	            printf("No hay lugar en el sistema\n");
	        }
	        else
	        {
	        	nuevoTrabajo.id = *pNextId;

	        	printf("Ingrese ID de mascota: ");
	        	scanf("%d", &idMascota);

	        	buscarMascotasPorId(vecDos, tam, idMascota, &indiceDos);

	        	while(indiceDos == -1)
	        	{
	        		printf("Este ID no existe , Reingrese ID: ");
	        		scanf("%d", &idMascota);
	        		buscarMascotasPorId(vecDos, tam, idMascota, &indiceDos);
	        	}

	        	nuevoTrabajo.idMascota = idMascota;
	        	system("cls");

	        	listarTiposServicios(servicos, tamSec);

	        	printf("Ingrese ID de el servicio: ");
	        	scanf("%d", &idServicio);

	        	while(idServicio < 20000 || idServicio > 20002)
	        	{
		        	printf("ERROR!! Ese ID no existe. ReIngrese el ID del servicio: ");
		        	scanf("%d", &idServicio);
	        	}

	        	nuevoTrabajo.idServicio = idServicio;

	        	printf("Ingrese fecha: ");
	        	scanf("%d/%d/%d",
	        		&fecha.dia,
					&fecha.mes,
					&fecha.anio);

	        	while((fecha.dia < 1 || fecha.dia > 31) || (fecha.mes < 1 || fecha.mes > 12) || (fecha.anio < 1 ))
	        	{
		        	printf("Error fecha invalida!!!, Reingrese fecha: ");
		        	scanf("%d/%d/%d",
		        		&fecha.dia,
						&fecha.mes,
						&fecha.anio);
	        	}

	        	nuevoTrabajo.fechaIngresada = fecha;
	        	system("cls");

	        	nuevoTrabajo.isEmpty = 0;


	            vec[indice] = nuevoTrabajo;

	            (*pNextId)++;

	            todoOK = 1;
	        }
	    }

	return todoOK;
}

int listarTrabajos(eMascota vec[], int tam, eTrabajo trabajos[], eServicio servicios[], int tamSecDos){
    int bandera = 0;
    int flag = 1;
    if( trabajos != NULL && tam > 0)
    {
        system("cls");
        printf("       *** Lista de trabajos ***\n");
        printf("  id          Nombre mascota            Servicio                Fecha           \n");
        printf("______________________________________________________________________________________\n");
        for(int i=0; i < tam; i++)
        {
            if( !trabajos[i].isEmpty)
            {
            	mostrarTrabajos(trabajos[i], vec, servicios, tamSecDos);
                flag = 0;
            }
        }
        printf("_______________________________________________________________________________________\n\n");
        if(flag)
        {
            printf("  No hay trabajos cargadas en el sistema!!!\n\n");
            bandera = 1;
        }


    }
    return bandera;
}

void mostrarTrabajos(eTrabajo trab, eMascota masc[], eServicio servicios[], int tam){

	char tipoServicio[20];
	char nombreMascota[20];

	cargarServicio(servicios, tam, trab.idServicio, tipoServicio);
	cargarNombreMascota(masc, tam, trab.idMascota, nombreMascota);


	printf("%-6d|        %-10s            |   %-15s|    %02d/%02d/%d      \n",
			trab.id,
			nombreMascota,
			tipoServicio,
			trab.fechaIngresada.dia,
			trab.fechaIngresada.mes,
			trab.fechaIngresada.anio);


}

int cargarServicio(eServicio tipos[], int tam, int id, char desc[]){

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

int cargarNombreMascota(eMascota tipos[], int tam, int id, char desc[]){

    int todoOk = 0;
    if(tipos != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( tipos[i].id == id){
                strcpy( desc, tipos[i].nombre);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}















