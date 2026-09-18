#include <stdio.h>
#include "libreria.h"

int main(){

    int a = 5 , b = 10;

    printf("La suma entre %d y %d da como resultado: %d" , a , b , suma(a , b));

    printf("La resta entre %d y %d da como resultado: %d" , a , b , resta(a , b));

    printf("El producto entre %d y %d da como resultado: %d" , a , b , producto(a , b));

    return 0;

}