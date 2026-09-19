#include <stdio.h>

int main(){

    int *ptr = NULL;        /*se inicializa apuntando a la nada de forma segura*/

    /*siempre se valida antes de intentar usarlo*/
    if(ptr == NULL) printf("el puntero esta vacio, no se puede desreferenciar aun\n");
    
}