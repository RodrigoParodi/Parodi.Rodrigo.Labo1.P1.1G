/*
 * mascota.h
 *
 *  Created on: 17 may. 2022
 *      Author: Rodrigo
 */

#include "color.h"
#include "tipo.h"

#ifndef MASCOTA_H_
#define MASCOTA_H_

typedef struct{

	int id;
	char nombre[20];
	int idTipo;
	int idColor;
	int edad;
	char vacunado;
	int isEmpty;

} eMascota;


#endif /* MASCOTA_H_ */

int altaMascota(eMascota vec[], int tam, eTipo tipos[], eColor colores[], int tamSec, int* pNextId);
///Realiza el alta de una mascota en el sistema pidiendole que ingrese los datos requeridos
/// @param eMascota vecDos[]
/// @param int tam
/// @param eTipo tipos[]
/// @param eColor colores[]
/// @param int tamSec
/// @param int* pNextId
/// @return todoOK
int listarMascotas(eMascota vec[], int tam, eTipo tipos[], eColor colores[], int tamSec);
///Lista a todas las mascotas que hay cargados en el sistema
/// @param eMascota vec[]
/// @param int tam
/// @param eTipo Tiposs[]
/// @param eColor colores[]
/// @param int tamSec
/// @return bandera      retorna una bandera que indica si hay usuarios cargados en el sistema o no los hay
void mostrarMascotas(eMascota Masc, eTipo tipos[], eColor colores[], int tam);
//// esta funcion es llamada en listarMascotas y solo me muestra toda la lista con las mascotas cargadas
/// @param eMascota Masc
/// @param eTipo tipos[]
/// @param eColor colores[]
/// @param int tam
int borrarMascota(eMascota vec[], int tam, eTipo tipos[], eColor colores[], int tamSec);
///Borra a una mascota del sistema pidiendo que ingresemos su id, mostrara sus datos y luego nos pedira confirmacion todo esto llamado a otras dos funciones
/// @param eMascota vec[]
/// @param int tam
/// @param eTipo tipos[]
/// @param eColor colores[]
/// @param int tamSec
/// @return todoOK
void mostrarMascota(eMascota Masc, eTipo tipos[], eColor colores[], int tam);
//// esta funcion es llamada en BorrarMascotas y modificarMascotas y solo me muestra los datos de X mascota seleccionada
/// @param eMascota Masc
/// @param eTipo tipos[]
/// @param eColor colores[]
/// @param int tam
int modificarMascota(eMascota vec[], int tam, eTipo tipos[], eColor colores[], int tamSec);
/// modifica los datos de X mascota que nosotros seleccionemos
/// @param eMascota vec[]
/// @param int tam
/// @param eTipo tipos[]
/// @param eColor colores[]
/// @param int tamSec
/// @return todoOK
int ordenarMascotas(eMascota vec[], int tam);
/// Ordena a las mascotas por nombre y tipo
/// @param eMascota vec[]
/// @param int tam
/// @return todoOK
