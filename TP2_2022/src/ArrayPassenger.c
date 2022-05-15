/*
 * ArrayPassenger.c
 *
 *  Created on: 25 abr. 2022
 *      Author: Elias
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "ArrayPassenger.h"

/*-----------------------------------------------------------------------------------------------------------------------------*/

int initPassengers(Passenger* list, int len)
{
	int rtn = -1;

	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			list[i].id = -1;
			list[i].isEmpty = 1;
		}
		rtn = 0;
	}

	return rtn;
}

/*-------------------------------------------------------------------------------------------------------------------------------*/

int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[])
{
	int rtn = -1;
	//int contador;

	if(list != NULL && len > 0 && name != NULL && lastName != NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				list[i].id = id;
				list[i].price = price;
				list[i].typePassenger = typePassenger;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				strcpy(list[i].flyCode, flyCode);
				list[i].isEmpty = 0;
/*
				list[i].id = id;//ta mal//ignorar
				contador = id;
				contador += 1;*/
				rtn = 0;
				break;
			}


		}

	}

	return rtn;
}

/*-------------------------------------------------------------------------------------------------------------------------------*/

int findPassengerById(Passenger* list, int len, int id)
{
	int rtn = -1;

	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].id == id && list[i].isEmpty == 0)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

/*-------------------------------------------------------------------------------------------------------------------------------*/

int removePassenger(Passenger* list, int len, int id)
{
	int rtn = -1;

	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].id == id && list[i].isEmpty==0)
			{
				list[i].isEmpty = 1;
				rtn=0;
				break;
			}
		}
	}

	return rtn;
}

/*-------------------------------------------------------------------------------------------------------------------------------*/

int sortPassengersByName(Passenger* list, int len, int order)
{
	int rtn = -1;
	Passenger aux;


	if(list != NULL && len > 0)
	{

	    switch(order)
	    {
        case 0:
            for(int i=0; i<len-1; i++)
            {
                for(int j=i+1; j<len; j++)

                {
                    if(list[i].isEmpty==0 && list[j].isEmpty==0)
                    {
                        if((list[i].typePassenger == list[j].typePassenger && strcmp(list[i].lastName, list[j].lastName)==1)
                           || list[i].typePassenger > list[j].typePassenger)
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                    }
                }
            }
            rtn = 0;
            break;

        case 1:
            for(int i=0; i<len-1; i++)
            {
                for(int j=i+1; j<len; j++)
                {
                    if(list[i].isEmpty==0 && list[j].isEmpty==0)
                    {
                        if((list[i].typePassenger == list[j].typePassenger && strcmp(list[i].lastName, list[j].lastName)==-1)
                           || list[i].typePassenger < list[j].typePassenger)
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                    }
                }
            }
            break;
	    }
	}

	return rtn;
}

/*-------------------------------------------------------------------------------------------------------------------------------*/

int sortPassengersByCode(Passenger* list, int len, int order)
{
    int rtn=-1;
    Passenger aux;


    if(list != NULL && len > 0)
    {
        switch(order)
        {
        case 0:
            for(int i=0; i < len-1; i++)
            {
                for(int j=i+1; j<len; j++)
                {
                    if(list[i].isEmpty==0 && list[j].isEmpty==0)
                    {
                        if((list[i].statusFlight == list[j].statusFlight && strcmp(list[i].flyCode, list[j].flyCode)==1)
                           || list[i].statusFlight > list[j].statusFlight)
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                    }
                }
            }
            rtn=0;
        break;

        case 1:
            for(int i=0; i < len-1; i++)
            {
                for(int j=i+1; j<len; j++)
                {
                    if(list[i].isEmpty==0 && list[j].isEmpty==0)
                    {
                        if((list[i].statusFlight == list[j].statusFlight && strcmp(list[i].flyCode, list[j].flyCode)==-1)
                           || list[i].statusFlight < list[j].statusFlight)
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                    }
                }
            }
            break;
        }
    }

    return rtn;

}

/*-------------------------------------------------------------------------------------------------------------------------------*/

int printPassenger(Passenger* list, int lenght)
{
	int rtn = -1;
			printf("--------------------------------------------------------------------------------\n");
			printf("ID   |   NAME   |   LASTNAME   |   PRICE      |   FLYCODE    |   TYPEPASSENGER|\n");
			printf("--------------------------------------------------------------------------------\n");

	for(int i=0; i<lenght; i++)
	{
		if(list[i].isEmpty == 0)
		{
			printf("%2d   |%10s|  %10s  |   $%.2f | %10s   |   %2d\t      |\n", list[i].id,
																			    list[i].name,
																			    list[i].lastName,
																			    list[i].price,
																			    list[i].flyCode,
																			    list[i].typePassenger);
			printf("--------------------------------------------------------------------------------\n\n");

			rtn=0;
		}
	}
	printf("********************************************************************************\n\n");
	return rtn;
}

/*-------------------------------------------------------------------------------------------------------------------------------*/
















