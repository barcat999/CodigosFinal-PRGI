#include <stdio.h>

int main(){

    int array[5] = {5 , 2 , 9 , 1 , 3} , temp;

    printf("Array desordenado: ");
    for(int i = 0 ; i < 5 ; i++){

        printf("%d " , array[i]);

    }

    printf("\n");

    for(int i = 0 ; i < 5 - 1 ; i++){

        for(int j = 0 ; j < 5 - 1 - i ; j++){


            if(array[j] > array[j + 1]){

                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

            }
            
        } 

    }

    printf("Array ordenado: ");
    for(int i = 0; i < 5; i++){   

        printf("%d " , array[i]);

    }

    return 0;

}