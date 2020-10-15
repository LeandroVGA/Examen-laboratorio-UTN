#include "Clientes.h"

/*
 *  Author: Leandro varela gomez
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "Clientes.h"
#include "utn.h"

/*
 * list | se le pasa la lista
 * len | se le pasa la longitud de la lista
 *
 * Se encarga de inicializar todas las variables
 *
 * */
int cliente_initArray(Cliente list[], int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
		    list[i].isEmpty = TRUE;
		    list[i].id = 0;
		    list[i].publicacionesActivas = 0;
		    strcpy(list[i].nombre, "");
		    strcpy(list[i].apellido,"");
		    strcpy(list[i].cuit,"");
		}
		retorno = 0;
	}
	return retorno;
}


//
/*
 * list | se le pasa la lista de tipo Employee
 * len | se le pasa la longitud de la lista
 *
 * Se encarga de imprimir lo que este dento de la lista
 *
 * */
int cliente_printArray(Cliente* list, int length)
{
	int retorno = -1;
	if(list != NULL && length > 0)
	{
		for(int i=0;i<length;i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id !=0)
			{
				printf(" %-6d %-12s %-13s %-13s %-6d \n"
				 //   ,list[i].isEmpty
				    ,list[i].id
				    ,list[i].nombre
				    ,list[i].apellido
				    ,list[i].cuit
					,list[i].publicacionesActivas);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int clienteActivos_printArray(Cliente* list, int length)
{
	int retorno = -1;
	if(list != NULL && length > 0)
	{
		for(int i=0;i<length;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf(" %-6d %-12s %-13s %-13s \n"
				 //   ,list[i].isEmpty
				    ,list[i].id
				    ,list[i].nombre
				    ,list[i].apellido
				    ,list[i].cuit
					,list[i].publicacionesActivas);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int cliente_isEmpty(Cliente* list, int limit, int index)
{
  int retorno = FALSE;
    if (list != NULL && list > 0)
    {
      if (list[index].isEmpty == TRUE)
	{
	  retorno = TRUE;
	}
    }
  return retorno;
}

int cliente_isEmptyForid(Cliente* list, int limit, int id)
{
  int retorno = FALSE;
    if (list != NULL && list > 0)
    {
    	for(int i = 0;i<QTY_CLIENTES;i++){

			  if (list[i].isEmpty == TRUE && list[i].id == 0 &&list[i].id == id)
			{
			  retorno = TRUE;
			}
    	}
    }
  return retorno;
}

void cliente_headerArray(void)
{
    printf("\n%*s%*s%*s%*s%*s \n",
	   -7, " ID",
	   -13," NOMBRE",
	   -14," APELLIDO",
	   -12," CUIT",
	   -14,"   PUBLICACIONES ACTIVAS",
	   "\n-----------------------------------------------------\n");
}
void cliente_headerArray2(void)
{
    printf("\n%*s%*s%*s%*s \n",
	   -7, " ID",
	   -13," NOMBRE",
	   -14," APELLIDO",
	   -12," CUIT",
	   "\n-----------------------------------------------------\n");
}
void subMenu_headerArray(void)
{
    printf("\n%*s%*s%*s \n",
	   -13," CANTIDAD AVISOS PAUSADOS     ",
	   -7, " CLIENTE CON MAS AVISOS     ",
	   -14," RUBRO CON MAS AVISOS",
	   "\n-----------------------------------------------------\n");
}




int cliente_searchFree (Cliente *list, int len)
{
  int i;
  int retorno = FALSE;

  if (list != NULL && list > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (cliente_isEmpty(list, len, i) == 1)
	    {
	      retorno = TRUE;
	      break;
	    }
	}
    }
  return retorno;
}

/*
 * list     | se le pasa la lista de tipo Employee
 * len      | se le pasa la longitud de la lista
 * id       | se le pasa el id del empleado
 * name     | se le pasa el nombre del empleado
 * lastName | se le pasa el apellido del empleado
 * salary   | se le pasa el salario del empleado
 * sector   | se le pasa el sector del empleado
 * Se encarga de agregar un empleado a la lista Employee
 *
 * */
int cliente_addArray(Cliente* list, int len, int id,char* nombre,char* apellido,char* cuit)
{
  int i;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (cliente_isEmpty(list, len, i) == 1)
	    {
	      list[i].id = id;
	      strcpy (list[i].nombre, nombre);
	      strcpy (list[i].apellido, apellido);
	      strcpy (list[i].cuit, cuit);
	      list[i].isEmpty = FALSE;
	      return 0;
	    }
	}
    }
  return -1;
}


int idIncremental(void)
{
    static int id = 0;
    id++;
    return id;
}



/*
 * list     | se le pasa la lista de tipo Employee
 * len      | se le pasa la longitud de la lista
 *
 * Se encarga de dar de alta un empleado
 *
 * */

int cliente_chargeArray (Cliente *list, int len)
{
  Cliente auxCliente;

  if (list != NULL && len > 0)
    {
      if (utn_getNombre ("Ingrese nombre del cliente: ",  "\nError al ingresar.\n", auxCliente.nombre, LONG_NAME_CLIENTES, 5) != 0)
	{
	  return -1;
	}
     if (utn_getNombre ("Ingrese apellido del cliente: ", "\nError al ingresar.\n", auxCliente.apellido, LONG_NAME_CLIENTES, 5) != 0)
	{
	  return -1;
	}
     if (utn_getNombre ("Ingrese cuit del cliente: ", "\nError al ingresar.\n", auxCliente.cuit, LONG_NAME_CLIENTES, 5) != 0)
   	{
   	  return -1;
   	}

      switch (utn_getAceptaRechaza ("\nAcepta el ingreso? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n'))
	{
	case -1:
	  return -1;
	  break;

	case 1:
	  auxCliente.id = idIncremental ();
	  printf ("\n-----------------------------------------------------");
	  printf ("\n                    ALTA EXITOSA!                  \n");
	  printf ("-----------------------------------------------------\n\n");


	  if(cliente_addArray(list, len, auxCliente.id, auxCliente.nombre, auxCliente.apellido,auxCliente.cuit)!=0)
	    {
	      return -1;
	    }
	  cliente_headerArray2();
	  printf(" %-7d",auxCliente.id);
	  printf("%-13s",auxCliente.nombre);
	  printf("%-14s",auxCliente.apellido);
	  printf("%-9s\n",auxCliente.cuit);
	  printf ("-----------------------------------------------------\n\n");

	  return 0;
	  break;

	case 0:
	  return 0;
	  break;

	default:
	  break;
	}
    }
  return -1;
}



/*
 * list     | se le pasa la lista de tipo Employee
 * len      | se le pasa la longitud de la lista
 * id       | se le pasa el id del empleado
 *
 * se encarga de encontrar a un empleado a travez del id
 *
 * */
int cliente_findById(Cliente *list, int len, int id)
{
  int i;
  int retorno = -1;

  if (list != NULL && len > 0 && id != 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].id == id)
	    {
	      retorno = id;
	      break;
	    }
	}

    }
return retorno;
}
/*
 * list     | se le pasa la lista de tipo Employee
 * len      | se le pasa la longitud de la lista
 * id       | se le pasa el id del empleado
 *
 * Se encarga de imprimir toda la informacion de un empleado a travez del id
 *
 * */
int cliente_printForId(Cliente *list, int len, int id)
{
  int retorno = -1;
  int i;
  	if(list != NULL && len > 0)
  	{
  		cliente_headerArray();
  		for( i=0;i<len;i++)
  		{
  			if(list[i].id == id && list[i].isEmpty == FALSE && list[i].cuit > 0)
  			{
  				printf(" %-6d %-12s %-13s %-13s \n"
  				  //  ,list[i].isEmpty
  				    ,list[i].id
  				    ,list[i].nombre
  				    ,list[i].apellido
  				    ,list[i].cuit);
  			}
  		}
  		retorno = 0;
  	}
 return retorno;
}

int cliente_printForId2(Cliente *list, int len, int id)
{
  int retorno = -1;
  int i;
  	if(list != NULL && len > 0)
  	{
  		cliente_headerArray2();
  		for( i=0;i<len;i++)
  		{
  			if(list[i].id == id && list[i].isEmpty == FALSE && list[i].cuit > 0)
  			{
  				printf(" %-6d %-12s %-13s %-13s \n"
  				  //  ,list[i].isEmpty
  				    ,list[i].id
  				    ,list[i].nombre
  				    ,list[i].apellido
  				    ,list[i].cuit);
  			}
  		}
  		retorno = 0;
  	}
 return retorno;
}




int cliente_arrayToBuffer(Cliente *list,Cliente *listBuffer, int len, int id)
{
  int retorno = -1;
    int i;
    	if(list != NULL && len > 0)
    	{
    	      for( i=0;i<len;i++)
    		{
    			if(list[i].id == id)
    			{
    			*listBuffer=list[i];
    			}
    		}
    		retorno = 0;
    	}
return retorno;
}


int cliente_bufferToArray(Cliente *list, Cliente *listBuffer, int len, int id)
{
  int i;
  int retorno = -1;
  if (list != NULL && listBuffer != NULL && len > 0)
    {

	for (i = 0; i < len; i++)
	  {
	    if (list[i].id == id)
	      {
		list[i] = *listBuffer;
		retorno = 0;
	      }
	  }
    }
  return retorno;
}



/*
 * list     | se le pasa la lista de tipo Employee
 * len      | se le pasa la longitud de la lista
 *
 * se encarga de modificar el valor de la informacion de un empleado en base a su id
 *
 * */
int cliente_updateArray (Cliente *list, int len)
{
  int bufferID;
  int retorno = -1;
  int opcion;
  Cliente auxCliente;

  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese ID del cliente: ", "\nError al ingresar. ", &bufferID, 1, QTY_CLIENTES, 5);
      if (cliente_findById(list, len, bufferID) != -1)
	{
	  retorno = 0;
	  cliente_arrayToBuffer(list, &auxCliente,  len,  bufferID);
	  do
	     {
		  cliente_printForId  (&auxCliente,len,  bufferID);
	      printf ("\n1-Nombre-\n"
	    		  "2-Apellido-\n"
	      	      "3-Cuit-\n"
	      	      "4-Aceptar Cambios-\n"
	      	      "5-Salir-\n");

	       if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 6, 3) != -1)
	 	{
	 	  switch (opcion)
	 	    {
	 	    case 1:
	 	      printf ("\nNOMBRE\n-----------\n");

	 	     if (utn_getNombre ("Ingrese nombre del cliente: ",  "\nError al ingresar.\n", auxCliente.nombre, LONG_NAME_CLIENTES, 5) != 0)
	 	    	{
	 	    	  return -1;
	 	    	}
	 	      break;
	 	    case 2:
	 	      printf ("\nAPELLIDO\n-----------\n");
	 	     if (utn_getNombre ("Ingrese apellido del cliente: ", "\nError al ingresar.\n", auxCliente.apellido, LONG_NAME_CLIENTES, 5) != 0)
	 	   	{
	 	   	  return -1;
	 	   	}
	 	      break;
	 	   case 3:
	 	  	 	      printf ("\nCUIT\n-----------\n");
	 	  	 	     if (utn_getNombre ("Ingrese cuit del cliente: ", "\nError al ingresar.\n", auxCliente.cuit, LONG_NAME_CLIENTES, 5) != 0)
	 	  	 	   	{
	 	  	 	   	  return -1;
	 	  	 	   	}
	 	      break;
	 	   case 4:
	 		 if(utn_getAceptaRechaza ("\nGrabar cambios? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
	 		   {
	 			cliente_bufferToArray (list, &auxCliente,  len, bufferID);
	 		    printf ("\nLOS CAMBIOS SE GRABARON EXITOSAMENTE!\n");

	 		   }
	 	      break;
	 	    }
	 	}
	       else
	 	{
	 	  printf ("\nTE QUEDASTE SIN REINTENTOS\n");
	 	  system ("pause");
	 	  return EXIT_SUCCESS;
	 	}
	     }
	   while (opcion != 5);

	  if(opcion == 5)
	    {
	      return EXIT_SUCCESS;
	    }
	}//final del if findEmployeeById
      else
	{
	  printf ("\nEl ID NO existe\n");
	}
    }//final de validacion de null
  return retorno;
}

/*
 * list     | se le pasa la lista de tipo Cliente
 * len      | se le pasa la longitud de la lista
 * id       | se le pasa el id del empleado
 *
 * Se encarga de eliminar un empleado a la lista Cliente
 *
 * */
int cliente_removeArray(Cliente* list, int len, int id)
{
  int i;
  int retorno;

  if (list != NULL && len > 0 && id > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].id == id)
	    {
	      list[i].isEmpty = TRUE;
	      retorno = 0;
	    }
	}
    }
 return retorno;
}


