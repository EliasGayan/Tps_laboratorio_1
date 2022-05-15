/*
 * datos.h
 *
 *  Created on: 27 abr. 2022
 *      Author: Elias
 */

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

/*-----------------------------------------------------------------------*/

/**
 * @fn int getString(char*, char*, char*, int)
 * @brief Permite ingresar una cadena de texto.
 *
 * @param chain
 * @param message
 * @param messageMistake
 * @param max
 * @return rtn (0 OK o -1 ERROR)
 */
int getString(char* chain, char* message, char* messageMistake, int max);

/*-----------------------------------------------------------------------*/

/**
 * @fn float getFloat(char[], float*)
 * @brief Permite ungresar una cadena de texto y que el usuario ingrese un numero flotante.
 *
 * @param cadena
 * @param numero
 * @return rtn (0 OK o -1 ERROR)
 */
int getFloat(char cadena[], float *numero);

/*-----------------------------------------------------------------------*/

/**
 * @fn int getInt(char[], int*)
 * @brief Permite ungresar una cadena de texto y que el usuario ingrese un numero flotante.
 *
 * @param cadena
 * @param numero
 * @return rtn (0 OK o -1 ERROR)
 */
int getInt(char cadena[], int *numero);



#endif /* INPUT_H_ */

