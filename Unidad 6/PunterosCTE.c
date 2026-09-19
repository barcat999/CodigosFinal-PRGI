#include <stdio.h>

int main(){

    int a = 10 , * const ptr = &a;       //      el asterisco va antes del const. La direccion queda fijada a '&a'

    printf("--- ANTES DE LA MODIFICACION ---\n");
    printf("Valor en memoria: %d\n" , *ptr);
    printf("Direccion bloqueada: %p\n" , (void*)ptr);

    *ptr = 15;      //      modificamos el dato al que apunta

    printf("\n--- DESPUES DE LA MODIFICACION ---\n");
    printf("Nuevo valor en memoria: %d\n" , *ptr);
    printf("Direccion bloqueada: %p\n" , (void*)ptr);

    return 0;

}