

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

#define TAMC 20
#define TAM 5
#define TAMS 3

int main() {
	setbuf(stdout, NULL);

	char respuesta = 'n';
	int proximoId = 0;
	int proximoIdTrabajos = 0;
	eMascota lista[TAMC];
	eTrabajo trabajos[TAMC];

	eTipo tiposMascotas[TAM] =
	{
			{1000, "Ave"},
			{1001, "Perro"},
			{1002, "Roedor"},
			{1003, "Gato"},
			{1004, "Pez"}
	};

	eColor tiposColores[TAM] =
	{
			{5000, "Negro"},
			{5001, "Blanco"},
			{5002, "Rojo"},
			{5003, "Gris"},
			{5004, "Azul"}
	};

	eServicio tiposServicios[TAMS] =
	{
			{20000, "Corte", 450},
			{20001, "Desparasitado", 800},
			{20002, "Castrado", 600}
	};

	init(lista, TAMC);
	initTrabajos(trabajos, TAMC);

	printf("Hola bienvenido!!!\n");

	hardcodearMascotas(lista, TAMC, 10, &proximoId);

	do{

		switch(menuPrincipal())
		{
		case 1:
			if(altaMascota(lista, TAMC, tiposMascotas, tiposColores, TAM, &proximoId))
			{
				printf("Mascota cargada con exito!!!\n\n");
			}else{
				printf("No se pudo cargar la mascota!!!\n\n");
			}
			break;
		case 2:
			modificarMascota(lista, TAMC, tiposMascotas, tiposColores, TAM);
			break;
		case 3:
			borrarMascota(lista, TAMC, tiposMascotas, tiposColores, TAM);
			break;
		case 4:
			ordenarMascotas(lista, TAMC);
			listarMascotas(lista, TAMC, tiposMascotas, tiposColores, TAM);
			break;
		case 5:
			listarTiposMascotas(tiposMascotas, TAM);
			break;
		case 6:
			listarTiposColor(tiposColores, TAM);
			break;
		case 7:
			listarTiposServicios(tiposServicios, TAMS);
			break;
		case 8:
			if(listarMascotas(lista, TAMC, tiposMascotas, tiposColores, TAM) == 0)
			{
				if(altaTrabajo(trabajos, lista, TAMC, tiposServicios, TAMS, &proximoIdTrabajos))
				{
					printf("Trabajo cargada con exito!!!\n\n");
				}else{
					printf("No se pudo cargar el trabajo!!!\n\n");
				}
			}
			break;
		case 9:
			listarTrabajos(lista, TAMC, trabajos, tiposServicios, TAMS);
			break;
		case 10:
			respuesta = preguntaSalirDelMenu();
			break;
		default:
			printf("Opcion invalida!!!!!\n");
			break;
		}

	}while(respuesta != 's');


	system("cls");
	printf("Adios!!!!");

	return 0;
}
