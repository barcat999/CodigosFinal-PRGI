#include <stdio.h>
#include <stdlib.h>

struct  Nodo{

    int dato;
    struct Nodo *siguiente;

};

struct Nodo *frente = NULL;     //      apunta al primer elemento
struct Nodo *final = NULL;      //      apunta al último

void encolar(int nuevoDato){

    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));        //      crear nuevo nodo

    nuevo->dato = nuevoDato;        //      cargamos el dato dentro del nodo recien creado
    nuevo->siguiente = NULL;        //      el nuevo nodo apunta a NULL , xq al crearlo sera el ultimo de la cola (como va al final , no hay nadie despues)

    if(frente == NULL){

    /*caso A: primer elemento , tanto el frente como el final apuntan a el*/
        frente = nuevo;
        final = nuevo;

    }
    else{

    /* caso B: ya hay gente en la fila , el nodo que actualmente es el ultimo engancha al nuevo nodo atras suyo*/
        final->siguiente = nuevo;
        final = nuevo;      //      actualizamos 'final' para que ahora apunte al nodo recien llegado

    }

}

void desencolar(int *valorExtraido){

    if(frente == NULL) return;      //      si no hay nadie en la fila , cortamos la ejecucion

    struct Nodo *aux = frente;      //      creamos un puntero temporal llamado 'aux' para no perderlo cuando movamos el 'frente'

    *valorExtraido = aux->dato;     //      extraemos el numero guardado en el nodo y lo guardamos en la direccion de memoria que nos pasaron desde el main
    frente = aux->siguiente;        //      avanza la fila -> el frente ahora es el nodo que estaba segundo

    if(frente == NULL) final = NULL;        //      si al avanzar el frente nos dimos cuenta de que ya no hay nadie , entonces el 'final' también debe reiniciarse a NULL

    free(aux);      //     destruimos el nodo viejo que quedó retenido por 'aux' (para evitar perdidas de memoria)

}

int main(){

    int valor;

    printf("--- ENCOLANDO ---\n");
    encolar(100);
    printf("Entra: 100\n");
    encolar(200);
    printf("Entra: 200\n");

    printf("\n--- DESENCOLANDO ---\n");
    desencolar(&valor);
    printf("Sale: %d\n" , valor);

    desencolar(&valor);
    printf("Sale: %d\n" , valor);

    return 0;

}