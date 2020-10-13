/*
 ============================================================================
 Name        : TP2.c
 Author      : Leandro varela gomez  - 1H
 ============================================================================
 */

#ifndef PUBLICACION_H_
#define PUBLICACION_H_

#include"Clientes.h"

#define TRUE 1
#define FALSE 0
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
#define LONG_NAME_PUBLICACION 51
#define LONG_PUBLICACION 64
#define QTY_PUBLICACION 1000
#define ACTIVO 1
#define PAUSADO 0
#define VACIO -1
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////

struct
{
int id;
int isEmpty;
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
/*char name[LONG_NAME_TEMPLATE];
char lastName[LONG_NAME_TEMPLATE];
float salary;
int sector;*/
int idCliente;
int numeroRubro;
char textoAviso[LONG_PUBLICACION];
int valorEstadoPublicacion;
char estado[7];



}typedef Publicacion;//SOLO SE DEBE HACER REFACTOR EN EL NOMBRE DE LA ENTIDAD
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////

int publicacion_isEmpty(Publicacion* list, int limit, int index);

//FUNCIONES MODIFICABLES
int publicacion_initArray(Publicacion* list, int len); ////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////

int publicacion_addArray(Publicacion* list, int len, int id,////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		      int numeroRubro,
		      char* textoAviso,
		      int idCliente,
			  char* estado,
			  int valorEstadoPublicacion
///////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		      );
int publicacion_printArray(Publicacion* list, int length);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int publicacion_sortArray(Publicacion* list, int len, int order);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
void publicacion_headerArray(void);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int publicacion_printForId  (Publicacion *list, int len, int id);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int publicacion_chargeArray (Publicacion list[],Cliente listC[], int len);
int publicacion_updateArray (Publicacion* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int publicacion_printForIdSinHeader(Publicacion *list, int len, int id);

//FUNCIONES NO MODIFICABLES
int publicacion_findById (Publicacion *list, int len, int id);
int publicacion_removeArray(Publicacion* list, int len, int id);
int publicacion_searchFree (Publicacion* list, int len);
int publicacion_bufferToArray (Publicacion* list, Publicacion * , int len, int id);
int publicacion_arrayToBuffer(Publicacion *list,Publicacion *listBuffer, int len, int id);
int publicacion_deleteArray (Publicacion* list, int len);
int publicacion_flagLimite(Publicacion* list, int len);
int publicacion_prepareForDelete (Publicacion *list, int len);
int publicacion_buscarIndiecePorId (Publicacion *list, int len, int idBuscar, int *pIndice);



#endif /* PUBLICACION_H_ */
