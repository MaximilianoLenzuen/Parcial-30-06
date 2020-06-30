#include "piloto.h"

ePilotos* piloto_new()
{
    ePilotos* this;
    this = (ePilotos*) malloc(sizeof(ePilotos));
    return this;
}
ePilotos* piloto_newParametros(int idPiloto,char* nombre)
{
    ePilotos* punteroPiloto = piloto_new();
    if(punteroPiloto != NULL)
    {
        pilotos_setIdPiloto(punteroPiloto,idPiloto);
        pilotos_setNombre(punteroPiloto,nombre);

    }
    return punteroPiloto;
}

int pilotos_setNombre(ePilotos* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
    return retorno;
}

int pilotos_getNombre(ePilotos* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL && nombre!= NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 1;
    }
}



int pilotos_setIdPiloto(ePilotos* this,int idPilotos)
{
    int retorno = -1;
    if(this!= NULL && idPilotos > 0)
    {
        this->idPiloto = idPilotos;
        retorno = 1;
    }
    return retorno;
}
int pilotos_getIdPiloto(ePilotos* this,int* idPilotos)
{
    int retorno = -1;

    if(this!=NULL)
    {
        *idPilotos = this->idPiloto;
        retorno = 1;
    }
    return 1;
}

/*
int hardcodeoPilotos(LinkedList* pArrayListaPilotos)
{
    int returnAux = 1;
    ePilotos* pilotoUno;
    ePilotos* pilotoDos;
    ePilotos* pilotoTres;
    ePilotos* pilotoCuatro;
    ePilotos* pilotoCinco;

    pilotoUno = piloto_newParametros(1,"Alex Lifeson");
    pilotoDos = piloto_newParametros(2,"Richard Bach");
    pilotoTres = piloto_newParametros(3,"John Kerry");
    pilotoCuatro = piloto_newParametros(4,"Erwin Romell");
    pilotoCinco = piloto_newParametros(5,"Stephen Coonts");

    if(pilotoUno!=NULL && pilotoDos!=NULL&& pilotoTres!=NULL&& pilotoCuatro!=NULL&& pilotoCinco!=NULL)
    {
            ll_add(pArrayListaPilotos,pilotoUno);
            ll_add(pArrayListaPilotos,pilotoDos);
            ll_add(pArrayListaPilotos,pilotoTres);
            ll_add(pArrayListaPilotos,pilotoCuatro);
            ll_add(pArrayListaPilotos,pilotoCinco);
            returnAux=1;
    }

    return returnAux;
}
*/

int filtrarPilotoPorNombre(void* piloto,char* cadena )
{
    int retorno = 0;
    char auxNombre[50];
    if(piloto!=NULL)
    {
        pilotos_getNombre((ePilotos*)piloto,auxNombre);
        if(strcmp(auxNombre,cadena)!=0)
        {
            retorno = 1;
        }

    }
        return retorno;
}
