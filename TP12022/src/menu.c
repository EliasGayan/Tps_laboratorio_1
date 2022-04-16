/*
 * menu.c
 *
 *  Created on: 11 abr. 2022
 *      Author: Elias
 */
#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"

void menu()
{
	setbuf(stdout, NULL);

		int km = 0;
		float precioAerolineas = 0;
		float precioLatam = 0;
		float debitoDescAerolineas;
		float debitoDescLatam;
		float creditoInteresAerolineas;
		float creditoInteresLatam;
		float bitcoinAerolineas;
		float bitcoinLatam;
		float precioUnitarioAerolineas;
		float precioUnitarioLatam;
		float diferenciaDePrecio;

		int opcion=0;
		int flag=0;


		do
		{
			printf("------------------------------------\n");
			printf("¡¡Binvenido a la Agencia de Vuelos!!\n");
			printf("------------------------------------\n\n");
			printf("1. Ingrese la cantidad de KILOMETROS que desee: %dKM \n", km);
			printf("2. Ingresar Precio de Vuelos: (Aerolíneas = $%.2f, Latam = $%.2f)\n", precioAerolineas, precioLatam);
			printf("3. Calcular todos los costos: \n");
			printf("4. Informar Resultados \n");
			printf("5. Carga forzada de datos \n");
			printf("6. Salir\n");

			opcion = PedirOpcionMenu("\n-Ingrese la opcion que desea: \n\n");
			LimpiarConsola();


			switch(opcion)
			{
			case 1:
					km = PedirNumeroEntero("Ingresar la cantidad de KM: \n");
					LimpiarConsola();
				break;

			case 2:
					if(km > 0)
					{
						precioAerolineas = PedirNumeroFlotante("Ingrese el precio de su vuelo en Aerolineas: ");
						precioLatam = PedirNumeroFlotante("Ingrese el precio de su vuelo en Latam: ");
					}
					else
					{
						printf("Error, Ingrese previamente un valor para los KM!!! \n");
						system("pause");
					}

					LimpiarConsola();
				break;

			case 3:
					if(precioAerolineas > 0 && precioLatam > 0)
					{
						printf("CALCULO DE COSTOS EXITOSO\n");

						debitoDescAerolineas = MostrarDescuentoDebito(precioAerolineas);
						debitoDescLatam = MostrarDescuentoDebito(precioLatam);
						creditoInteresAerolineas = MostrarInteresCredito(precioAerolineas);
						creditoInteresLatam = MostrarInteresCredito(precioLatam);
						bitcoinAerolineas = MostrarPesosABitcoin(precioAerolineas);
						bitcoinLatam = MostrarPesosABitcoin(precioLatam);
						precioUnitarioAerolineas = PrecioUnitarioKm(km, precioAerolineas);
						precioUnitarioLatam = PrecioUnitarioKm(km, precioLatam);
						diferenciaDePrecio = DiferenciarPrecio(precioLatam, precioAerolineas);


						LimpiarConsola();
						flag = 1;
					}
					else
					{
						printf("ERROR, Ingresar previamente los precios del vuelo!!!\n\n");
						system("pause");
					}

				break;

			case 4:
					if(flag==1)
					{
						printf("\nLATAM:\n"
							   "\t a) Precio con tarjeta de débito: $ %.2f\n"
							   "\t b) Precio con tarjeta de crédito: $ %.2f\n"
							   "\t c) Precio pagando con bitcoin : %.8f BTC\n"
							   "\t d) Precio unitario: $ %.2f \n\n", debitoDescLatam, creditoInteresLatam, bitcoinLatam, precioUnitarioLatam);

						printf("AEROLINEAS:\n"
							   "\t a) Precio con tarjeta de débito: $ %.2f\n"
							   "\t b) Precio con tarjeta de crédito: $ %.2f\n"
							   "\t c) Precio pagando con bitcoin : %.8f BTC\n"
							   "\t d) Precio unitario: $ %.2f\n\n"
							   "\t La diferencia de precio es de $ %.2f \n\n\n", debitoDescAerolineas, creditoInteresAerolineas, bitcoinAerolineas, precioUnitarioAerolineas, diferenciaDePrecio);
					}
					else
					{
						printf("ERROR, No se han calculado los pagos!!!\n\n");
					}

				system("pause");
				break;

			case 5:
				km=7090;
				precioAerolineas = 162965;
				precioLatam = 159339;

				debitoDescAerolineas = MostrarDescuentoDebito(precioAerolineas);
				debitoDescLatam = MostrarDescuentoDebito(precioLatam);
				creditoInteresAerolineas = MostrarInteresCredito(precioAerolineas);
				creditoInteresLatam = MostrarInteresCredito(precioLatam);
				bitcoinAerolineas = MostrarPesosABitcoin(precioAerolineas);
				bitcoinLatam = MostrarPesosABitcoin(precioLatam);
				precioUnitarioAerolineas = PrecioUnitarioKm(km, precioAerolineas);
				precioUnitarioLatam = PrecioUnitarioKm(km, precioLatam);
				diferenciaDePrecio = DiferenciarPrecio(precioLatam, precioAerolineas);

				printf("\t KMs Ingresados: %d\n\n", km);

				printf("\t LATAM:\n"
					   "\t Precio Latam: $ %.2f\n"
					   "\t a) Precio con tarjeta de débito: $ %.2f\n"
					   "\t b) Precio con tarjeta de crédito: $ %.2f\n"
					   "\t c) Precio pagando con bitcoin: %.8f BTC\n"
					   "\t d) Precio unitario: $ %.2f \n\n", precioLatam, debitoDescLatam, creditoInteresLatam, bitcoinLatam, precioUnitarioLatam);

				printf("\t AEROLINEAS:\n"
					   "\t Precio Aerolineas: $ %.2f\n"
					   "\t a) Precio con tarjeta de débito: $ %.2f\n"
					   "\t b) Precio con tarjeta de crédito: $ %.2f\n"
					   "\t c) Precio pagando con bitcoin: %.8f BTC\n"
					   "\t d) Precio unitario: $ %.2f \n\n"
					   "\t La diferencia de precio es de $ %.2f \n\n\n", precioAerolineas, debitoDescAerolineas, creditoInteresAerolineas, bitcoinAerolineas, precioUnitarioAerolineas, diferenciaDePrecio);
				system("pause");

				break;

			}

		}while(opcion != 6);

		printf("\n-------------------------------------------\n");
		printf("¡¡¡HA FINALIZADO EXITOSAMENTE EL PROGRAMA!!!\n");
		printf("-------------------------------------------\n\n");
		system("pause");
}
