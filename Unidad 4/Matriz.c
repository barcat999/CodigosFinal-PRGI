#include <stdio.h>

#define FILA 3
#define COL 3

int main(){

    int matriz[FILA][COL];

    for(int i = 0 ; i < FILA ; i++){

        for(int j = 0 ; j < COL ; j++){

            printf("Ingrese un valor para [%d][%d]: " , i , j);
            scanf("%d" , &matriz[i][j]);

        } 

    }

    printf("---MOSTRAR MATRIZ CARGADA---\n");
    for(int i = 0 ; i < FILA ; i++){

        for(int j = 0 ; j < COL ; j++){

            printf("%d " , matriz[i][j]);

        }

        printf("\n");

    }


    printf("---MOSTRAR MATRIZ DIAGONAL PRINCIPAL---\n");
    for(int i = 0 ; i < FILA ; i++){

        printf("%d " , matriz[i][i]);

    }

    printf("\n");

    printf("---MOSTRAR MATRIZ DIAGONAL SECUNDARIA---\n");
    for(int i = 0 ; i < FILA ; i++){

        printf("%d " , matriz[i][2 - i]);

    }


    return 0;

}