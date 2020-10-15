/*
 ============================================================================
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */

#include "hardCodePublicidad.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <conio.h>
#include "Publicacion.h"



void publicacion_hardcodDatosArray(Publicacion* list, int len)
{
    int i;
    int idPublicacion[QTY_PUBLICACION] = {1,2,3,4,5};/////////NO TOCAR////////
    int isEmpty[QTY_PUBLICACION]= {FALSE,FALSE,FALSE,FALSE,FALSE};/////////NO TOCAR////////
    int idCliente[QTY_PUBLICACION] = {1,1,2,3,3};/////////NO TOCAR////////
    char texto[QTY_PUBLICACION][LONG_NAME_PUBLICACION]= {"Neumatico para coches","Venta de Barbijos","Sepelios","Venta de sarlanga","Mecanico MARCELO"};
    int numeroRubro[QTY_PUBLICACION] = {9,8,15,8,5};
    int estadoPublicacion[QTY_PUBLICACION] = {ACTIVO,ACTIVO,ACTIVO,PAUSADO,PAUSADO};
    char descripcionestadoPublicacion[QTY_PUBLICACION][10] = {"ACTIVA","ACTIVA","ACTIVA","ACTIVA","ACTIVA"};



    for(i=0; i<(len-995); i++)
        {

            list[i].id = idPublicacion[i];/////////NO TOCAR////////
            list[i].isEmpty = isEmpty[i];/////////NO TOCAR////////
            list[i].idCliente = idCliente[i];
            strcpy(list[i].textoAviso, texto[i]);
            list[i].numeroRubro = numeroRubro[i];
            list[i].valorEstadoPublicacion = estadoPublicacion[i];
            strcpy(list[i].estado, descripcionestadoPublicacion[i]);




        }
}
