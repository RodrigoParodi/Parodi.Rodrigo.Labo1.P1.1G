/*
 * tipo.h
 *
 *  Created on: 17 may. 2022
 *      Author: Rodrigo
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct{

	int id;
	char descripcion[20];

} eTipo;


#endif /* TIPO_H_ */


int listarTiposMascotas(eTipo tipos[], int tam);
int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char desc[]);
