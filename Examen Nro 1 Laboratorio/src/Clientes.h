#ifndef CLIENTES_H_
#define CLIENTES_H_

#define TRUE 1
#define FALSE 0
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
#define LONG_NAME_CLIENTES 51
#define QTY_CLIENTES 100


/*char name[LONG_NAME_TEMPLATE];
char lastName[LONG_NAME_TEMPLATE];
float salary;
int sector;*/
struct{
int isEmpty;
int id;
char nombre[LONG_NAME_CLIENTES];
char apellido[LONG_NAME_CLIENTES];
char cuit [LONG_NAME_CLIENTES];
int publicacionesActivas;
}typedef Cliente;

int cliente_isEmpty(Cliente* list, int limit, int index);

//FUNCIONES MODIFICABLES
int cliente_initArray(Cliente* list, int len); ////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////

int cliente_addArray(Cliente* list, int len, int id,////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		      char* nombre,
		      char* apellido,
		      char* cuit
///////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		      );
int cliente_printArray(Cliente* list, int length);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int cliente_sortArray(Cliente* list, int len, int order);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
void cliente_headerArray(void);
void cliente_headerArray2(void);
void subMenu_headerArray(void);
int cliente_printForId(Cliente *list, int len, int id);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int cliente_chargeArray (Cliente* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int cliente_updateArray (Cliente* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
float cliente_sumaTotal(Cliente* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
float cliente_promedio(Cliente* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int cliente_cantidadSuperiorAlPromedio(Cliente* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int cliente_isEmptyForid(Cliente* list, int limit, int id);
int cliente_printForId2(Cliente *list, int len, int id);





//FUNCIONES NO MODIFICABLES
int cliente_findById (Cliente *list, int len, int id);
int cliente_removeArray(Cliente* list, int len, int id);
int cliente_searchFree (Cliente* list, int len);
int cliente_bufferToArray (Cliente* list, Cliente *listBuffer, int len, int id);
int cliente_arrayToBuffer(Cliente *list,Cliente *listBuffer, int len, int id);
int cliente_deleteArray (Cliente* list, int len);
int cliente_flagLimite(Cliente* list, int len);
int cliente_prepareForDelete (Cliente *list, int len);
int cliente_buscarIndiecePorId (Cliente *list, int len, int idBuscar, int *pIndice);



#endif /* CLIENTES_H_ */
