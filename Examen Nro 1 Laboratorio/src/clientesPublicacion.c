
#include "utn.h"
#include "Publicacion.h"
#include "CLientes.h"
#include <stdio.h>
#include <stdlib.h>


/*
 * listP     | se le pasa la lista de tipo Publicacion
 * listC     | se le pasa la lista de tipo Cliente
 *
 * Se encarga de calcular la cantidad de publicaciones activas por cliente
 *
 * */
int sumarActivosPublicacionesClientes(Publicacion* listP,Cliente* listC){

   int auxPubliActivas;
   for(int i = 0;i<QTY_CLIENTES;i++){
   auxPubliActivas =0;
            for(int j = 0 ; j<QTY_PUBLICACION;j++){

                     if(listP[j].idCliente == listC[i].id){
                         if(listP[j].valorEstadoPublicacion == 1 && listP[j].isEmpty == FALSE){
                                auxPubliActivas++;
                          }

                     }
            }
            listC[i].publicacionesActivas =auxPubliActivas;

   }

    return 0;

}
/*
 * listP     | se le pasa la lista de tipo Publicacion
 * listC     | se le pasa la lista de tipo Cliente
 * length    | se pasa la longitud de la lista
 *
 * Se encarga de calcular quien es el cliente con mas avisos
 *
 * */
