
/*
 * trabajo.h
 *
 *  Created on: 17 may. 2022
 *      Author: Rodrigo
 */
#include "mascota.h"
#include "servicio.h"
#include "fecha.h"

#ifndef TRABAJO_H_
#define TRABAJO_H_


typedef struct{

	int id;
	int idMascota;
	int idServicio;
	eFecha fechaIngresada;
	int isEmpty;


} eTrabajo;


#endif /* TRABAJO_H_ */

int altaTrabajo(eTrabajo vec[], eMascota vecDos[], int tam, eServicio servicos[], int tamSec, int* pNextId);
///Realiza el alta de un trabajo en el sistema mostrandole las mascotas que hay cargadas en el sistema
/// @param eTrrabajo vec[]
/// @param eMascota vecDos[]
/// @param int tam
/// @param eServicio servicios[]
/// @param int tamSec
/// @param int* pNextId
/// @return todoOK
int initTrabajos(eTrabajo vec[], int tam);
/// inicializa toda la estructura eTrabajo cambiando su campo isEmpty a 1
/// @param eTrabajo vec[]  estructura de trabajos
/// @param int tam  tamanio
/// @return todoOK
int buscarLibreTrabajo(eTrabajo vec[], int tam, int* pIndex);
/// Busca si hay lugar en la estructura de trabajos
/// @param eTrabajo vec[]    estrucutra de trabajos
/// @param int tam      tamaño del sistema
/// @param int* pIndex   direccion de memoria de indice
/// @return todoOK
int listarTrabajos(eMascota vec[], int tam, eTrabajo trabajos[], eServicio servicios[], int tamSecDos);
///Lista a todos los trabajos que hay cargados en el sistema
/// @param eMascota vec[]
/// @param int tam
/// @param eTrabajo Trabajos[]
/// @param eServicio servicios[]
/// @param int tamSecDos
/// @return bandera      retorna una bandera que indica si hay usuarios cargados en el sistema o no los hay
void mostrarTrabajos(eTrabajo trab, eMascota masc[], eServicio servicios[], int tam);
//// esta funcion es llamada en listarTrabajos y solo me muestra toda la lista con los trabajos cargados
/// @param eTrabajo trab
/// @param eMascota masc[]
/// @param eServicio servicios[]
/// @param int tam
int cargarServicio(eServicio tipos[], int tam, int id, char desc[]);
///carga el servicio que selecciono el usuario
/// @param eServicio tipos[]
/// @param int tam
/// @param int id
/// @param char desc[]
/// @return todoOK
int cargarNombreMascota(eMascota tipos[], int tam, int id, char desc[]);
///carga el nombre de la mascota que se le realizara X servicio
/// @param eMascota tipos[]
/// @param int tam
/// @param int id
/// @param char desc[]
/// @return todoOK


