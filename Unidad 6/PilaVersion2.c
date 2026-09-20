#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{

    int dato; 
    struct Nodo *siguiente;

} Nodo; 

int empty(Nodo *cima){

    return cima == NULL; 

}

void push(Nodo **cima , int nuevoDato){

    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo)); 

    if(nuevo != NULL){

        nuevo->dato = nuevoDato; 
        nuevo->siguiente = *cima;     //      enganchamos la flecha a lo que haya en la cima actual
        *cima = nuevo;      //      La cima oficial ahora es el nuevo Nodo

    } 
    else{ 

        printf("Error: memoria insuficiente\n");
        return; 

    }

}

void pop(Nodo **cima){

    Nodo *aux;      //      el auxiliar debe ser un puntero para poder usar 'free()' luego

    if(!empty(*cima)){

        aux = *cima; 
        *cima = (*cima)->siguiente;       //      La pila avanza al siguienteuiente elemento
        printf("Desapilado: %d\n" , aux->dato); 
        free(aux);

    } 
    else printf("Pila vacia\n"); 

}

int main(){

    Nodo *cima = NULL; 
    int opcion , nuevoDato;

    do{
        printf("\n======= MENU PILA =======\n");
        printf("1. Apilar (Push)\n");
        printf("2. Desapilar (Pop)\n");
        printf("3. Verificar si esta vacia\n");
        printf("4. Salir\n");
        printf("=========================\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                printf("Ingrese el numero a apilar: ");
                scanf("%d" , &nuevoDato);
                push(&cima , nuevoDato);
                printf("Valor %d apilado con exito\n" , nuevoDato);
                break;
                
            case 2:

                printf("\n--- Ejecutando Pop ---\n");
                pop(&cima);
                break;
                
            case 3:

                if(empty(cima)) printf("Estado: La pila esta actualmente VACIA\n");
                else printf("Estado: La pila TIENE ELEMENTOS\n");
                break;
                
            case 4:

                printf("\nCerrando programa...\n");
                
                if(!empty(cima)){

                    printf("Vaciando los elementos restantes de la memoria:\n");
                    while(!empty(cima)){

                        pop(&cima);
                    
                    }
                }

                printf("Memoria liberada. Adios!\n");
                break;
                
            default:
            
                printf("Opcion invalida. Intente de nuevo\n");

        }
        
    }while(opcion != 4);

    return 0;

}