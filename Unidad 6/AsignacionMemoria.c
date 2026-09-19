#include <stdio.h>
#include <stdlib.h>

int main(){

    int *p1 = (int *) malloc(10 * sizeof(int));
    int *p2 = (int *) calloc(10 , sizeof(int));

    p1 = (int *) realloc(p1 , 15 * sizeof(int));
    p2 = (int *) realloc(p2 , 15 * sizeof(int));
    
    free(p1);
    p1 = NULL;
    
    free(p2);
    p2 = NULL;
    
    printf("Memoria gestionada y liberada correctamente\n");
    
    return 0;

}