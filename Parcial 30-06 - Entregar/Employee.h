#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
int idVuelo;
int idAvion;
int idPiloto;
char fecha[50];
char destino[50];
int cantPasajeros;
int horaDespegue;
int horaLlegada;
}eVuelos;

eVuelos* vuelos_new();
eVuelos* vuelos_newParametros(int idVuelo,int idAvion, int idPiloto, char* fecha,char* destino,int cantPasajeros,int horaDespegue,int horaLlegada);


int vuelos_setIdVuelo(eVuelos* this,int idVuelo);
int vuelos_setIdAvion(eVuelos* this,int idAvion);
int vuelos_setIdPiloto(eVuelos* this,int idPiloto);
int vuelos_setCantPasajeros(eVuelos* this,int CantPasajeros);
int vuelos_setHoraDespegue(eVuelos* this,int HoraDespegue);
int vuelos_setHoraLlegada(eVuelos* this,int HoraLlegada);
int vuelos_setFecha(eVuelos* this, char* Fecha);
int vuelos_setDestino(eVuelos* this, char* Destino);
int vuelos_getIdVuelo(eVuelos* this,int* idVuelo);
int vuelos_getIdAvion(eVuelos* this,int* idAvion);
int vuelos_getIdPiloto(eVuelos* this,int* idPiloto);
int vuelos_getCantPasajeros(eVuelos* this,int* CantPasajeros);
int vuelos_getHoraDespegue(eVuelos* this,int* HoraDespegue);
int vuelos_getHoraLlegada(eVuelos* this,int* HoraLlegada);
int vuelos_getFecha(eVuelos* this, char* Fecha);
int vuelos_getDestino(eVuelos* this, char* Destino);
int contar(void* vuelo);
int contarIrlanda(void* vuelo);
int filtrarVuelosCortos (void* vuelo);
int filtrarVuelosPortugal(void* vuelo);
int filtrarVuelosPiloto (void* vuelo);



#endif // employee_H_INCLUDED
