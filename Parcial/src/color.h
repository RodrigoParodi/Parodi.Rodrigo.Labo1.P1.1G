/*
 * color.h
 *
 *  Created on: 17 may. 2022
 *      Author: Rodrigo
 */

#ifndef COLOR_H_
#define COLOR_H_

typedef struct{

	int id;
	char nombreColor[20];

} eColor;


#endif /* COLOR_H_ */

int listarTiposColor(eColor tipos[], int tam);
/// Muestra los tipos de colores que hay cargados en el sistema
/// @param eColor tipos[]  estructura de colores
/// @param int tam    cantidad de colores
/// @return todoOK
int cargarDescripcionColor(eColor color[], int tam, int id, char desc[]);
/// toma el idColor cargado en la estrucutura de mascotas y le carga su descripcion
/// @param eColor color[]
/// @param int tam
/// @param int id   idColor de la estructura mascotas.h
/// @param char desc[]      aqui se guarda la descripcion
/// @return todoOK
