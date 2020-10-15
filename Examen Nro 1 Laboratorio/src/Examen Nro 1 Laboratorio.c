/*
 *  Created on: 26 sep. 2020
 *  Author: Leandro varela gomez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "Clientes.h"
#include "Publicacion.h"
#include "utn.h"
#include "clientesPublicacion.h"
#include "hardCodeCliente.h"
#include "hardCodePublicidad.h"



int main(void) {
setbuf(stdout,NULL);
int opcion;
int opcion2;
int opcion3;
int idPublicacion;
int mayorAvisos = 0;
int mayorRubros = 0;
int cantidadAvisosPausados = 0;

Cliente List[QTY_CLIENTES];
cliente_initArray(List, QTY_CLIENTES);
cliente_HardcodDatosArray(List, QTY_CLIENTES);

Publicacion ListP[QTY_PUBLICACION];
publicacion_initArray(ListP, QTY_PUBLICACION);
publicacion_hardcodDatosArray(ListP, QTY_PUBLICACION);
do{

	 printf ("\n---------------"
				  "\n* MENU  *"
				  "\n*********"
				  "\n1-Menu Cliente\n"
				  "2-Menu Publicacion\n"
				  "3-Salir\n\n");
	 if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion2, 1, 5, 3) != -1){

		 switch(opcion2){


		 	 case 1:

			  do
				{
				  printf ("\n---------------"
					  "\n* MENU  *"
					  "\n*********"
					  "\n1-Alta\n"
					  "2-Modificacion\n"
					  "3-Baja\n"
					  "4-Informar\n"
					  "5-Salir\n\n");


				  if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 5, 3) != -1)
				{
				  switch (opcion)
					{
					case 1:

					  if (cliente_flagLimite(List, QTY_CLIENTES) != -1)
					{
					  if (cliente_searchFree (List, QTY_CLIENTES) == TRUE)
						{
						  printf ("\n------------------------------------------------------");
						  printf ("\n------------------      ALTA CLIENTE    --------------------\n");
						  printf ("------------------------------------------------------\n");
						  if (cliente_chargeArray (List, QTY_CLIENTES) != 0)
						{
						  printf ("\n-----------------------------\n");
						  printf ("\nSE TERMINARON LOS REINTENTOS!\n");
						  printf ("\n-----------------------------\n");
						}
						}
					}
					  else
					{
					  printf ("\n-------------------------------------------\n");
					  printf ("\nLA CANTIDAD DE EMPLEADOS LLEGO A SU LIMITE!\n");
					  printf ("\n-------------------------------------------\n");
					}


					  break;
					case 2:
					  if (cliente_flagLimite (List, QTY_CLIENTES) != 0)
					{
					  printf ("\n-----------------------------------------------------");
					  printf ("\n------------------    MODIFICAR CLIENTE   ------------------\n");
					  printf ("-----------------------------------------------------\n");
					  if (cliente_updateArray (List, QTY_CLIENTES) != 0)
						{
						  printf ("\n******\n");
						  printf ("\nERROR!\n");
						  printf ("\n******\n");
						}
					}
					  else
					{
					  printf ("\n--------------------------------------------\n");
					  printf ("\nNO HAY CLIENTES CARGADOS PARA MODIFICAR!\n");
					  printf ("\n--------------------------------------------\n");

					}

					  break;
					case 3:
					  if (cliente_flagLimite (List, QTY_CLIENTES) != 0)
						{
					  printf ("\n-----------------------------------------------------\n");
					  printf ("\n--------------------     BAJA CLIENTE   ---------------------\n");
					  printf ("\n-----------------------------------------------------\n");
					  borradoCLientePublicacion(ListP, QTY_PUBLICACION, List, QTY_CLIENTES);

						}
					  else
							{
					  printf ("\n----------------------------------------\n");
					  printf ("\nNO HAY CLIENTES CARGADOS PARA ELIMINAR!\n");
					  printf ("\n----------------------------------------\n");
							}
					  break;
					case 4:
					  if (cliente_flagLimite (List, QTY_CLIENTES) != 0)
						{
					 printf ("\n------------------------------------------------------");
					 printf ("\n------------------    INFORMAR CLIENTES    --------------------\n");
					 printf ("-----------------------------------------------------\n");
					  if(cliente_sortArray(List, QTY_CLIENTES, 1) == -1)
					{
					  printf ("\n******\n");
					  printf ("\nERROR!\n");
					  printf ("\n******\n");
					}
					  cliente_headerArray();
					  cliente_printArray(List, QTY_CLIENTES);

					  printf ("\n------------------------------------------------------\n");
						}
					  else
						{
					  printf ("\n------------------------------------\n");
					  printf ("\nNO HAY EMPLEADOS CARGADOS PARA MOSTRAR!\n");
					  printf ("\n------------------------------------\n");
						}
					  break;
					case 5:
					  printf("\nEL RPOGRAMA SE CERRO CON EXITO!\n");

					  break;
					default:
					  break;
					}
				}
				  else
				{
				  printf ("\n------------------------------------\n");
				  printf ("\nSE TERMINARON LOS REINTENTOS!\n");
				  printf ("\n------------------------------------\n");

				  //return EXIT_SUCCESS;
				}
				}
			  while (opcion != 5);


			  break;


		 	 case 2:

		 		do
					{
					  printf ("\n---------------"
						  "\n* MENU  *"
						  "\n*********"
						  "\n1-Publicar\n"
						  "2-Modificacion\n"
						  "3-Baja\n"
						  "4-Informar\n"
						  "5-Pausar publicacion\n"
						  "6-Reanudar publicacion\n"
						  "7-Imprimir Clientes\n"
						  "8-Salir\n\n");


					  if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 8, 3) != -1)
					{
					  switch (opcion)
						{
						case 1:

						  if (publicacion_flagLimite(ListP	, QTY_PUBLICACION) != -1)
						{
						  if (publicacion_searchFree (ListP, QTY_PUBLICACION) == TRUE)
							{
							  printf ("\n------------------------------------------------------");
							  printf ("\n------------------      PUBLICAR   --------------------\n");
							  printf ("------------------------------------------------------\n");
							  if (publicacion_chargeArray (ListP,List, QTY_PUBLICACION) != 1)
							{
							  printf ("\n-----------------------------\n");
							  printf ("\nSE TERMINARON LOS REINTENTOS!\n");
							  printf ("\n-----------------------------\n");
							}


							}
						}
						  else
						{
						  printf ("\n-------------------------------------------\n");
						  printf ("\nLA CANTIDAD DE PUBLICACIONES LLEGO A SU LIMITE!\n");
						  printf ("\n-------------------------------------------\n");
						}

						  break;
						case 2:
						  if (publicacion_flagLimite (ListP, QTY_PUBLICACION) != 0)
						{
						  printf ("\n-----------------------------------------------------");
						  printf ("\n------------------    MODIFICAR PUBLICACION    ------------------\n");
						 printf ("-----------------------------------------------------\n");
						  if (publicacion_updateArray (ListP, QTY_PUBLICACION) != 0)
							{
							  printf ("\n******\n");
							  printf ("\nERROR!\n");
							  printf ("\n******\n");
							}
						}
						  else
						{
						  printf ("\n--------------------------------------------\n");
						  printf ("\nNO HAY PUBLICACIONES CARGADOS PARA MODIFICAR!\n");
						  printf ("\n--------------------------------------------\n");

						}

						  break;
						case 3:
						  if (publicacion_flagLimite (ListP, QTY_PUBLICACION) != 0)
							{
						  printf ("\n-----------------------------------------------------\n");
						  printf ("\n--------------------     BAJA PUBLICACION    ---------------------\n");
						  printf ("\n-----------------------------------------------------\n");
						  if(publicacion_prepareForDelete(ListP,QTY_PUBLICACION)==-1)
						{
						  printf ("\n******\n");
						  printf ("\nERROR!\n");
						  printf ("\n******\n");
						}
							}
						  else
								{
						  printf ("\n----------------------------------------\n");
						  printf ("\nNO HAY PUBLICACIONES CARGADOS PARA ELIMINAR!\n");
						  printf ("\n----------------------------------------\n");
								}
						  break;
						case 4:
						  if (publicacion_flagLimite (ListP, QTY_PUBLICACION) != 0)
							{
						 printf ("\n------------------------------------------------------");
						 printf ("\n------------------    INFORMAR PUBLICACION   --------------------\n");
						 printf ("-----------------------------------------------------\n");
						  if(publicacion_sortArray(ListP, QTY_PUBLICACION, 1) == -1)
						{
						  printf ("\n******\n");
						  printf ("\nERROR!\n");
						  printf ("\n******\n");
						}
						  publicacion_headerArray();
						  publicacion_printArray(ListP, QTY_PUBLICACION);

						  printf ("\n------------------------------------------------------\n");
							}
						  else
							{
						  printf ("\n------------------------------------\n");
						  printf ("\nNO HAY PUBLICACIONES CARGADOS PARA MOSTRAR!\n");
						  printf ("\n------------------------------------\n");
							}
						  break;


						case 5:

							 printf ("\n------------------------------------------------------");
							 printf ("\n-----------    PAUSAR PUBLICACION    --------------\n");
							 printf ("-----------------------------------------------------\n");

							 utn_getNumero ("\nPor favor ingrese el id de la publicacion a pausar: ","\nOpcion Invalida. ", &idPublicacion, 1, 1000, 3);
							 PausarClientePublicacion(ListP, List,idPublicacion );

							break;


						case 6:


							printf ("\n------------------------------------------------------");
							printf ("\n------------    REANUDAR PUBLICACION    -------------\n");
							printf ("-----------------------------------------------------\n");

							utn_getNumero ("\nPor favor ingrese el id de la publicacion a reanudar: ","\nOpcion Invalida. ", &idPublicacion, 1, 1000, 3);
							ReanudarClientePublicacion(ListP, List, idPublicacion);
							break;


						case 7:

							printf ("\n------------------------------------------------------");
							printf ("\n------------    IMPRIMIR CLIENTES    -------------\n");
							printf ("-----------------------------------------------------\n");

							sumarActivosPublicacionesClientes(ListP, List);
							cliente_headerArray();
							cliente_printArray(List, QTY_CLIENTES);


							do{

								printf ("\n---------------"
								  "\n* MENU  *"
								  "\n*********"
								  "\n1-Cliente con más avisos\n"
								  "2- Cantidad de avisos pausados\n"
								  "3-Rubro con mas avisos\n"
								  "4-Salir\n\n");

								if(utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion3, 1, 4, 3) != -1){


									switch(opcion3){


										case 1:

											CalcularAvisosClientes(ListP, List, &mayorAvisos);
											printf("%s","Cliente con más avisos\n");
											printf("%-28d",mayorAvisos);
											break;

										case 2:

											sumarPausadosPublicacionesClientes(ListP,&cantidadAvisosPausados);
											printf("%s","Cantidad de avisos pausados\n");
											printf(" %-30d",cantidadAvisosPausados);
											break;

										case 3:

											CalcularRubrosPublicaciones(ListP, &mayorRubros);
											printf("%s","Rubro con mas avisos\n");
											printf("%-12d",mayorRubros);
											break;

										case 4:

											printf("\nEL RPOGRAMA SE CERRO CON EXITO!\n");
											break;

									}
								}
							}
							 while (opcion3 != 4);

							break;

						case 8:
						  printf("\nEL PROGRAMA SE CERRO CON EXITO!\n");

						  break;
						default:
						  break;
						}
					}
					  else
					{
					  printf ("\n------------------------------------\n");
					  printf ("\nSE TERMINARON LOS REINTENTOS!\n");
					  printf ("\n------------------------------------\n");

					  //return EXIT_SUCCESS;
					}
					}
				  while (opcion != 8);


		 		 break;

		 }


	 }

}
while (opcion != 3);


	return EXIT_SUCCESS;
}
