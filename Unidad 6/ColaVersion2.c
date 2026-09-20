#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    
    int dato; 
    struct Nodo *siguiente; 

} Nodo; 

int empty(Nodo *frente){

    return frente == NULL;

}

void encolar(Nodo **frente , Nodo **final , int nuevoDato){

    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo)); 

    if(nuevo != NULL){

        nuevo->dato = nuevoDato; 
        nuevo->siguiente = NULL;      //      como va al fondo de la fila , siempre apunta a NULL

        if(empty(*frente)){
        
            *frente = nuevo; 
            *final = nuevo; 

        } 
        else{

            /*si ya hay fila , el ultimo engancha al nuevo y luego el final avanza*/
            (*final)->siguiente = nuevo; 
            *final = nuevo;

        }
    } 
    else printf("Error: memoria insuficiente\n");

}

void desencolar(Nodo **frente , Nodo **final){

    Nodo *aux; 

    if(!empty(*frente)){ 

        aux = *frente; 
        *frente = (*frente)->siguiente;       //      la fila avanza un lugar
                        
        if(*frente == NULL) *final = NULL;      //      acomoda el final si la fila quedo vacia

        printf("Dato eliminado: %d\n" , aux->dato);     //      imprime el dato retenido
        free(aux);      //      libera la memoria

    } 
    else printf("Cola vacia\n"); 

}

int main(){

    Nodo *frente = NULL , *final = NULL;

    encolar(&frente , &final , 10);
    encolar(&frente , &final , 20);
    
    desencolar(&frente , &final);
    desencolar(&frente , &final);
    
    return 0;

}