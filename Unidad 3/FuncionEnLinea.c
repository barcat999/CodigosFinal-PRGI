#include <stdio.h>

/* El preprocesador hace un "buscar y reemplazar" de texto literal */
#define CALCULAR_DOBLE(x) ((x) * 2)

int main(){

    int x = 5 , resultado = CALCULAR_DOBLE(x); 
    
    printf("El doble de %d es %d\n" , x , resultado);
    
    return 0;
    
}