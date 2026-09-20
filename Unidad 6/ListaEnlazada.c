#include <stdio.h>
#include <stdlib.h>

struct  Nodo{

    int dato;
    struct Nodo *siguiente;

};

struct Nodo *cabeza = NULL;

void alta(){

    struct Nodo *nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));

    if(nuevo == NULL) return;

    printf("Ingrese el nuevo numero: ");
    scanf("%d" , &nuevo->dato);

    nuevo->siguiente = cabeza;
    cabeza = nuevo;

}

void listar(){

    struct Nodo *aux = cabeza;

    if(aux == NULL) return;

    while(aux != NULL){

        printf("[%d] -> " , aux->dato);
        aux = aux->siguiente;        

    }

}

void buscar(){

    struct Nodo *aux = cabeza;
    int valorBuscar , encontrado = 0;

    printf("Numero a buscar :");
    scanf("%d" , &valorBuscar);

    while(aux != NULL){

        if(aux->dato == valorBuscar){

            printf("Valor %d encontrado en la lista!!!\n" , aux->dato);
            encontrado = 1;     
            break;

        }

        aux = aux->siguiente;

    }

    if(encontrado == 0) printf("Valor no encontrado"); 

}

void modificar(){

    struct Nodo *aux = cabeza;
    int valorBuscar , encontrado = 0;

    printf("Numero a modificar:");
    scanf("%d" , &valorBuscar);

    while(aux != valorBuscar){

        if(aux->dato == valorBuscar){

            printf("Ingrese el NUEVO numero: ");
            scanf("%d" , &aux->dato);
            encontrado = 1;
            printf("Valor modificado con exito!!!\n");
            break;

        }

        aux = aux->siguiente;

    }

    if(encontrado == 0) printf("Valor no encontrado"); 

}

void baja(){

    struct Nodo *actual = cabeza , *anterior = NULL;
    int valorBuscar , encontrado = 0;

    printf("Numero a eliminar: ");
    scanf("%d" , &valorBuscar);

    while(actual != NULL){

        if(actual->dato == valorBuscar){

            if(anterior == NULL) cabeza = actual->siguiente;
            else anterior->siguiente = actual->siguiente;

            free(actual);
            encontrado = 1;
            break;

        }

        anterior = actual;
        actual = actual->siguiente;

    }

    if(encontrado) printf("Nodo eliminado\n");
    else printf("Valor no encontrado\n");

}