/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */

#include "hardCodeCliente.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <conio.h>
#include "Clientes.h"



void cliente_HardcodDatosArray(Cliente list[], int len)
{
    int i;

    int idCliente[QTY_CLIENTES] = {1,2,3,4,5};/////////NO TOCAR////////
    int estadoCleinte[QTY_CLIENTES]= {FALSE,FALSE,FALSE,FALSE,FALSE};/////////NO TOCAR////////
    char nombre_Cliente[QTY_CLIENTES][LONG_NAME_CLIENTES]= {"Leandro","Nicolas","Pedro","Juan","Marcelo"};
    char apellido_Cliente[QTY_CLIENTES][LONG_NAME_CLIENTES]= {"Varela gomez","E_Dominguez","C_Gonzalez","Z_Dominguez","E_Dominguez"};
    char cuit [QTY_CLIENTES][LONG_NAME_CLIENTES] = {"0323205109","20323205119","20323205129","20323205139","20323205149"};


    for(i=0; i<len; i++)
        {
            list[i].id = idCliente[i];/////////NO TOCAR////////
            list[i].isEmpty = estadoCleinte[i];/////////NO TOCAR////////
            strcpy(list[i].nombre, nombre_Cliente[i]);
            strcpy(list[i].apellido, apellido_Cliente[i]);
            strcpy(list[i].cuit , cuit[i]);


        }
}
