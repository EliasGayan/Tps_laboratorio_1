/*
 * nexo.c
 *
 *  Created on: 12 may. 2022
 *      Author: Elias
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nexo.h"
#include "input.h"
#include "ArrayPassenger.h"

/*-------------------------------------------------------------------------------------------------------------------------------*/
int Harcodeo(Passenger* list, int tamList, int* id, int* contador)
{
	int rtn =-1;

	Passenger eHarcodeo[] = {{0, "Elias", "Gayan", 330000, "SAP", 5, 1, 0},
							{0, "Mauricio", "Vicente", 500000, "MINER", 1, 1, 0},
							{0, "Joaquin", "Rodriguez", 1295000, "BSAS", 8, 1, 0},
							{0, "Carlos", "Lorendo", 970450, "PILL", 8, 1, 0},
							{0, "maximiliano", "Etche", 32500, "FLYING", 3, 1, 0},
							{0, "Federico", "Ramos", 98555, "SOPW", 2, 1, 0},
							{0, "Victor", "Estigarribia", 10000, "THC", 7, 1, 0},
							{0, "Franco", "Caelo", 46700, "NASA", 9, 1, 0},
							{0, "Mariana", "Perez", 250000, "CBD", 4, 1, 0},
							{0, "Sofia", "Micrus", 487710, "LEMON", 9, 1, 0}
	    };

	if(list != NULL && tamList > 0 && id != NULL)
	{
		for(int i=0; i<10; i++)
		{
			list[i] = eHarcodeo[i];
			list[i].id = *id;
			*id = *id + 1;
			*contador = *contador + 1;
		}
		rtn=0;
	}
	return rtn;
}

/*-------------------------------------------------------------------------------------------------------------------------------*/

int AgregarPassenger(Passenger* list, int tamList, int* id)
{
	int rtn = -1;

	char nombre[51];
	char apellido[51];
	float precio=0;
	char flyCode[10];
	int tipoPasajero=0;

	if(list != NULL && tamList > 0 && id != NULL)
	{
		getString(nombre,"Ingrese el Nombre: \n", "error\n", 51);
		getString(apellido,"Ingrese el apellido: \n", "error\n", 51);
		getFloat("Ingrese el precio: \n", &precio);
		getString(flyCode,"Ingrese el flycode: \n", "error\n", 51);
		getInt("Ingrese el Tipo de Pasajero: \n", &tipoPasajero);


		addPassenger(list, tamList, *id, nombre, apellido, precio, tipoPasajero, flyCode);

		*id = *id +1;



		printf("Se ha ingresado con Exito!!\n");
		rtn = 0;
	}

	return rtn;
}

/*-------------------------------------------------------------------------------------------------------------------------------*/

int EliminarPassenger(Passenger* list, int tamList)
{
	int rtn=-1;
	int flag = -1;
	int id;

	if(list!=NULL && tamList > 0)
	{
		printPassenger(list, tamList);
		printf("Ingrese el ID que desea eliminar: \n");
		scanf("%d", &id);
		flag = removePassenger(list, tamList, id);

		if(flag!=0)
		{
			printf("El ID ingresado no existe\n");
		}
		else
		{
			printf("El ID ingresado se ha Eliminado correctamente\n");
		}

		rtn=0;
	}

	return rtn;
}

/*-------------------------------------------------------------------------------------------------------------------------------*/

