#include <stdio.h>

int main(){

     int numeros[3] = {10 , 20 , 30} , *ptr = numeros;

    printf("1. Array clasico: numeros[1] = %d\n" , numeros[1]);
    printf("2. Puntero como Array: ptr[1] = %d\n" , ptr[1]);
    printf("3. Aritmetica en el Array: *(numeros + 1) = %d\n" , *(numeros + 1));
    printf("4. Aritmetica en el Puntero: *(ptr + 1) = %d\n" , *(ptr + 1));

    return 0;

}