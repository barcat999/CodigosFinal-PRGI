#include <stdio.h>

int main(){

    int array[5] = {10 , 20 , 30 , 40 , 50} , buscado , encontrado = 0;

    printf("Ingrese numero a buscar: ");
    scanf("%d" , &buscado);

    for(int i = 0 ; i < 5 ; i++){

        if(array[i] == buscado){

            printf("El numero %d fue encontrado en la posicion [%d]\n" , buscado , i);
            encontrado = 1;
            break;

        }

    }

    if(!encontrado) printf("Valor no encontrado\n");

}