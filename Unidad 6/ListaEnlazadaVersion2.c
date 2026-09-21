#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{

    int dato;
    struct Nodo *sig;

} Nodo;

void alta(Nodo **cabeza){
    
    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));

    if(nuevo != NULL){

        printf("Ingrese el nuevo numero: ");
        scanf("%d" , &nuevo->dato);

        nuevo->sig = *cabeza;
        *cabeza = nuevo;
        printf("Alta exitosa!\n");

    } 
    else printf("Error: memoria insuficiente\n");
    
}

void baja(Nodo **cabeza){

    if(*cabeza == NULL){

        printf("La lista esta vacia\n");
        return;

    }

    Nodo *actual = *cabeza, *anterior = NULL;
    int valorBuscar, encontrado = 0;

    printf("Numero a eliminar: ");
    scanf("%d" , &valorBuscar);

    while(actual != NULL){

        if(actual->dato == valorBuscar){
            
            /* Caso A: el nodo a eliminar es el primero de la lista */
            if(anterior == NULL) *cabeza = actual->sig;

            /* Caso B: el nodo está en el medio o al final */
            else anterior->sig = actual->sig;

            free(actual);
            encontrado = 1;
            break;

        }

        anterior = actual;
        actual = actual->sig;

    }

    if(encontrado) printf("Nodo eliminado\n");
    else printf("Valor no encontrado\n");
    
}

void listar(Nodo *cabeza){

    Nodo *aux = cabeza;

    if(aux == NULL){
        
        printf("Lista vacia\n");
        return;

    }

    while(aux != NULL){
        
        printf("[%d] -> " , aux->dato);
        aux = aux->sig;

    }

    printf("NULL\n");

}

void buscar(Nodo *cabeza){

    Nodo *aux = cabeza;
    int valorBuscar, encontrado = 0;

    printf("Numero a buscar: ");
    scanf("%d" , &valorBuscar);

    while(aux != NULL){

        if(aux->dato == valorBuscar){

            printf("Valor %d encontrado en la lista!!!\n" , aux->dato);
            encontrado = 1;     
            break;

        }

        aux = aux->sig;

    }

    if(encontrado == 0) printf("Valor no encontrado\n"); 

}

void modificar(Nodo *cabeza){

    Nodo *aux = cabeza;
    int valorBuscar, encontrado = 0;

    printf("Numero a modificar: ");
    scanf("%d" , &valorBuscar);

    while(aux != NULL){

        if(aux->dato == valorBuscar){

            printf("Ingrese el NUEVO numero: ");
            scanf("%d" , &aux->dato);
            encontrado = 1;
            printf("Valor modificado con exito!!!\n");
            break;

        }

        aux = aux->sig;

    }

    if(encontrado == 0) printf("Valor no encontrado\n");

}

int main(){

    Nodo *cabeza = NULL; 

    printf("--- EJECUTANDO ALTAS ---\n");
    alta(&cabeza);
    alta(&cabeza);
    alta(&cabeza);

    printf("\n--- MOSTRANDO LISTA ---\n");
    listar(cabeza);

    printf("\n--- MODIFICANDO ---\n");
    modificar(cabeza);
    listar(cabeza);

    printf("\n--- ELIMINANDO ---\n");
    baja(&cabeza);
    listar(cabeza);

    return 0;

}