int ModificarPassenger(Passenger* list, int tamList)
{
	int rtn = -1;
	int modificar;
	int id;
	int i;
	Passenger nuevoPasajero;

	if(list != NULL && tamList > 0)
	{
		printPassenger(list, tamList);
		getInt("¿Que Id de pasajero desea modificar?\n", &id);
		i = findPassengerById(list, tamList, id);

		if(i > -1)
		{
		    nuevoPasajero = list[i];
			getInt("Para modificar:\n1. NOMBRE\n2. APELLIDO\n3. PRECIO\n4. CODIGO DE VUELO\n5. TIPO DE PASAJERO\n", &modificar);

			switch(modificar)
			{

				case 1:
					getString(nuevoPasajero.name,"Ingrese el Nombre a modificar: \n", "ERROR, Reingrese nuevamente el nombre:\n", 15);
				break;

				case 2:
					getString(nuevoPasajero.lastName,"Ingrese el apellido a modificar: \n", "ERROR, Reingrese nuevamente el apellido:\n", 15);
				break;

				case 3:
					getFloat("Ingrese el precio a modificar: \n", &nuevoPasajero.price);
				break;

				case 4:
					getString(nuevoPasajero.flyCode,"Ingrese el codigo de vuelo a modificar: \n", "ERROR, Reingrese nuevamente el codigo de vuelo:\n", 10);
				break;

				case 5:
					getInt("Ingrese el Tipo de Pasajero a modificar: \n", &nuevoPasajero.typePassenger);
				break;
			}

			list[i] = nuevoPasajero;
			rtn=0;
		}
		else
		{
			printf("NO SE HA ENCONTRADO NINGUN PASAJERO PARA SER MODIFICADO\n");
		}

	}

	return rtn;
}

/*-------------------------------------------------------------------------------------------------------------------------------*/

int SubMenuOrdenamientoByName(Passenger* list, int tamList, int opcion)
{
    int rtn = -1;

    if(list != NULL && tamList > 0)
    {
        printf("INGRESE 0 PARA ORDENAR ASCENDENTE\n");
        printf("INGRESE 1 PARA ORDENAR DESCENDENTE\n");
        printf("OPCION: \n");
        scanf("%d", &opcion);

        sortPassengersByName(list, tamList, opcion);
        rtn=0;
    }

    while(opcion < 0 || opcion > 1)
    {
        printf("ERROR, Reingrese nuevamente, (0 ASCENDENTE o 1 DESCENDENTE)\n");
        scanf("%d", &opcion);
    }
    return rtn;
}

/*-------------------------------------------------------------------------------------------------------------------------------*/

int SubMenuOrdenamientoByCode(Passenger* list, int tamList, int opcion)
{
    int rtn = -1;

    if(list != NULL && tamList > 0)
    {
        printf("INGRESE 0 PARA ORDENAR ASCENDENTE\n");
        printf("INGRESE 1 PARA ORDENAR DESCENDENTE\n");
        printf("OPCION: \n");
        scanf("%d", &opcion);

        sortPassengersByCode(list, tamList, opcion);
        rtn=0;
    }

    while(opcion < 0 || opcion > 1)
    {
        printf("ERROR, Reingrese nuevamente, (0 ASCENDENTE o 1 DESCENDENTE)\n");
        scanf("%d", &opcion);
    }
    return rtn;
}
//Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.


int SubMenuInformePromedio(Passenger* list, int tamList)
{
	int rtn = -1;
	float promedio;
	float total;
	int promedioSuperado;
	if(list != NULL && tamList > 0)
	{

			PromedioPrecios(list, tamList, &promedio, &promedioSuperado, &total);
			printf("EL PROMEDIO DE LOS PASAJES ES: %.2f\n", promedio);
			printf("La cantidad de pasajeros que superan el precio promedio son: %d\n", promedioSuperado);
			printf("El precio total es: %.2f\n", total);

	}

	return rtn;
}


int PromedioPrecios(Passenger* list, int tamList, float* promedio, int* contador, float* total)
{
	int rtn = -1;
	float prom;
	float suma=0;
	int cont=0;
	int contSuperado=0;
	if(list != NULL && tamList > 0)
	{
		for(int i=0; i<tamList; i++)
		{
			if(list[i].isEmpty == 0)
			{
				cont++;
				suma = suma + list[i].price;
			}
		}
		prom = (float) suma / cont;

			for(int i = 0; i<tamList;i++)
			{
				if(list[i].isEmpty == 0 && list[i].price > prom)
				{
					contSuperado++;
				}
			}
			*promedio = prom;
			*contador = contSuperado;
			*total = suma;


	}
	return rtn;
}




















/*-------------------------------------------------------------------------------------------------------------------------------*/

