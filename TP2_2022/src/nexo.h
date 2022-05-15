/*
 * nexo.h
 *
 *  Created on: 12 may. 2022
 *      Author: Elias
 */

#ifndef NEXO_H_
#define NEXO_H_
#include "ArrayPassenger.h"

/**
 * @fn int Harcodeo(Passenger*, int, int*, int*)
 * @brief Carga forzada de todos los datos.
 *
 * @param list
 * @param tamList
 * @param id
 * @param contador
 * @return rtn (0 OK o -1 ERROR)
 */
int Harcodeo(Passenger* list, int tamList, int* id, int* contador);

/*-----------------------------------------------------------------------*/

/**
 * @fn int AgregarPassenger(Passenger*, int, int*)
 * @brief Agrega un pasajero al array.
 *
 * @param list
 * @param tamList
 * @param id
 * @return rtn (0 OK o -1 ERROR)
 */
int AgregarPassenger(Passenger* list, int tamList, int* id);

/*-----------------------------------------------------------------------*/

/**
 * @fn int ModificarPassenger(Passenger*, int)
 * @brief Permite poder modificar los campos de la estructura.
 *
 * @param list
 * @param tamList
 * @return rtn (0 OK o -1 ERROR)
 */
int ModificarPassenger(Passenger* list, int tamList);

/*-----------------------------------------------------------------------*/

/**
 * @fn int EliminarPassenger(Passenger*, int, int*)
 * @brief Se pide el ID que desee Eliminar, una vez obtenido el ID se da de baja.
 *
 * @param list
 * @param tamList
 * @param id
 * @return rtn (0 OK o -1 ERROR)
 */
int EliminarPassenger(Passenger* list, int tamList);

/*-----------------------------------------------------------------------*/

/**
 * @fn int SubMenuOrdenamientoByName(Passenger*, int, int)
 * @brief Menu para mostrar si desea ordenar ascendentemente o descendentemente.
 *
 * @param list
 * @param tamList
 * @param opcion
 * @return rtn (0 OK o -1 ERROR)
 */
int SubMenuOrdenamientoByName(Passenger* list, int tamList, int opcion);

/*-----------------------------------------------------------------------*/

/**
 * @fn int SubMenuOrdenamientoByCode(Passenger*, int, int)
 * @brief Menu para mostrar si desea ordenar ascendentemente o descendentemente.
 *
 * @param list
 * @param tamList
 * @param opcion
 * @return rtn (0 OK o -1 ERROR)
 */
int SubMenuOrdenamientoByCode(Passenger* list, int tamList, int opcion);

/*-----------------------------------------------------------------------*/

/**
 * @fn int SubMenuInformePromedio(Passenger*, int)
 * @brief Muestra el menu del promedio.
 *
 * @param list
 * @param tamList
 * @return rtn (0 OK o -1 ERROR)
 */
int SubMenuInformePromedio(Passenger* list, int tamList);

/*-----------------------------------------------------------------------*/

/**
 * @fn int PromedioPrecios(Passenger*, int, float*, int*, float*)
 * @brief
 *
 * @param list
 * @param tamList
 * @param promedio
 * @param contador
 * @param total
 * @return rtn (0 OK o -1 ERROR)
 */
int PromedioPrecios(Passenger* list, int tamList, float* promedio, int* contador, float* total);
#endif /* NEXO_H_ */
