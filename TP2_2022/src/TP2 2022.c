/*
 ============================================================================
 Name        : TP2.c
 Author      : ELIAS GAYAN
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "menu.h"
#include "input.h"
#include "nexo.h"
#define TAM 2000
#define ORDENASC 0
#define ORDENDES 1

int main(void)
{
	setbuf(stdout, NULL);

	Passenger arrayPassenger[TAM];
	int opcion=0;
	int contadorPassenger=0;
	int id=0;
	int respuesta;

	initPassengers(arrayPassenger, TAM);

	do{
		opcion = menu();
		switch(opcion)
		{
		case 1:
			if(contadorPassenger < TAM)
			{

				AgregarPassenger(arrayPassenger, TAM, &id);
				contadorPassenger++;
			}
			else
			{
				printf("ERROR, se ha alcanzado la cantidad de maxima de pasajeros.\n");
			}

		break;

		case 2:

			if(contadorPassenger > 0)
			{
				ModificarPassenger(arrayPassenger, TAM);
			}

		break;

		case 3:
			if(contadorPassenger > 0)
			{
				EliminarPassenger(arrayPassenger, TAM);
			}
			break;

		case 4:

			if(contadorPassenger > 0)
			{
				getInt("\n1.ORDENAR POR APELLIDO Y TIPO\n2.INFORMAR CALCULOS\n3.ORDENAR POR CODIGO DE VUELO Y ESTADO\nIngrese opcion: ", &respuesta);
				switch(respuesta)
				{
					case 1:
						SubMenuOrdenamientoByName(arrayPassenger, TAM, ORDENASC);
						printPassenger(arrayPassenger, TAM);
						break;
					case 2:
						SubMenuInformePromedio(arrayPassenger, TAM);
						break;
					case 3:
						SubMenuOrdenamientoByCode(arrayPassenger, TAM, ORDENDES);
						printPassenger(arrayPassenger, TAM);
						break;
				}

			}
			else
			{
				printf("NO SE HAN CARGADO PASAJEROS\n");
			}
		break;

		case 5:
		    	Harcodeo(arrayPassenger, TAM, &id, &contadorPassenger);
		    	printPassenger(arrayPassenger, TAM);

		    break;

		}


	}while(opcion != 6);

    printf("¡¡HA SALIDO DEL PROGRAMA EXITOSAMENTE!!\n");

    return EXIT_SUCCESS;
}

