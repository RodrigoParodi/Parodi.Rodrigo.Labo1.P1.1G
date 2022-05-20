/*
 * menu.c
 *
 *  Created on: 17 may. 2022
 *      Author: Rodrigo
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mascota.h"
#include "validaciones.h"

char preguntaSalirDelMenu(){

	char respuesta;

	printf("Desea salir ?('s' o 'n'): ");
	fflush(stdin);
	scanf("%c", &respuesta);
	respuesta = tolower(respuesta);

	while(respuesta !='s' && respuesta !='n')
	{
		printf("Error, Desea salir ? ('s' o 'n'): ");
		fflush(stdin);
		scanf("%c", &respuesta);
		respuesta = tolower(respuesta);
	}

	return respuesta;
}

int menuPrincipal(){

	int opciones;

	system("pause");
	system("cls");

	printf("\n\n MENU DE OPCIONES.\n\n");
	printf("1)ALTA MASCOTA.\n");
	printf("2)MODIFICAR MASCOTA.\n");
	printf("3)BAJA MASCOTA.\n");
	printf("4)LISTAR MASCOTAS.\n");													//menu principal.
	printf("5)LISTAR TIPOS.\n");
	printf("6)LISTAR COLORES.\n");
	printf("7)LISTAR SERVICIOS.\n");
	printf("8)ALTA TRABAJO.\n");
	printf("9)LISTAR TRABAJOS.\n");
	printf("10)INFORMES.\n");
	printf("11)Salir.\n\n");

	printf("Eliga que opcion desea iniciar : ");
	fflush(stdin);
	scanf("%d", &opciones);

	return opciones;

}

char preguntaSalirDelMenuModificar(){

	char respuesta;

	printf("Desea modificar otro dato ?('s' o 'n'): ");
	fflush(stdin);						      //FUNCION PARA SALIR DEL MENU O NO
	scanf("%c", &respuesta);
	respuesta = tolower(respuesta);

	while(respuesta !='s' && respuesta !='n')
	{
		printf("Error, Desea salir ? ('s' o 'n'): ");
		fflush(stdin);
		scanf("%c", &respuesta);
		respuesta = tolower(respuesta);
	}

	return respuesta;
}

int menuModificarMascota(){
	int opcion;

    printf("     *** Campo a modificar ***\n\n");
    printf("1. Nombre.\n");
    printf("2. edad.\n");
    printf("3. Tipo de mascota.\n");
    printf("4. Color.\n");
    printf("5. Estado Vacunado.\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

int menuInformes(){
	int opcion;

    printf("     *** Menu de informes ***\n\n");
    printf("1. Informe.\n");
    printf("2. Informe.\n");
    printf("3. Informe.\n");
    printf("4. Informe.\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


