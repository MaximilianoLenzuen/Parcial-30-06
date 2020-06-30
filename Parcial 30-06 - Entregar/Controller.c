#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funciones.h"
#include "piloto.h"



/** \brief Carga los datos de los archivos a eleccion (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_Lenzuen_loadFromText(LinkedList* pArrayListEmployee,LinkedList* pArrayListPilotos)
{
    FILE* file;
    int retorno = -1;
    char recibo[50];
    printf("\n Opciones iniciales: vuelos.csv / pilotos.csv");
    getString("\nIngrese el archivo a abrir: ",recibo);
    file = recibo;
    if(file!=NULL && pArrayListEmployee!=NULL)
    {
        file = fopen(recibo,"r");
        if(strcmp("vuelos.csv",recibo)==0)
        {
            if(parser_VueloFromText(file,pArrayListEmployee)==1)
            {
                printf("\nLa carga fue realizada correctamente!\n");
                retorno = 1;
            }else
            {
                printf("\n Hubo un problemilla");
            }
        }

        if(strcmp("pilotos.csv",recibo)==0)
        {
            if(parser_PilotoFromText(file,pArrayListPilotos)==1)
            {
                printf("\nLa carga fue realizada correctamente!\n");
                retorno = 1;
            }else
            {
                printf("\n Hubo un problemilla");
            }
        }


    }
    return retorno;
}

/** \brief Relaciona estructuras piloto y vuelo.
 *
 * \param path char*
 * \param pArrayListaPilotos LinkedList*
 * \param id int
 * \return int
 *
 */
