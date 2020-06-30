#include "funciones.h"
int getInt(char mensaje[],char mensajeError[],int piso, int techo){
    int entero;
    printf("%s",mensaje);
    scanf("%d",&entero);
    while (entero < piso || entero>techo ){
        printf("%s",mensajeError);
        scanf("%d",&entero);
    }
    return entero;
}

void getString(char mensaje[],char lugar[]){
    printf("%s",mensaje);
    fflush(stdin);
    gets(lugar);
}

void menu(void)
{
     printf("\nMenu:\n");
     printf("1. Cargar los datos de los archivos.\n");
     printf("2. Imprimir vuelos\n");
     printf("3. Cantidad de pasajeros\n");
     printf("4. Cantidad de pasajeros a irlanda\n");
     printf("5. Filtrar vuelos cortos\n");
     printf("6. Listar vuelos a portugal\n");
     printf("7. Filtrar a Alex Lifeson\n");
     printf("8. Filtrar pilotos\n");
     printf("9. Imprimir pilotos\n");
     printf("10. Salir\n");
}

