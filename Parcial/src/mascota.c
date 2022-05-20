/*
 * mascota.c
 *
 *  Created on: 17 may. 2022
 *      Author: Rodrigo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"
#include "mascota.h"
#include "tipo.h"
#include "menu.h"
#include "validaciones.h"


int altaMascota(eMascota vec[], int tam, eTipo tipos[], eColor colores[], int tamSec, int* pNextId)
{
	int todoOk = 0;
	int indice;
	int sw;
	int idMascota;
	int idColor;
	int cant;
	char auxCad[100];
	char RespVacunado;
	eMascota nuevaMascota;




	    if( vec != NULL && pNextId != NULL && tam > 0)
	    {
	        system("cls");
	        printf("    *** Alta Mascota ***\n\n");
	        buscarLibre(vec, tam, &indice);

	        if(indice == -1)
	        {
	            printf("No hay lugar en el sistema\n");
	        }
	        else
	        {
	        	nuevaMascota.id = *pNextId;


	        	printf("Ingrese Nombre: ");
	        	fflush(stdin);
	        	gets(auxCad);
	        	sw = validarCadena(auxCad);

	        	while(strlen(auxCad) >= 20 || sw==1)
	        	{
	        		printf("Nombre  Invalido!!!!. Reingrese nombre: ");
	        		fflush(stdin);
	        		gets(auxCad);
	        		sw = validarCadena(auxCad);
	        	}

	        	mayusculaPrimerCaracter(auxCad);
	        	strcpy(nuevaMascota.nombre, auxCad);
	        	system("cls");

	        	listarTiposMascotas(tipos, tamSec);

	        	printf("Ingrese ID de tipo de mascota: ");
	        	scanf("%d", &idMascota);

	        	while(idMascota < 1000 || idMascota > 1004)
	        	{
		        	printf("Ese ID no existe!!, ingrese otro ID de Tipo de mascota: ");
		        	scanf("%d", &idMascota);
	        	}

	        	nuevaMascota.idTipo = idMascota;
	        	system("cls");

	        	listarTiposColor(colores, tamSec);

	        	printf("Ingrese ID de Color: ");
	        	scanf("%d", &idColor);

	        	while(idColor < 5000 || idColor > 5004)
	        	{
		        	printf("Ese ID no existe!!, ingrese ID de color: ");
		        	scanf("%d", &idColor);
	        	}

	        	nuevaMascota.idColor = idColor;

	        	system("cls");

	        	printf("Ingrese edad de la mascota: ");
	        	cant = scanf("%d", &nuevaMascota.edad);

	        	while(nuevaMascota.edad < 0 || cant == 0)
	        	{
		        	printf("Edad invalida !!. Reingrese edad: ");
		        	fflush(stdin);
		        	cant = scanf("%d", &nuevaMascota.edad);
	        	}

	        	system("cls");

	        	printf("Vacunado ?(s o n): ");
	        	fflush(stdin);
	        	scanf("%c", &RespVacunado);
	        	RespVacunado = tolower(RespVacunado);

	        	while(RespVacunado !='s' && RespVacunado !='n')
	        	{
		        	printf("Error !!. Reingrese respuesta: ");
		        	fflush(stdin);
		        	scanf("%c", &RespVacunado);
		        	RespVacunado = tolower(RespVacunado);
	        	}

	        	nuevaMascota.vacunado= RespVacunado;

	        	system("cls");

	        	nuevaMascota.isEmpty = 0;


	            vec[indice] = nuevaMascota;

	            (*pNextId)++;

	            todoOk = 1;
	        }
	    }
	    return todoOk;
	}

int listarMascotas(eMascota vec[], int tam, eTipo tipos[], eColor colores[], int tamSec){
    int bandera = 0;
    int flag = 1;
    if( vec != NULL && tam > 0)
    {
        system("cls");
        printf("       *** Lista de mascotas ***\n");
        printf("  id          Nombre         Edad           Tipo             Color              Vacunado ?\n");
        printf("___________________________________________________________________________________________\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty)
            {
            	mostrarMascotas(vec[i], tipos, colores, tamSec);
                flag = 0;
            }
        }
        printf("____________________________________________________________________________________________\n\n");
        if(flag)
        {
            printf("  No hay mascotas cargadas en el sistema!!!\n\n");
            bandera = 1;
        }


    }
    return bandera;
}

void mostrarMascotas(eMascota Masc, eTipo tipos[], eColor colores[], int tam){

	char tipo[20];
	char color[20];

	cargarDescripcionTipo(tipos, tam, Masc.idTipo, tipo);
	cargarDescripcionColor(colores, tam, Masc.idColor, color);

	printf("| %-6d|    %-10s|     %-10d|     %-10s|     %-15s|     %-10c|           \n",
			Masc.id,
			Masc.nombre,
			Masc.edad,
			tipo,
			color,
			Masc.vacunado);

}

void mostrarMascota(eMascota Masc, eTipo tipos[], eColor colores[], int tam){

	char tiposMascotas[20];
	char tiposColores[20];

	cargarDescripcionTipo(tipos, tam, Masc.idTipo, tiposMascotas);
	cargarDescripcionColor(colores, tam, Masc.idColor, tiposColores);

    printf("ID: %d\n", Masc.id);
    printf("Nombre Mascota : %s\n", Masc.nombre);
    printf("Edad: %d\n", Masc.edad);
    printf("Tipo de mascota: %s\n", tiposMascotas);
    printf("Color: %s\n", tiposColores);
    printf("Vacunado ?: %c\n\n", Masc.vacunado);
}

int borrarMascota(eMascota vec[], int tam, eTipo tipos[], eColor colores[], int tamSec){

	   	int todoOk = 0;
	    int indice;
	    int id;
	    char confirma;
	    if( vec != NULL && tam > 0 )
	    {
	    	if(listarMascotas(vec, tam, tipos, colores, tamSec) == 0)
	    	{

	    		printf("Ingrese id: ");
	    		scanf("%d", &id);

	    		if( buscarMascotasPorId(vec, tam, id, &indice))
	    			{
	    			       if(indice == -1)
	    			         {
	    			             printf("No existe una mascota con id: %d en el sistema\n", id);
	    			         }
	    			         else
	    			           {
	    			        	 system("cls");
	    			        	 mostrarMascota(vec[indice], tipos, colores, tam);
	    			             printf("Confirma baja?: ");
	    			             fflush(stdin);
	    			             scanf("%c", &confirma);

	    			              if(confirma == 's' || confirma == 'S')
	    			               {
	    			                   vec[indice].isEmpty = 1;
	    			                   printf("Baja exitosa!!!\n");
	    			               }
	    			               else
	    			               {
	    			                   printf("Baja cancelada por el usuario\n");
	    			               }

	    			            }

	    			   todoOk = 1;
	    			 }

	    	}

	    }
	    return todoOk;
}

int modificarMascota(eMascota vec[], int tam, eTipo tipos[], eColor colores[], int tamSec){

    int todoOk = 0;
    char RespVacunado;
    int indice;
    int id;
    int idColor;
    int idMascotas;
    int edad;
    int cant;
    char auxCad[100];
    char respuesta = 's';


    if( vec != NULL && tam > 0 )
    {

    	if(listarMascotas(vec, tam, tipos, colores, tamSec) == 0)
    	{
    		        printf("Ingrese id: ");
    		        scanf("%d", &id);


    		        if( buscarMascotasPorId(vec, tam, id, &indice))
    		        {

    		            if(indice == -1)
    		            {
    		                printf("No existe una mascota con id: %d en el sistema\n", id);
    		            }
    		            else
    		            {
    		            	system("cls");
    		            	mostrarMascota(vec[indice], tipos, colores, tam);
    		            	printf("Estos son los datos que desea modificar ?: ");
    		            	fflush(stdin);
    		            	scanf("%c", &respuesta);

    		            	if(respuesta == 's' || respuesta == 'S')
    		            	{
    	   		            	do{

    	    		                    switch(menuModificarMascota())
    	    		                    {

    	    		                    case 1:
    	    		                        printf("Ingrese nuevo nombre: ");
    	    		                        fflush(stdin);
    	    		                        gets(auxCad);

    	    		        	        	while(strlen(auxCad) >= 20)
    	    		        	        	{
    	    		        	        		printf("Nombre demasiado largo. Reingrese nombre: ");
    	    		        	        		fflush(stdin);
    	    		        	        		gets(auxCad);
    	    		        	        	}

    	    		                        strcpy(vec[indice].nombre, auxCad);
    	    		                        printf("Nombre modificado!\n\n");
    	    		                        break;
    	    		                    case 2:
    	    		                        printf("Ingrese nueva edad: ");
    	    		                        cant = scanf("%d", &edad);

    	    		        	        	while(edad < 0 || cant == 0)
    	    		        	        	{
    	    		        		        	printf("edad invalido !!. Reingrese edad: ");
    	    		        		        	fflush(stdin);
    	    		        		        	cant = scanf("%d", &edad);
    	    		        	        	}

    	    		                        vec[indice].edad = edad;
    	    		                        printf("edad modificada!\n\n");
    	    		                        break;
    	    		                    case 3:
    	    		                    	listarTiposMascotas(tipos, tamSec);

    	    		        	        	printf("Ingrese Tipo de mascota: ");
    	    		        	        	scanf("%d", &idMascotas);

    	    		        	        	while(idMascotas < 1000 || idMascotas > 1004)
    	    		        	        	{
    	    		        		        	printf("Ese ID no existe!!, ingrese Tipo de mascota: ");
    	    		        		        	scanf("%d", &idMascotas);
    	    		        	        	}

    	    		        	        	vec[indice].idTipo = idMascotas;
    	    		        	        	printf("Tipo de Mascota modificada!\n\n");
    	    		                        break;
    	    		                    case 4:
    	    		                    	listarTiposColor(colores, tamSec);

    	    		        	        	printf("Ingrese Tipo de color: ");
    	    		        	        	scanf("%d", &idColor);

    	    		        	        	while(idColor < 5000 || idColor > 5004)
    	    		        	        	{
    	    		        		        	printf("Ese ID no existe!!, ingrese  color: ");
    	    		        		        	scanf("%d", &idColor);
    	    		        	        	}

    	    		        	        	vec[indice].idColor = idColor;
    	    		        	        	printf("color modificado!\n\n");
    	    		                    	break;
    	    		                    case 5:
    	    		        	        	printf("Vacunado ?(s o n): ");
    	    		        	        	fflush(stdin);
    	    		        	        	scanf("%c", &RespVacunado);
    	    		        	        	RespVacunado = tolower(RespVacunado);

    	    		        	        	while(RespVacunado !='s' && RespVacunado !='n')
    	    		        	        	{
    	    		        		        	printf("Error !!. Reingrese respuesta: ");
    	    		        		        	fflush(stdin);
    	    		        		        	scanf("%c", &RespVacunado);
    	    		        		        	RespVacunado = tolower(RespVacunado);
    	    		        	        	}

    	    		        	        	vec[indice].vacunado= RespVacunado;
    	    		        	        	printf("Estado de vacuna modificado!!!!\n\n");
    	    		                    	break;
    	    		                    default:
    	    		                    	printf("Opcion invalida!!!!\n");
    	    		                    	break;
    	    		                    }
    	    		                    respuesta=preguntaSalirDelMenuModificar();
    	    		                    system("cls");
    	    		            	}while(respuesta != 'n');

    		            	}else{
    		            		printf("Modificacion cancelada por el usuario!!!!\n\n");
    		            	}


    		            }

    		            todoOk = 1;
    		        }

    	}


    }
    return todoOk;

}

int ordenarMascotas(eMascota vec[], int tam){

    int todoOk = 0;
    eMascota auxMascota;

    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {
                if((vec[i].idTipo == vec[j].idTipo && strcmp(vec[i].nombre,vec[j].nombre) > 0)
                        ||(vec[i].idTipo != vec[j].idTipo && (vec[i].idTipo > vec[j].idTipo)))
                {
                	auxMascota = vec[i];

                    vec[i] = vec[j];
                    vec[j] = auxMascota;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


