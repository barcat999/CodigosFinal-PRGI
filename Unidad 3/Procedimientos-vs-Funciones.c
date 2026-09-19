#include <stdio.h>

int Cubo(int numero);
void calcularDobleTriple(int numero , int *doble , int *triple);

int main(){

    int valor = 5 , resultadoFuncion , resultadoDoble , resultadoTriple;

    printf("Valor original en el main: %d\n\n" , valor);
    resultadoFuncion = Cubo(valor);     //      llamada funcion

    printf("--- 1. Prueba de FUNCION ---\n");
    printf("El cubo es: %d\n\n" , resultadoFuncion);

    calcularDobleTriple(valor , &resultadoDoble , &resultadoTriple);       //      llamada procedimiento

    printf("--- 2. Prueba de PROCEDIMIENTO ---\n");
    printf("El doble es: %d\n" , resultadoDoble);
    printf("El triple es: %d\n" , resultadoTriple);

    return 0;

}

int Cubo(int numero){
    
    return numero * numero * numero;

}
void calcularDobleTriple(int numero , int *doble , int *triple){

    *doble = numero * 2;   
    *triple = numero * 3;  

}