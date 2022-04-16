/*
 * funcion.c
 *
 *  Created on: 7 abr. 2022
 *      Author: Elias
 */
#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"


#define BITCOIN 4606954.55


float MostrarDescuentoDebito(float precio)
{
	float descuento;

	descuento = precio * 0.10;

	precio = precio - descuento;

	return precio;
}

/*------------------------------------------------*/

float PedirNumeroFlotante(char mensaje[])
{
	float numero;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &numero);

		while(numero < 1)
		{
			printf("ERROR, Reingrese el precio de su vuelo: ");
			fflush(stdin);
			scanf("%f", &numero);
		}

	return numero;
}

/*------------------------------------------------*/

int PedirNumeroEntero(char mensaje[])
{
	int numero;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &numero);



	while(numero < 1)
	{
		printf("ERROR, Reingrese una cantidad de KM valida: ");
		fflush(stdin);
		scanf("%d", &numero);
	}

	return numero;
}

/*---------------------------------------------------*/

int PedirOpcionMenu(char mensaje[])
{
	int numero;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &numero);


	while(numero < 1 || numero > 6)
		{
			printf("\nERROR, Reingrese una opcion valida!!! \n\n");
			fflush(stdin);
			scanf("%d", &numero);
		}

	return numero;
}

/*------------------------------------------------*/

float MostrarInteresCredito(float precio)
{
	float aumento;

	aumento = precio * 1.25;

	return aumento;
}

/*------------------------------------------------*/

float MostrarPesosABitcoin(float precioPesos)
{
	float precioEnBitcoin;

	precioEnBitcoin = precioPesos / BITCOIN;

	return precioEnBitcoin;
}

/*------------------------------------------------*/

float PrecioUnitarioKm(int kmTotal, float precio)
{
	float resultadoUnitario;

	resultadoUnitario = precio / kmTotal;

	return resultadoUnitario;
}

/*------------------------------------------------*/

void LimpiarConsola()
{
	printf("\n**********************************************************************\n\n");
}

/*------------------------------------------------*/


float DiferenciarPrecio(float primerNumero, float segundoNumero)
{
	float diferenciaPrecio;

	if(primerNumero > segundoNumero)
	{
		diferenciaPrecio = primerNumero - segundoNumero;
	}
	else
	{
		diferenciaPrecio = segundoNumero - primerNumero;
	}

	return diferenciaPrecio;
}










