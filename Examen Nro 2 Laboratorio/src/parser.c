#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "cliente.h"
#include "ventas.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile -> puntero al file
 * \param pArrayListEnvios LinkedList* -> puntero al array
 * \return int
 *
 */


int parser_clientesFromText(FILE* pFile , LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	int r;
	char var[64],var2[128],var3[128],var4[128];
	if (pArrayListEnvios!=NULL && pFile!=NULL)
	{
		do
		{
		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",var,var2,var3,var4);
		if (r==4)
			{
				Cliente * clienteAux= cliente_new();
				if (clienteAux!=NULL)
				{
				clienteAux=cliente_newParam(atoi(var),var2,var3,var4);
				if (clienteAux!=NULL)
				{
				ll_add(pArrayListEnvios, clienteAux);
				retorno=0;
				}

				}
				else
				{
					printf("error\n");
					retorno=-1;
				}

			}

		} while (!feof(pFile));
	fclose(pFile);
	}
	else
	{
		printf("\n No se encontro el archivo");
	}

	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile -> puntero al file
 * \param pArrayListVentas LinkedList* -> puntero al array
 * \return int
 *
 */


int parser_ventasFromText(FILE* pFile , LinkedList* pArrayListVentas)
{
	int retorno = -1;
	int r;

	char var[64],var2[128],var3[128],var4[128],var5[128],var6[128];
	if (pArrayListVentas!=NULL && pFile!=NULL)
	{
		do
		{
		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]",var,var2,var3,var4,var5,var6);
		if (r==6)
			{
				Ventas * ventasAux= ventas_new();
				if (ventasAux!=NULL)
				{
					ventasAux = ventas_newParam(atoi(var),atoi(var2), atoi(var3),var4 , atoi(var5),atoi(var6));
				    if (ventasAux!=NULL)
				    {
					ll_add(pArrayListVentas, ventasAux);
					retorno=0;
					}

				}
				else
				{
					printf("error\n");
					retorno=-1;
				}

			}

		} while (!feof(pFile));
	fclose(pFile);
	}
	else
	{
		printf("\n No se encontro el archivo");
	}

	return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
		Cliente* auxPEmployee;
		Cliente auxEmployee;
		char auxiliarId[4096];
		char auxiliarNombre[4096];
		char auxiliarApellido[4096];
		char auxiliarCuit[4096];
		int contadorEmployee=0;

		if(pFile != NULL && pArrayListEmployee != NULL)
		{
			if(pFile != NULL)
			{

				do
				{
					if(fread(&auxEmployee,sizeof(Cliente),1, pFile)==1)
					{
		                sprintf(auxiliarId, "%d", auxEmployee.idCliente);
		                strcpy(auxiliarNombre, auxEmployee.nombreCliente);
		                strcpy(auxiliarApellido, auxEmployee.apellidoCliente);
		                strcpy(auxiliarCuit, auxEmployee.cuitCliente);

						if(cliente_newParamTxt(auxiliarId,auxiliarNombre,auxiliarApellido,auxiliarCuit) >= 0)
						{
							auxPEmployee = (Cliente*) cliente_newParamTxt(auxiliarId,auxiliarNombre,auxiliarApellido,auxiliarCuit);
							if(ll_add(pArrayListEmployee,auxPEmployee)==0)
							{
								retorno = 0;
								contadorEmployee++;
							}

						}
					}
				}while(!feof(pFile));
			}
		}
		printf("Se cargaron %d empleados\n",contadorEmployee);
		return retorno;
}





