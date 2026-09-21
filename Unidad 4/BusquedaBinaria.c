#include <stdio.h>

int main(){

    int array[5] = {5 , 10 , 20 , 60 , 100} , buscado , inicio = 0 , fin = 4 , medio , encontrado = 0;

    printf("Ingrese numero a buscar: ");
    scanf("%d" , &buscado);

    while(inicio <= fin){

        medio = (inicio + fin) / 2;

        if(array[medio] == buscado){

            printf("El numero %d fue encontrado en la posicion [%d]\n" , buscado , medio);
            encontrado = 1;
            break;

        }

        if(buscado < array[medio]) fin = medio - 1;
        else inicio = medio + 1;

    }

    if(!encontrado) printf("El numero %d no se encuentra en el array\n" , buscado);

    return 0;

}