#include <stdio.h>

int suma(int a , int b){

    return a + b;

}

int resta(int a , int b){

    return a - b;

}

int main(){

    int (*ptrFunc)(int a , int b);

    ptrFunc = suma;
    printf("--- LLAMANDO A SUMAR INDRIECTAMENTE ---\n");
    printf("10 + 5 = %d\n\n" , ptrFunc(10 , 5));

    ptrFunc= resta;
    printf("--- LLAMANDO A RESTAR INDRIECTAMENTE ---\n");
    printf("10 - 5 = %d\n\n" , ptrFunc(10 , 5));

    return 0;

}