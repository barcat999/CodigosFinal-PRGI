#include <stdio.h>
#include <stdlib.h>

struct Nodo{

    int dato;
    struct Nodo *siguiente;

};

struct Nodo *cima = NULL;

void push(int nuevoDato){

    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));        //      crear nuevo nodo

    /*validacion de seguridad*/
    if(nuevo == NULL){ 
        
        printf("ERROR: Memoria insuficiente\n");
        return;

    }

    nuevo->dato = nuevoDato;        //      cargamos el dato dentro del nodo recien creado
    nuevo->siguiente = cima;        //      hacemos que su flecha 'siguiente' apunte a donde esta apuntando 'cima' actualmente
    cima = nuevo;       //      la variable global 'cima' se actualiza para apuntar al nodo que acabamos de poner en lo más alto

}

void pop(int *valorExtraido){

    if(cima == NULL) return;        //      si la pila esta vacia , cortamos para que no explote

    struct Nodo *aux = cima;        //      creamos un puntero temporal llamado 'aux' y lo hacemos apuntar a la cima (esto es vital porque vamos a mover 'cima' , y si no guardamos la dirección del nodo a eliminar , se convertiría en memoria inaccesible)
    *valorExtraido = aux->dato;      //      extraemos el numero guardado en el nodo y lo guardamos en la direccion de memoria que nos pasaron desde el main
    cima = aux->siguiente;      //      ahora la pila apunte al siguiente nodo (la cima pasa a ser el nodo que estaba abajo)

    free(aux);      //     destruimos el nodo viejo que quedó retenido por 'aux' (para evitar perdidas de memoria)

}

int main(){

    /*
    al inicio la pila está vacia , por eso el puntero pila no apunta a ningun nodo y se inicializa en NULL
    a medida que hago push , ese puntero pasa a apuntar al nuevo nodo que queda en la cima
    */

    int valor;

    printf("--- APILANDO ---\n");
    push(10);
    printf("Entra: 10\n");
    push(20);
    printf("Entra: 20\n");

    printf("\n--- DESAPILANDO ---\n");
    pop(&valor);
    printf("Sale: %d\n" , valor);
    pop(&valor);
    printf("Sale: %d\n" , valor);

    return 0;

}