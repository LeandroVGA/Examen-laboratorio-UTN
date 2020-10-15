/*
 *  Created on: 26 sep. 2020
 *  Author: Leandro varela gomez
 */


#include "Publicacion.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "utn.h"
#include "clientesPublicacion.h"
#include "Clientes.h"

/*
 * list | se le pasa la lista
 * len | se le pasa la longitud de la lista
 *
 * Se encarga de inicializar todas las variables
 *
 * */
int publicacion_initArray(Publicacion list[], int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
		    list[i].isEmpty = TRUE;
		    list[i].id = 0;
		    list[i].numeroRubro = 0;
		    strcpy(list[i].textoAviso,"");
		    list[i].idCliente = 0;
		    strcpy(list[i].estado,"VACIO");
		    list[i].valorEstadoPublicacion = -1;
		}
		retorno = 0;
	}
	return retorno;
}


//
/*
 * list | se le pasa la lista de tipo Publicacion
 * len  | se le pasa la longitud de la lista
 *
 * Se encarga de imprimir lo que este dento de la lista
 *
 * */
int publicacion_printArray(Publicacion* list, int length)
{
	int retorno = -1;

	if(list != NULL && length > 0)
	{
		for(int i=0;i<length;i++)
		{
			if(list[i].isEmpty == FALSE )
			{
				if(list[i].valorEstadoPublicacion == 1 ){

					strcpy(list[i].estado,"ACTIVA");

				}else if(list[i].valorEstadoPublicacion == 0){

					strcpy(list[i].estado,"PAUSADA");

				}else{

					strcpy(list[i].estado,"VACIO");
				}

				printf("  %-7d %-16d %-11d %-13s %-13s %-13d  \n"
				 //   ,list[i].isEmpty
				    ,list[i].id
				    ,list[i].numeroRubro
				    ,list[i].idCliente
					,list[i].estado
				    ,list[i].textoAviso
					,list[i].valorEstadoPublicacion
					);
			}
		}
		retorno = 0;
	}
	return retorno;
}
/*
 * list     | se le pasa la lista de tipo Publicacion
 * limit     | se le pasa la longitud de la lista
 * index    | se le pasa el indice de la lista
 *
 * Se encarga de calcular quien es el cliente con mas avisos
 *
 * */
int publicacion_isEmpty(Publicacion* list, int limit, int index)
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


/**
 *se encarga de generar los titulos de todas las columnas a mostrar por printf
 *
 */
void publicacion_headerArray(void)
{
    printf("\n %*s %*s %*s %*s %*s \n",
	   -7, " ID",
	   -13," NUMERO DE RUBRO",
	   -2," ID CLIENTE",
	   -12," ESTADO",
	   -14," TEXTO EN AVISO"
	   "\n-----------------------------------------------------\n");
}


/**
 *se encarga de generar los titulos de todas las columnas a mostrar por printf
 *
 */
void publicacion_headerArray2(void)
{
    printf("\n %*s %*s %*s \n",
	   -2," ID CLIENTE",
	   -13," NUMERO DE RUBRO",
	   -14," TEXTO EN AVISO"
	   "\n-----------------------------------------------------\n");
}



int publicacion_searchFree (Publicacion *list, int len)
{
  int i;
  int retorno = FALSE;

  if (list != NULL && list > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (publicacion_isEmpty(list, len, i) == 1)
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
int publicacion_addArray(Publicacion* list, int len, int id,int numeroRubro,char* textoAviso,int idCliente,char *estado,int valorEstadoPublicacion)
{
  int i;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (publicacion_isEmpty(list, len, i) == 1)
	    {
	      list[i].id = id;
	      list[i].numeroRubro = numeroRubro;
	      strcpy (list[i].textoAviso, textoAviso);
	      strcpy (list[i].estado, estado);
	      list[i].idCliente = idCliente;
	      list[i].valorEstadoPublicacion = valorEstadoPublicacion;
	      list[i].isEmpty = FALSE;
	      return 0;
	    }
	}
    }
  return -1;
}


int idIncrementalPublicacion(void)
{
    static int id = 0;
    id++;
    return id;
}



/*
 * list     | se le pasa la lista de tipo Publicacion
 * listC    | se lep asa la lista de tipo Cliente
 * len      | se le pasa la longitud de la lista
 *
 * Se encarga de dar de alta una publicacion
 *
 * */

