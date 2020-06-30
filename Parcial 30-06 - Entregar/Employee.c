#include <stdlib.h>
#include "Employee.h"
#include <string.h>

eVuelos* vuelos_new()
{
    eVuelos* this;
    this = (eVuelos*) malloc(sizeof(eVuelos));
    return this;
}
eVuelos* vuelos_newParametros(int idVuelo,int idAvion, int idPiloto, char* fecha,char* destino,int cantPasajeros,int horaDespegue,int horaLlegada)
{
    eVuelos* punteroVuelo = vuelos_new();
    if(punteroVuelo != NULL)
    {

        vuelos_setIdVuelo(punteroVuelo,idVuelo);
        vuelos_setDestino(punteroVuelo,destino);
        vuelos_setIdPiloto(punteroVuelo,idPiloto);
        vuelos_setCantPasajeros(punteroVuelo,cantPasajeros);
        vuelos_setHoraDespegue(punteroVuelo,horaDespegue);
        vuelos_setHoraLlegada(punteroVuelo,horaLlegada);
        vuelos_setIdAvion(punteroVuelo,idAvion);
        vuelos_setFecha(punteroVuelo,fecha);
    }
    return punteroVuelo;
}

//// ID VUELO
int vuelos_setIdVuelo(eVuelos* this,int idVuelo)
{
    int retorno = -1;
    if(this!= NULL && idVuelo > 0)
    {
        this->idVuelo = idVuelo;
        retorno = 1;
    }
    return retorno;
}
int vuelos_getIdVuelo(eVuelos* this,int* idVuelo)
{
    int retorno = -1;

    if(this!=NULL)
    {
        *idVuelo = this->idVuelo;
        retorno = 1;
    }
    return 1;
}
////IDAVION
int vuelos_setIdAvion(eVuelos* this,int idAvion)
{
    int retorno = -1;
    if(this!= NULL && idAvion > 0)
    {
        this->idAvion = idAvion;
        retorno = 1;
    }
    return retorno;
}

int vuelos_getIdAvion(eVuelos* this,int* idAvion)
{
    int retorno = -1;

    if(this!=NULL)
    {
        *idAvion = this->idAvion;
        retorno = 1;
    }
    return 1;
}
////ID PILOTO
int vuelos_setIdPiloto(eVuelos* this,int idPiloto)
{
    int retorno = -1;
    if(this!= NULL && idPiloto > 0)
    {
        this->idPiloto = idPiloto;
        retorno = 1;
    }
    return retorno;
}
int vuelos_getIdPiloto(eVuelos* this,int* idPiloto)
{
    int retorno = -1;

    if(this!=NULL)
    {
        *idPiloto = this->idPiloto;
        retorno = 1;
    }
    return 1;
}

//////// FECHA
int vuelos_setFecha(eVuelos* this,char* Fecha)
{
    int retorno=-1;
    if(this!=NULL && Fecha != NULL)
    {
        strcpy(this->fecha, Fecha);
        retorno = 1;
    }
    return retorno;
}

int vuelos_getFecha(eVuelos* this,char* Fecha)
{
    int retorno = -1;
    if(this!=NULL && Fecha!= NULL)
    {
        strcpy(Fecha,this->fecha);
        retorno = 1;
    }
}
////////Destino
int vuelos_setDestino(eVuelos* this,char* Destino)
{
    int retorno=-1;
    if(this!=NULL && Destino != NULL)
    {
        strcpy(this->destino, Destino);
        retorno = 1;
    }
    return retorno;
}

int vuelos_getDestino(eVuelos* this,char* Destino)
{
    int retorno = -1;
    if(this!=NULL && Destino!= NULL)
    {
        strcpy(Destino,this->destino);
        retorno = 1;
    }
}


//////CantPasajeros
int vuelos_setCantPasajeros(eVuelos* this,int CantPasajeros)
{
    int retorno = -1;
    if(this!= NULL && CantPasajeros > 0)
    {
        this->cantPasajeros = CantPasajeros;
        retorno = 1;
    }
    return retorno;
}
int vuelos_getCantPasajeros(eVuelos* this,int* CantPasajeros)
{
    int retorno = -1;

    if(this!=NULL)
    {
        *CantPasajeros = this->cantPasajeros;
        retorno = 1;
    }
    return 1;
}

/////HoraLlegada
int vuelos_setHoraLlegada(eVuelos* this,int HoraLlegada)
{
    int retorno = -1;
    if(this!= NULL && HoraLlegada > 0)
    {
        this->horaLlegada = HoraLlegada;
        retorno = 1;
    }
    return retorno;
}
int vuelos_getHoraLlegada(eVuelos* this,int* HoraLlegada)
{
    int retorno = -1;

    if(this!=NULL)
    {
        *HoraLlegada = this->horaLlegada;
        retorno = 1;
    }
    return 1;
}
/////HoraDespegue
int vuelos_setHoraDespegue(eVuelos* this,int HoraDespegue)
{
    int retorno = -1;
    if(this!= NULL && HoraDespegue > 0)
    {
        this->horaDespegue = HoraDespegue;
        retorno = 1;
    }
    return retorno;
}
int vuelos_getHoraDespegue(eVuelos* this,int* HoraDespegue)
{
    int retorno = -1;

    if(this!=NULL)
    {
        *HoraDespegue = this->horaDespegue;
        retorno = 1;
    }
    return 1;
}


//////////////////////////////////////////
int contar(void* vuelo)
{
    int retornoCantidad=0;
    if(vuelo!=NULL)
    {
        vuelos_getCantPasajeros((eVuelos*)vuelo,&retornoCantidad);
    }
    return retornoCantidad;
}

int contarIrlanda(void* vuelo)
{
    int retornoCantidad = 0;
    char auxDestino[50];
    if(vuelo!=NULL)
    {
        vuelos_getDestino((eVuelos*)vuelo,auxDestino);
        if(strcmp(auxDestino,"Irlanda")==0)
        {
            vuelos_getCantPasajeros((eVuelos*)vuelo,&retornoCantidad);
        }


    }
        return retornoCantidad;
}

int filtrarVuelosCortos (void* vuelo)
{

    int returnAux = -1;
    int despegue;
    int llegada;
        if(vuelo!=NULL)
        {

        vuelos_getHoraDespegue((eVuelos*)vuelo,&despegue);
        vuelos_getHoraLlegada((eVuelos*)vuelo,&llegada);
        if(llegada-despegue<3)
        {
            returnAux = 1;
        }


        }
    return returnAux;
}


int filtrarVuelosPortugal(void* vuelo)
{
    int retorno = 0;
    char auxDestino[50];
    if(vuelo!=NULL)
    {
        vuelos_getDestino((eVuelos*)vuelo,auxDestino);
        if(strcmp(auxDestino,"Portugal")==0)
        {
            retorno = 1;
        }

    }
        return retorno;
}

int filtrarVuelosPiloto (void* vuelo)
{

    int returnAux = -1;
    int id;
        if(vuelo!=NULL)
        {
        vuelos_getIdPiloto((eVuelos*)vuelo,&id);

        if(id!=1)
        {
            returnAux = 1;
        }


        }
    return returnAux;
}



