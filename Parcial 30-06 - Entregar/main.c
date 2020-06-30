#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "piloto.h"

int main()
{
    int option;

    LinkedList* listaVuelos = ll_newLinkedList();
    LinkedList* listaPilotos = ll_newLinkedList();

/*
    if(hardcodeoPilotos(listaPilotos))
    {
        printf("\nHardcodeo realizado con exito!");
    }
    else
    {
        printf("\nHubo un error al hardcodear.");
    }
*/

    do{
            menu();
            option = getInt("\nIngrese una opcion: ","Ingrese una opcion valida!!",0,10);
            switch(option)
            {

                case 1:
                    system("cls");
                    controller_Lenzuen_loadFromText(listaVuelos,listaPilotos);
                    break;
                case 2:
                    system("cls");
                    controller_Lenzuen_ListaVuelos(listaVuelos,listaPilotos);
                    break;
                case 3:
                    system("cls");
                    controller_Lenzuen_ListaCantidadPasajeros(listaVuelos);
                    break;
                case 4:
                    system("cls");
                    controller_Lenzuen_ListaCantidadPasajerosIrlanda(listaVuelos);
                    break;
                case 5:
                    system("cls");
                    controller_Lenzuen_FiltrarVuelosCortos(listaVuelos);
                    break;
                case 6:
                    system("cls");
                    if(controller_Lenzuen_FiltrarVuelosPortugal(listaVuelos)==1)
                    {
                        printf("\n Carga realizada!");
                    }
                    else
                    {
                        printf("Hubo un problemilla!");
                    }
                    break;
                case 7:
                    system("cls");
                    if(controller_Lenzuen_FiltrarVuelosPiloto(listaVuelos)==1)
                    {
                        printf("\n Filtrado realizado!");
                    }
                    else
                    {
                        printf("Hubo un problemilla!");
                    }
                    break;
                case 8:
                    system("cls");
                    if(controller_Lenzuen_FiltrarPilotoPorNombre(listaPilotos)==1)
                    {
                        printf("\n Filtrado realizado!");
                    }
                    else
                    {
                        printf("Hubo un problemilla!");
                    }
                    break;
                case 9:
                    system("cls");
                    controller_Lenzuen_ListaPilotos(listaPilotos);
                    break;

                case 10:
                    system("cls");
                    printf("\nGracias por utilizar el menu!");
                    break;


        }
    }while(option != 10);
    return 0;
}
