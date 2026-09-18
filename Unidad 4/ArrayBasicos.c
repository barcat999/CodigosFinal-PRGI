#include <stdio.h>

int main(){

    int array[5];

    printf("\n--- INGRESAR DATOS ARRAY ---\n");
    for(int i = 0 ; i < 5 ; i++){

        printf("Ingrese un numero: ");
        scanf("%d" , &array[i]);

    }

    printf("\n--- RECORRIDO ARRAY ---\n");
    for(int i = 0 ; i < 5 ; i++){

        printf("Array [%d] -> Valor: %d\n " , i , array[i]);

    }

    return 0;

}