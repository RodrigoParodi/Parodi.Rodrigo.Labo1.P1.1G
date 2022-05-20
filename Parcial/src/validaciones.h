/*
 * validaciones.h
 *
 *  Created on: 17 may. 2022
 *      Author: Rodrigo
 */
#include "mascota.h"

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */

int buscarLibre(eMascota vec[], int tam, int* pIndex);
/// Busca si hay lugar en la estructura de mascotas
/// @param eMascota vec[]    estrucutra de mascotas
/// @param int tam      tamaño del sistema
/// @param int* pIndex   direccion de memoria de indice
/// @return todoOK
int validarCadena(char cadena[50]);
/// Valida una cadena de caracteres, evita que se pongan numeros
/// @param cadena[50]  cadena a validar
/// @return sw    si se ingresaron numeros devuelve sw = 1 y nos obliga a volver a escribir la cadena sin numeros
int mayusculaPrimerCaracter(char cadena[]);
/// Pone la primera letra de una cadena en mayusculas
/// @param char cadena[]
/// @return todoOK
int init(eMascota vec[], int tam);
/// inicializa toda la estructura eMascota cambiando su campo isEmpty a 1
/// @param eMascota vec[]  estructura de mascotas
/// @param int tam  tamanio
/// @return todoOK
int buscarMascotasPorId(eMascota vec[], int tam, int id, int* pIndex);
///Busca a X mascota por su numero de ID
///@param eMascota vec[]
/// @param int tam
/// @param int id
/// @param int* pIndex
/// @return todoOK
