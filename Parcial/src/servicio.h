/*
 * servicio.h
 *
 *  Created on: 17 may. 2022
 *      Author: Rodrigo
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct{

	int id;
	char descripcion[25];
	float precio;

} eServicio;


#endif /* SERVICIO_H_ */

int listarTiposServicios(eServicio tipos[], int tam);
/// Le muestra al usuario todos los tipos de servicios que hay cargados en el sistema para que seleccione uno de ellos
/// @param eServicio tipos[]   Estructura de servicios donde estan guardados los datos del sector
/// @param int tam   tamanio de servicios
/// @return todoOK
