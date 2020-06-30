#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
typedef struct
{
int idPiloto;
char nombre[50];
}ePilotos;

int pilotos_setIdPiloto(ePilotos* this,int idPiloto);
int pilotos_setNombre(ePilotos* this,char* nombre);
int pilotos_getIdPiloto(ePilotos* this, int* IdPiloto);
int pilotos_getNombre(ePilotos* this, char* Nombre);
ePilotos* piloto_newParametros(int idPiloto,char* nombre);
ePilotos* piloto_new();
int hardcodeoPilotos(LinkedList* pArrayListaPilotos);
int filtrarPilotoPorNombre(void* piloto,char* cadena);
