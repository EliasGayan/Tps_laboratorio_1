/*
 * menu.c
 *
 *  Created on: 26 abr. 2022
 *      Author: Elias
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "menu.h"
#include "input.h"


int menu()
{
	int opcion;
		printf("|-----------------------|\n");
		printf("         VUELOS         \n");
		printf("|-----------------------|\n");
		printf("|1. DAR DE ALTA         |\n");
		printf("|2. MODIFICAR           |\n");
		printf("|3. DAR DE BAJA         |\n");
		printf("|4. INFORMAR            |\n");
		printf("|5. CARGA FORZADA       |\n");
		printf("|6. SALIR DEL PROGRAMA  |\n");
		printf("|-----------------------|\n\n");
		printf("---------------------------\n");
		printf("Ingrese la opcion deseada: \n");
		printf("---------------------------\n");
		scanf("%d", &opcion);
		while(opcion < 0 || opcion > 7)
		{
			printf("ERROR, Reingrese una opcion valida");
			scanf("%d", &opcion);
		}
		return opcion;
}

