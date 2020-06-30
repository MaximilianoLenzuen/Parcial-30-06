#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "piloto.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_VueloFromText(FILE* pFile , LinkedList* pArrayListaVuelos)
{
    int retorno=-1;
	int cantidad;
	char buffer1[128];
	char buffer2[128];
	char buffer3[128];
	char buffer4[128];
	char buffer5[128];
	char buffer6[128];
	char buffer7[128];
	char buffer8[128];
	eVuelos* newVuelo;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer1, buffer2, buffer3, buffer4, buffer5, buffer6, buffer7, buffer8);

	if(pFile!=NULL && pArrayListaVuelos!=NULL){

		while(!feof(pFile)){
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",buffer1, buffer2, buffer3, buffer4, buffer5, buffer6, buffer7, buffer8);
			newVuelo=vuelos_newParametros(atoi(buffer1), atoi(buffer2), atoi(buffer3), buffer4, buffer5, atoi(buffer6), atoi(buffer7), atoi(buffer8));
			if(cantidad<8){
				if(feof(pFile)){
					break;
				}

				else{
					retorno=0;
					break;
				}
			}
			if(newVuelo!=NULL){
				ll_add(pArrayListaVuelos,newVuelo);
				retorno=1;
			}



		}

	}

    return retorno;
}



int parser_PilotoFromText(FILE* pFile , LinkedList* pArrayListaPiloto)
{
    int retorno=-1;
	int cantidad;
	char buffer1[128];
	char buffer2[128];

	ePilotos* newPiloto;

	fscanf(pFile, "%[^,],%[^\n]\n", buffer1, buffer2);

	if(pFile!=NULL && pArrayListaPiloto!=NULL){

		while(!feof(pFile)){
			cantidad = fscanf(pFile,"%[^,],%[^\n]",buffer1, buffer2);
			newPiloto=piloto_newParametros(atoi(buffer1), buffer2);

                if(cantidad<2){
				if(feof(pFile)){
					break;
				}

				else{
					retorno=0;
					break;
				}
			}
			if(newPiloto!=NULL){
				ll_add(pArrayListaPiloto,newPiloto);
				retorno=1;
			}



		}

	}

    return retorno;
}