int cliente_prepareForDelete(Cliente *list, int len)
{
  int retorno = -1;
  int bufferID;

  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese ID del cliente: ", "\nError al ingresar. ", &bufferID, 1, QTY_CLIENTES, 5);
      if (cliente_findById (list, len, bufferID) != -1)
	{
    	  cliente_printForId(list, len, bufferID);
	  retorno = utn_getAceptaRechaza ("\nAcepta eliminar cliente? s/n: ", "ERROR al ingresar opcion. \n", 's','n');
	  if (retorno == 1)
	    {
		  cliente_removeArray(list, len, bufferID);
	      retorno = 1;
	      printf ("\n------------------------------------------------------");
	      printf ("\n             ELIMINACION EXITOSA!\n");
	      printf ("------------------------------------------------------\n\n");
	    }
	}
    }
  return retorno;
}


/*
 * list     | se le pasa la lista de tipo cliente
 * len      | se le pasa la longitud de la lista
 * order    | se le pasa el valor para ordenar menor a 0 o mayor a 0 (-1 o 1)
 * Se encarga de agregar un empleado a la lista Employee
 *
 * */
int cliente_sortArray(Cliente* list, int len, int order)
{
  int flagSwap;
  int i;
  int contador = 0;
  int retorno = -1;
  Cliente buffer;
  int nuevoLimite;

  if (list != NULL && len >= 0)
    {
      nuevoLimite = len - 1;
      do
	{
	  flagSwap = 0;

	  for (i = 0; i < nuevoLimite; i++)
	    {
	      contador++;
	      if ((order == 0 && strcmp (list[i].apellido, list[i + 1].apellido) < 0)||
		  (order == 1 && strcmp (list[i].apellido, list[i + 1].apellido) > 0)||
		  (0==strcmp (list[i].apellido, list[i + 1].apellido)))
		{
		  flagSwap = 1;
		  buffer = list[i];
		  list[i] = list[i + 1];
		  list[i + 1] = buffer;
		}
	    }
	  nuevoLimite--;
	}
      while (flagSwap);
      retorno = contador;
    }
  return retorno;
}


/*
float sumaTotal (Cliente *list, int len)
{
  int i;
  float retorno = -1;
  float aux = 0;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE )
	    {
	      aux = aux + list[i].FLOTANTE1;
	    }
	}
      retorno = aux;
    }
  return retorno;
}
*/


float promedio(Cliente* list, int len)
{
  int i;
  float retorno = -1;
  int contador = 0;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE )
	    {
	      contador++;
	    }
	}
     // retorno = sumaTotal (list, len) / contador;
    }
  return retorno;
}


int cantidadSuperiorAlPronedio(Cliente* list, int len)
{

  int i;
  int retorno = -1;
  int contador = 0;
  float aux;

  aux = promedio (list, len);
  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE )
	    {
	      contador++;
	    }
	}
      retorno = contador;
    }
  return retorno;
}



int cliente_flagLimite(Cliente* list, int len)
{
  int retorno = -1;
  int i;
  int contador = 0;

  for (i = 0; i < len; i++)
    {
      if (i <= len && list[i].isEmpty == FALSE)
	{
	  contador++;
	}
    }
  if (contador == 0)
    {
      retorno = 0;
    }
  else if (contador > 0 && contador != len)
    {
      retorno = contador;
    }
  return retorno;
}


