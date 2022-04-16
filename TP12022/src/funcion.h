/*
 * funcion.h
 *
 *  Created on: 7 abr. 2022
 *      Author: Elias
 */

#ifndef FUNCION_H_
#define FUNCION_H_

/**
 * @fn float MostrarDescuentoDebito(float)
 *@brief Calcula un descuento de un 10%.
 *
 * @param precio
 * @return descuento
 */
float MostrarDescuentoDebito(float);

/*----------------------------------------------------------*/

/**
 * @fn float PedirNumero(char[])
 * @brief Pide un numero flotante, validado.
 *
 * @param mensaje
 * @return numero
 */
float PedirNumeroFlotante(char mensaje[]);

/*----------------------------------------------------------*/

/**
 * @fn float MostrarPesosABitcoin(float)
 * @brief Convierte los pesos ARG a Bitcoin.
 *
 * @param precioPesos
 * @return precioBitcoin
 */
float MostrarPesosABitcoin(float);

/*----------------------------------------------------------*/

/**
 * @fn float MostrarInteresCredito(float)
 * @brief Aumenta un 25% el precio.
 *
 * @param precio
 * @return aumento
 */
float MostrarInteresCredito(float);

/*----------------------------------------------------------*/

/**
 * @fn float PrecioUnitarioKm(float)
 * @brief
 *
 * @param kmTotal
 * @return precio
 */
float PrecioUnitarioKm(int,float);

/*----------------------------------------------------------*/

/**
 * @fn void menu()
 * @brief Contiene todo el codigo del menu.
 *
 */
void menu();

/*----------------------------------------------------------*/

/**
 * @fn void LimpiarConsola()
 * @brief Deja un espacio en blanco en la consola luego de un enter.
 *
 */
void LimpiarConsola();

/*----------------------------------------------------------*/

/**
 * @fn int PedirNumeroEntero(char[])
 * @brief Pide un numero entero, validado.
 *
 * @param mensaje
 * @return numero
 */
int PedirNumeroEntero(char mensaje[]);

/*----------------------------------------------------------*/

/**
 * @fn float DiferenciaDePrecio(float, float)
 * @brief Calcula la diferencia de precio entre un numero y otro.
 *
 * @param primerNumero
 * @param segundoNumero
 * @return diferenciaPrecio
 */
float DiferenciarPrecio(float primerNumero, float segundoNumero);

/*----------------------------------------------------------*/

/**
 * @fn int PedirOpcionMenu(char[])
 * @brief Pide un numero entero validado.
 *
 * @param mensaje
 * @return numero
 */
int PedirOpcionMenu(char mensaje[]);


#endif /* FUNCION_H_ */





