int publicacion_chargeArray (Publicacion list[],Cliente listC[], int len)
{
	Publicacion auxPublicacion;


  if (list != NULL && len > 0)
    {
	  if (utn_getNumero ("Ingrese el numero de rubro ", "\nError al ingresar. Por favor ", &auxPublicacion.numeroRubro, 0, 1000, 5)!= 0)
	  	{
	  	  return -1;
	  	}
		 if (utn_getNombre ("Ingrese el texto a mostrar en el aviso: ", "\nError al ingresar.\n", auxPublicacion.textoAviso, LONG_PUBLICACION, 5) != 0)
		{
		  return -1;
		}
		 do{

			  if (utn_getNumero ("Ingrese id de cliente: ", "\nError al ingresar. Por favor ", &auxPublicacion.idCliente, 0, 100, 5)!= 0)
			{
			  return -1;
			}

			  if(cliente_findById(listC, QTY_CLIENTES, auxPublicacion.idCliente)==-1){

				  printf("%s","El id del cliente no existe\n");

			  }

		 }
      while(cliente_findById(listC, QTY_CLIENTES, auxPublicacion.idCliente)==-1);

		  publicacion_headerArray2();
		  printf("  %-12d",auxPublicacion.idCliente);
		  printf("%-17d",auxPublicacion.numeroRubro);
		  printf("%-15s",auxPublicacion.textoAviso);

		  switch (utn_getAceptaRechaza ("\nAcepta el ingreso? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n'))
		{

		case -1:
		  return -1;
		  break;

		case 1:
		  auxPublicacion.valorEstadoPublicacion = 1;
		  auxPublicacion.id = idIncrementalPublicacion ();
		  printf ("\n-----------------------------------------------------");
		  printf ("\n                    ALTA EXITOSA!                  \n");
		  printf ("-----------------------------------------------------\n\n");


		  if(publicacion_addArray(list, len, auxPublicacion.id, auxPublicacion.numeroRubro, auxPublicacion.textoAviso,auxPublicacion.idCliente,auxPublicacion.estado,auxPublicacion.valorEstadoPublicacion)!=0)
			{

			  return -1;
			}

		  if(auxPublicacion.valorEstadoPublicacion == 1){

				strcpy(auxPublicacion.estado,"ACTIVA");

			}else{

				strcpy(auxPublicacion.estado,"PAUSADA");

			}
		  publicacion_headerArray();
		  printf("  %-12d",auxPublicacion.id);
		  printf("%-13d",auxPublicacion.numeroRubro);
		  printf("%-12d",auxPublicacion.idCliente);
		  printf("%-13s",auxPublicacion.estado);
		  printf("%-15s",auxPublicacion.textoAviso);

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
 * list     | se le pasa la lista de tipo Publciacion
 * len      | se le pasa la longitud de la lista
 * id       | se le pasa el id d la publicacion
 *
 * se encarga de encontrar una publicacion a travez del id
 *
 * */
int publicacion_findById(Publicacion *list, int len, int id)
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
 * list     | se le pasa la lista de tipo Publicacion
 * len      | se le pasa la longitud de la lista
 * id       | se le pasa el id del publicacion
 *
 * Se encarga de imprimir toda la informacion de una ublicacion a travez del id
 *
 * */
int publicacion_printForId(Publicacion *list, int len, int id)
{
  int retorno = -1;
  int i;
  	if(list != NULL && len > 0)
  	{


  		publicacion_headerArray();
  		for( i=0;i<len;i++)
  		{
  		if(list[i].valorEstadoPublicacion == 1){

			strcpy(list[i].estado,"ACTIVA");

		}else{

			strcpy(list[i].estado,"PAUSADA");

		}
  			if(list[i].id == id && list[i].isEmpty == FALSE && list[i].idCliente != FALSE )
  			{
  				printf("  %-7d %-16d %-11d %-13s %-13s  \n"
				 //   ,list[i].isEmpty
					,list[i].id
					,list[i].numeroRubro
					,list[i].idCliente
					,list[i].estado
					,list[i].textoAviso
					);
			}
  		}
  		retorno = 0;
  	}
 return retorno;
}


/*
 * list     | se le pasa la lista de tipo Publicacion
 * len     | se le pasa la longitud de la lista
 * id    | se le pasa el id de la publicacion
 *
 * Se encarga de mostrar por printf todas las publicaciones pero sin header
 *
 * */
int publicacion_printForIdSinHeader(Publicacion *list, int len, int id)
{
  int retorno = -1;
  int i;
  	if(list != NULL && len > 0)
  	{

  		for( i=0;i<len;i++)
  		{
  		if(list[i].valorEstadoPublicacion == 1){

			strcpy(list[i].estado,"ACTIVA");

		}else{

			strcpy(list[i].estado,"PAUSADA");

		}
  			if(list[i].id == id && list[i].isEmpty == FALSE && list[i].idCliente != FALSE )
  			{
  				printf("  %-7d %-16d %-11d %-13s %-13s  \n"
				 //   ,list[i].isEmpty
					,list[i].id
					,list[i].numeroRubro
					,list[i].idCliente
					,list[i].estado
					,list[i].textoAviso
					);
			}
  		}
  		retorno = 0;
  	}
 return retorno;
}




int publicacion_arrayToBuffer(Publicacion *list,Publicacion *listBuffer, int len, int id)
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


int publicacion_bufferToArray(Publicacion *list, Publicacion *listBuffer, int len, int id)
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
 * list     | se le pasa la lista de tipo Publicacion
 * len      | se le pasa la longitud de la lista
 *
 * se encarga de modificar el valor de la informacion de la publicacion en base a su id
 *
 * */
int publicacion_updateArray (Publicacion *list, int len)
{
  int bufferID;
  int retorno = -1;
  int opcion;
  Publicacion auxEmployee;

  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese ID de la publicacion ", "\nError al ingresar. ", &bufferID, 1, QTY_PUBLICACION, 5);
      if (publicacion_findById(list, len, bufferID) != -1)
	{
	  retorno = 0;
	  publicacion_arrayToBuffer(list, &auxEmployee,  len,  bufferID);
	  do
	     {
		  publicacion_printForId  (&auxEmployee,len,  bufferID);
	      printf ("\n1-Numero de rubro-\n"
	    		  "2-Texto del aviso-\n"
	      	      "3-Id cliente-\n"
	      	      "4-Aceptar Cambios-\n"
	      	      "5-Salir-\n");

	       if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 6, 3) != -1)
	 	{
	 	  switch (opcion)
	 	    {
	 	    case 1:
	 	      printf ("\nNUMERO RUBRO\n-----------\n");

	 	     if (utn_getNumero ("Ingrese el numero de rubro a modificar: ", "\nError al ingresar. Por favor ", &auxEmployee.numeroRubro, 1, 1000, 5)!= 0)
	 	    	 	   	{
	 	    	 	   	  return -1;
	 	    	 	   	}
	 	      break;
	 	    case 2:
	 	      printf ("\nTEXTO AVISO\n-----------\n");
	 	     if (utn_getNombre ("Ingrese el texto del aviso a modificar: ", "\nError al ingresar.\n", auxEmployee.textoAviso, LONG_PUBLICACION, 5) != 0)
	 	   	{
	 	   	  return -1;
	 	   	}
	 	      break;
	 	    case 3:
	 	      printf ("\nID CLIENTE\n------------\n");
	 	     if (utn_getNumero ("Ingrese el id del cliente a modificar: ", "\nError al ingresar. Por favor ", &auxEmployee.idCliente, 1, 100, 5)!= 0)
	 	   	{
	 	   	  return -1;
	 	   	}
	 	      break;
	 	   case 4:
	 		 if(utn_getAceptaRechaza ("\nGrabar cambios? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
	 		   {
	 			publicacion_bufferToArray (list, &auxEmployee,  len, bufferID);
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
 * list     | se le pasa la lista de tipo Publicacion
 * len      | se le pasa la longitud de la lista
 * id       | se le pasa el id del publicacion
 *
 * Se encarga de eliminar una publicacion a la lista Publicacion
 *
 * */
int publicacion_removeArray(Publicacion* list, int len, int id)
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


int publicacion_prepareForDelete(Publicacion *list, int len)
{
  int retorno = -1;
  int bufferID;

  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese ID del la publicacion ", "\nError al ingresar. ", &bufferID, 1, QTY_PUBLICACION, 5);
      if (publicacion_findById (list, len, bufferID) != -1)
	{
    	  publicacion_printForId(list, len, bufferID);
	  retorno = utn_getAceptaRechaza ("\nAcepta eliminar la publicacion? s/n: ", "ERROR al ingresar opcion. \n", 's','n');
	  if (retorno == 1)
	    {
		  publicacion_removeArray(list, len, bufferID);
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
 * list     | se le pasa la lista de tipo Publicacion
 * len      | se le pasa la longitud de la lista
 * order    | se le pasa el valor para ordenar menor a 0 o mayor a 0 (-1 o 1)
 * Se encarga de agregar una publicacion a la lista Publicacion
 *
 * */
int publicacion_sortArray(Publicacion* list, int len, int order)
{
  int flagSwap;
  int i;
  int contador = 0;
  int retorno = -1;
  Publicacion buffer;
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
	      if ((
		      (((list[i].idCliente > list[i + 1].idCliente)&&(order == 1))
			  ||((list[i].idCliente < list[i + 1].idCliente) &&(order == 0)))))
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





int publicacion_flagLimite(Publicacion* list, int len)
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