int controller_Lenzuen_relacionarId(LinkedList* listaPilotos,int id)
{
    int indice;
    int idComparison;
    int i;
    ePilotos* piloto;

    if(listaPilotos != NULL && id>0 && id <6)
    {
        for(i=0;i < ll_len(listaPilotos);i++)
        {
            piloto = ll_get(listaPilotos,i);
            pilotos_getIdPiloto(piloto,&idComparison);
            if(idComparison== id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}


/** \brief Listar vuelos
 *
 * \param pArrayListaVuelos LinkedList*
 * \return int
 *
 */

int controller_Lenzuen_ListaVuelos(LinkedList* pArrayListaVuelos,LinkedList* pArrayListaPilotos)
{
    int returnAux;
    int idVuelo;
    int idPiloto;
    int idAvion;
    int horaLlegada;
    int horaDespegue;
    int cantPasajeros;
    char fecha[50];
    char destino[50];
    char nombrePiloto[50];
    int indice;
    eVuelos* vuelo;
    ePilotos* piloto;
    if(pArrayListaVuelos != NULL)
    {
        returnAux = 1;
        for(int i=0;i<ll_len(pArrayListaVuelos);i++)
        {

            vuelo=ll_get(pArrayListaVuelos,i);
            vuelos_getIdVuelo(vuelo,&idVuelo);
            vuelos_getIdAvion(vuelo,&idAvion);
            vuelos_getIdPiloto(vuelo,&idPiloto);
            vuelos_getCantPasajeros(vuelo,&cantPasajeros);
            vuelos_getHoraDespegue(vuelo,&horaDespegue);
            vuelos_getHoraLlegada(vuelo,&horaLlegada);
            vuelos_getFecha(vuelo,fecha);
            vuelos_getDestino(vuelo,destino);
            indice = controller_Lenzuen_relacionarId(pArrayListaPilotos,idPiloto);
            piloto = ll_get(pArrayListaPilotos,indice);
            pilotos_getNombre(piloto,nombrePiloto);


            printf("\nId Vuelo: %d  id avion: %d Nombre del piloto: %s Fecha:%s Destino: %s  cantPasajeros: %d Hora despegue: %d  Hora llegada: %d",idVuelo,idAvion,nombrePiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
        }
    }


    return returnAux;
}

/** \brief Listar Pilotos
 *
 * \param pArrayListaPilotos LinkedList*
 * \return int
 *
 */

int controller_Lenzuen_ListaPilotos(LinkedList* pArrayListaPilotos)
{
    int returnAux;
    int id;
    char nombrePiloto[50];
    ePilotos* piloto;
    if(pArrayListaPilotos != NULL)
    {
        returnAux = 1;
        printf("**********LISTA DE PILOTOS***********");
        printf("\n***ID***************PILOTOS***********");
        for(int i=0;i<ll_len(pArrayListaPilotos);i++)
        {

            piloto=ll_get(pArrayListaPilotos,i);
            pilotos_getNombre(piloto,nombrePiloto);
            pilotos_getIdPiloto(piloto,&id);


            printf("\n%5d %25s ",id,nombrePiloto);
        }
    }


    return returnAux;
}


/** \brief Lista la cantidad de pasajeros de todos los vuelos.
 *
 * \param pArrayListaVuelos LinkedList*
 * \return int
 *
 */

 int controller_Lenzuen_ListaCantidadPasajeros(LinkedList* pArrayListaVuelos)
 {
     int returnAux=-1;
     void* vuelo;
     int cantidad;
     if(pArrayListaVuelos!=NULL)
     {
         cantidad = ll_count(pArrayListaVuelos,contar);
         printf("\n La cantidad de pasajeros son: %d", cantidad);
         returnAux = 1;
     }

     return returnAux;
 }

 /** \brief Lista la cantidad de pasajeros que van a irlanda.
 *
 * \param pArrayListaVuelos LinkedList*
 * \return int
 *
 */

 int controller_Lenzuen_ListaCantidadPasajerosIrlanda(LinkedList* pArrayListaVuelos)
 {
     int returnAux=-1;
     void* vuelo;
     int cantidad;
     if(pArrayListaVuelos!=NULL)
     {
         cantidad = ll_count(pArrayListaVuelos,contarIrlanda);
         printf("\n La cantidad de pasajeros a irlanda son: %d", cantidad);
         returnAux = 1;
     }

     return returnAux;
 }

/** \brief Guarda los datos de los vuelos en el archivo elegido (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_Lenzuen_saveAsText(char* path , LinkedList* pArrayListaVuelo)
{

        FILE* file;
	    eVuelos* this;
	    int i;
	    int len = -1;
	    int idVuelo;
        int idPiloto;
        int idAvion;
        int horaLlegada;
        int horaDespegue;
        int cantPasajeros;
        char fecha[50];
        char destino[50];

	    int aux = 0;

	    if(path != NULL && pArrayListaVuelo != NULL){
	        len = ll_len(pArrayListaVuelo);
	        if(len > 0){
	            file = fopen(path,"w");
	            if(file!=NULL){
	            	fprintf(file,"idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");
	                for(i=0;i<len;i++){
	                    this=(eVuelos*)ll_get(pArrayListaVuelo,i);
	                    vuelos_getIdVuelo(this,&idVuelo);
                        vuelos_getIdAvion(this,&idAvion);
                        vuelos_getIdPiloto(this,&idPiloto);
                        vuelos_getCantPasajeros(this,&cantPasajeros);
                        vuelos_getHoraDespegue(this,&horaDespegue);
                        vuelos_getHoraLlegada(this,&horaLlegada);
                        vuelos_getFecha(this,fecha);
                        vuelos_getDestino(this,destino);
	                    fprintf(file,"%d,%d,%d,%s,%s,%d,%d,%d\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
	                }
	                fclose(file);
	                if(i == len){
	                    aux = 1;
	                }
	            }
	        }
	    }
	    if(aux == 1)
	    {
	         	printf("El archivo se ha cargado correctamente\n");
	    }
	    else
	    {
	        if(len == 0)
	        {
	        	printf("La lista está vacia!!");
	        }
	        else
	        {
	        	printf("Ups!, ocurrio un error al salvar los datos");
	        }
	    }
	    return aux;

}


 /** \brief Almacena en una nueva lista los vuelos cortos (menores a 3 horas)
 *
 * \param pArrayListaVuelos LinkedList*
 * \return int
 *
 */

 int controller_Lenzuen_FiltrarVuelosCortos(LinkedList* pArrayListaVuelos)
 {

     LinkedList* listaVuelosCortos = NULL;
     int returnAux=-1;
     if(pArrayListaVuelos!=NULL)
     {
         listaVuelosCortos = ll_filter(pArrayListaVuelos,filtrarVuelosCortos);
         controller_Lenzuen_saveAsText("vuelosCortos.csv",listaVuelosCortos);

         returnAux = 1;
     }

     return returnAux;

 }

  /** \brief Almacena en una nueva lista los vuelos que van a portugal
 *
 * \param pArrayListaVuelos LinkedList*
 * \return int
 *
 */
 int controller_Lenzuen_FiltrarVuelosPortugal(LinkedList* pArrayListaVuelos)
 {

     LinkedList* listaVuelosPortugal = NULL;
     int returnAux=-1;
     if(pArrayListaVuelos!=NULL)
     {
         listaVuelosPortugal = ll_filter(pArrayListaVuelos,filtrarVuelosPortugal);
         returnAux = 1;
     }

     return returnAux;

 }

/** \brief Lista la cantidad de pasajeros que van a irlanda.
 *
 * \param pArrayListaVuelos LinkedList*
 * \return int
 *
 */
 int controller_Lenzuen_FiltrarVuelosPiloto(LinkedList* pArrayListaVuelos)
 {

     LinkedList* listaVuelosFiltradoPiloto = NULL;
     int returnAux=-1;
     if(pArrayListaVuelos!=NULL)
     {
         listaVuelosFiltradoPiloto = ll_filter(pArrayListaVuelos,filtrarVuelosPiloto);
         returnAux = 1;
     }

     return returnAux;

 }

    /** \brief Lista la cantidad de pasajeros que van a irlanda.
 *
 * \param pArrayListaVuelos LinkedList*
 * \return int
 *
 */
 int controller_Lenzuen_FiltrarPilotoPorNombre(LinkedList* pArrayListaPilotos)
 {
     char cadena[50];
     controller_Lenzuen_ListaPilotos(pArrayListaPilotos);
     getString("\n Ingrese el piloto que desea filtrar: ",cadena);
     LinkedList* listaVuelosPorFiltradoPiloto = NULL;
     int returnAux=-1;
     if(pArrayListaPilotos!=NULL)
     {
         listaVuelosPorFiltradoPiloto = ll_filter_parametro(pArrayListaPilotos,filtrarPilotoPorNombre,cadena);
         returnAux = 1;
     }
     controller_Lenzuen_ListaPilotos(listaVuelosPorFiltradoPiloto);
     return returnAux;

 }