int cliente_printArrayConPublicacion(Cliente* listC,Publicacion* listP, int length)
{
	int retorno = -1;
	sumarActivosPublicacionesClientes(listP, listC);
	if(listC != NULL && length > 0)
	{
		for(int i=0;i<length;i++)
		{
			if(listC[i].isEmpty == FALSE && listC[i].id !=0)
			{
				printf(" %-6d %-12s %-13s %-13s %-6d \n"
				 //   ,list[i].isEmpty
				    ,listC[i].id
				    ,listC[i].nombre
				    ,listC[i].apellido
				    ,listC[i].cuit
					,listC[i].publicacionesActivas);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/*
 * listP     | se le pasa la lista de tipo Publicacion
 * listC     | se le pasa la lista de tipo Cliente
 * salida    | se utiliza una variable puntero para devolver el "resultado"
 *
 * Se encarga de calcular quien es el cliente con mas avisos
 *
 * */
int CalcularAvisosClientes(Publicacion* listP,Cliente* listC,int *salida){

	  int flagAvisos = 0;
	  int masAvisos = 0;

	   for(int i = 0;i<QTY_CLIENTES;i++){

	            for(int j = 0 ; j<QTY_PUBLICACION;j++){

	            	if(flagAvisos==0){
	            		if(listC[i].publicacionesActivas > masAvisos){
	            		masAvisos = listC[i].publicacionesActivas;
	            		*salida = listC[i].id;
	            		}
	            		flagAvisos=1;
	            	}else{

	            		if(listC[i].publicacionesActivas > masAvisos){
	            		masAvisos = listC[i].publicacionesActivas;
	            		*salida = listC[i].id;
						}
	            	}
	          }
	   }

	    return 0;

}

/*
 * listP     | se le pasa la lista de tipo Publicacion
 * lenP      | se le pasa la longitud de respectiva lista
 * listC     | se le pasa la lista de tipo Cliente
 * lenC      | se le pasa la longitud de respectiva lista
 * id        | se le pasa el id de cliente
 *
 * Se encarga de mostrar todas las publicaciones asociadas con un cliente
 *
 * */
void publicacionesPorCLiente(Publicacion * listP, int lenP,Cliente * listC, int lenC, int id)
{
    int i;
    int j;
    publicacion_headerArray();
    for(i=0;i<lenC; i++)
    {
        if(listC[i].id == id && listC[i].isEmpty==FALSE )
        {
            for(j=0;j<lenP;j++)
            {
                if(listP[j].idCliente == listC[i].id && listP[j].isEmpty == FALSE )
                {
                    publicacion_printForIdSinHeader(listP, lenP, listP[j].id);
                }
            }
        }
    }
}

/*
 * listP     | se le pasa la lista de tipo Publicacion
 * lenP      | se le pasa la longitud de respectiva lista
 * listC     | se le pasa la lista de tipo Cliente
 * lenC      | se le pasa la longitud de respectiva lista
 * id        | se le pasa el id de cliente
 *
 * Se encarga de borrar las publicaciones asociadas a un cliente
 *
 * */
void publicacionesPorCLienteABorrar(Publicacion * listP, int lenP,Cliente * listC, int lenC, int id)
{
    int i;
    int j;
    publicacion_headerArray();
    for(i=0;i<lenC; i++)
    {
        if(listC[i].id == id && listC[i].isEmpty==FALSE )
        {
            for(j=0;j<lenP;j++)
            {
                if(listP[j].idCliente == listC[i].id && listP[j].isEmpty == FALSE )
                {
                    publicacion_removeArray( listP, lenP, listP[j].id);
                }
            }
        }
    }
}


/*
 * listP     | se le pasa la lista de tipo Publicacion
 * salida    | se utiliza una variable puntero para devolver el "resultado"
 *
 * Se encarga de calcular el rubro con mas avisos
 *
 * */
int CalcularRubrosPublicaciones(Publicacion* listP,int *salida){

	int retorno = -1;
	int contador;
	int rubroMax = 0;
	int rubroAMostrar=0;
		for (int i = 0 ; i<QTY_PUBLICACION; i++)
		{

			contador=0;
			for (int j = 0;j<QTY_PUBLICACION;j++)
			{
				if(listP[j].numeroRubro == i && listP[j].isEmpty==FALSE && listP[j].valorEstadoPublicacion == 1)
				{
					contador++;
				}
			}
			if (contador > rubroMax)
			{
				rubroAMostrar = i;
				rubroMax = contador;
			}

	}
		*salida = rubroAMostrar;

	return retorno;
}
/*
 * listP     | se le pasa la lista de tipo Publicacion
 * lenP      | se le pasa la longitud de respectiva lista
 * listC     | se le pasa la lista de tipo Cliente
 * lenC      | se le pasa la longitud de respectiva lista
 *
 * Se encarga de borrar en "casacada" lo que seria un cliente y con el sus publicaciones
 *
 * */
int borradoCLientePublicacion(Publicacion * listP, int lenP,Cliente * listC, int lenC)
{
    int retorno = -1;
    int idAux;

    if (listP != NULL && lenP > 0 && listC != NULL && lenC>0)
    {


         cliente_headerArray();
         cliente_printArrayConPublicacion(listC,listP, QTY_CLIENTES);



        if(utn_getNumero ("Ingrese id del Cliente: ", "\nError al ingresar. Por favor ",&idAux, 0, 999, 5)!= -1)
        {


            printf("\nIMRPIME EL VALOR INGRESADO: %d\n",idAux);


                publicacionesPorCLiente(listP,lenP,listC,lenC, idAux);

                if (utn_getAceptaRechaza ("\nAcepta que se eliminen todos los datos? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
                {

                    publicacionesPorCLienteABorrar(listP,lenP,listC, lenC,  idAux);

                    cliente_removeArray(listC,lenC, idAux);

                     return EXIT_SUCCESS;
                    }
                    else
                    {
                        printf("\n ERROR - No ingreso s / n (case sensitive)");
                    }
                }

        }

    return retorno;
}



/*
 * listP         | se le pasa la lista de tipo Publicacion
 * listC         | se le pasa la lista de tipo Cliente
 * idPublicacion | se le pasa el id de la publicacion a pausar
 *
 * Se encarga de pausar una publicacion en base a su id
 *
 * */
int PausarClientePublicacion(Publicacion* listP,Cliente* listC,int idPublicacion){

	for(int i = 0; i<QTY_CLIENTES;i++){

		if(listP[i].id == idPublicacion){

			if(listP[i].idCliente == listC[i].id){

				cliente_printForId(listC, QTY_CLIENTES, listC[i].id);
				switch (utn_getAceptaRechaza ("\nDesea pausar la publicacion? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')){

					case -1:
						return -1;
						break;

					case 1:
						printf("%s",listP[i].estado);
						listP[i].valorEstadoPublicacion = 0;

						publicacion_printForId(listP, QTY_PUBLICACION, idPublicacion);
						break;
				}
			}
		}
	}

	return 0;
}
/*
 * listP         | se le pasa la lista de tipo Publicacion
 * listC         | se le pasa la lista de tipo Cliente
 * idPublicacion | se le pasa el id de la publicacion a pausar
 *
 * Se encarga de reanudar una publicacion en base a su id
 *
 * */
int ReanudarClientePublicacion(Publicacion* listP,Cliente* listC,int idPublicacion){

	for(int i = 0; i<QTY_CLIENTES;i++){

		if(listP[i].id == idPublicacion){

			if(listP[i].idCliente == listC[i].id){

				//CalcularAvisosClientes(listP, listC, listC[i].publicacionesActivas);
				cliente_printForId(listC, QTY_CLIENTES, listC[i].id);
				switch (utn_getAceptaRechaza ("\nDesea reanudar la publicacion? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')){

					case -1:
						return -1;
						break;

					case 1:

						listP[i].valorEstadoPublicacion = 1;
					//	CalcularAvisosClientes(listP, listC, listC[i].publicacionesActivas);
						publicacion_printForId(listP, QTY_PUBLICACION, idPublicacion);
						break;
				}
			}
		}
	}

	return 0;
}



/*
 * listP     | se le pasa la lista de tipo Publicacion
 * salida    | se utiliza una variable puntero para devolver el "resultado"
 *
 * Se encarga de sumar la cantidad de publicaciones pausadas
 *
 * */
int sumarPausadosPublicacionesClientes(Publicacion* listP,int *salida){
	int contador = 0;
    for(int j = 0 ; j < QTY_PUBLICACION;j++){

		 if(listP[j].valorEstadoPublicacion != 1  && listP[j].isEmpty == FALSE ){
				contador++;
		  }
    }
    *salida = contador;
    return 0;
}


