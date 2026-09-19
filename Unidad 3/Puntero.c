#include <stdio.h>

int main(){

    int edad = 20 , *ptr = &edad; 

    printf("Le edad original es de: %d años\n" , edad);

    *ptr = 25;

    printf("La nueva edad es de: %d años\n" , edad);

}