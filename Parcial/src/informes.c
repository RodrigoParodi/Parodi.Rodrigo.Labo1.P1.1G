/*
 * informes.c
 *
 *  Created on: 20 may. 2022
 *      Author: Rodrigo
 */

#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "fecha.h"
#include "mascota.h"
#include "servicio.h"
#include "tipo.h"
#include "trabajo.h"
#include "menu.h"
#include "validaciones.h"



int mostrarMascotasColor(eMascota vec[], eTipo tipos[], eColor colores[], int tam, int tamSec){

    int todoOK = 0;
    int idColor;

    listarTiposColor(colores, tamSec);

    printf("Ingrese ID de color: ");
    scanf("%d", &idColor);

    while(idColor < 5000 || idColor > 5004)
    {
        printf("Este id no existe, ReIngrese ID de color: ");
        scanf("%d", &idColor);
    }
    system("cls");

    printf("       *** Lista de mascotas de color seleccionado ***\n");
    printf("  id          Nombre         Edad           Tipo             Color              Vacunado ?\n");
    printf("___________________________________________________________________________________________\n");
    for(int i=0; i < tam; i++)
    {
        if( !vec[i].isEmpty && vec[i].idColor == idColor)
        {
        	mostrarMascotas(vec[i], tipos, colores, tam);
        }
    }
    printf("____________________________________________________________________________________________\n\n");


	return todoOK;
}

int promedioMascotasVacunadas(eMascota vec[], int tam){

    int todoOK = 0;
    int contadorVacunados =0;
    int totalMascotas = 0;
    float promedio;

    for(int i=0; i < tam; i++)
    {
        if( !vec[i].isEmpty && vec[i].vacunado == 's')
        {
        	contadorVacunados++;
        }
    }

    for(int i=0; i < tam; i++)
    {
        if( !vec[i].isEmpty)
        {
        	totalMascotas++;
        }
    }

    promedio= (float) totalMascotas / contadorVacunados;

    printf("hay un total de  %d  mascotas en el sistema\n", totalMascotas);
    printf("%d  de estas mascotas estan vacunadas\n\n", contadorVacunados);
    printf("El promedio es de : %.2f\n\n", promedio);


	return todoOK;
}


int mostrarMascotasEdadMinima(eMascota vec[], eTipo tipos[], eColor colores[], int tam, int tamSec){

    int todoOK = 0;
    int edadMinima;


    for(int i=0; i < tam; i++)
    {
        if( !vec[i].isEmpty && vec[i].edad < edadMinima)
        {
            edadMinima = vec[i].edad;
        }
    }

    printf("       *** Lista de mascotas de menor edad ***\n");
    printf("  id          Nombre         Edad           Tipo             Color              Vacunado ?\n");
    printf("___________________________________________________________________________________________\n");
    for(int i=0; i < tam; i++)
    {
        if( !vec[i].isEmpty && vec[i].edad == edadMinima)
        {
        	mostrarMascotas(vec[i], tipos, colores, tam);
        }
    }
    printf("____________________________________________________________________________________________\n\n");


	return todoOK;
}

int listarMascotasPorTipo(eMascota vec[], int tam){

    int todoOk = 0;
    eMascota auxMascota;

    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {
                if((vec[i].idTipo == vec[j].idTipo ) ||(vec[i].idTipo != vec[j].idTipo && (vec[i].idTipo > vec[j].idTipo)))
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

int cantidadDeTipoYColor(eMascota vec[], eTipo tipos[], eColor colores[], int tam, int tamSec){
    int todoOK = 0;
    int idColor;
    int idTipo;
    int contadorTipo = 0;
    int contadorColor = 0;
	char tiposMascotas[20];
	char tiposColores[20];

    listarTiposColor(colores, tamSec);

    printf("Ingrese ID de color: ");
    scanf("%d", &idColor);

    while(idColor < 5000 || idColor > 5004)
    {
        printf("Este id no existe, ReIngrese ID de color: ");
        scanf("%d", &idColor);
    }
    system("cls");

    listarTiposMascotas(tipos, tamSec);

    printf("Ingrese ID de tipo de mascota: ");
    scanf("%d", &idTipo);

    while(idTipo < 1000 || idTipo > 1004)
    {
        printf("Este id no existe, ReIngrese ID de tipo de mascota: ");
        scanf("%d", &idTipo);
    }
    system("cls");

    for(int i=0; i < tam; i++)
    {
        if( !vec[i].isEmpty && vec[i].idColor == idColor)
        {
        	contadorColor++;
        }
    }

    for(int i=0; i < tam; i++)
    {
        if( !vec[i].isEmpty && vec[i].idTipo == idTipo)
        {
        	contadorTipo++;
        }
    }


	cargarDescripcionTipo(tipos, tam, idTipo, tiposMascotas);
	cargarDescripcionColor(colores, tam, idColor, tiposColores);

	printf("Hay %d Mascotas del color  %s   \n", contadorColor, tiposColores);
	printf("Hay %d Mascotas del tipo  %s  \n", contadorTipo, tiposMascotas);

	return todoOK;
}







